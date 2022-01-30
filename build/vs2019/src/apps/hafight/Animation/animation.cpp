#include "animation.h"
#include <stdexcept>

namespace Player {
    Animation::Animation(std::string fileName) {
        LoadFrames(fileName);
    }
    Animation::~Animation() {
        UnloadFrames();
    }
    Texture2D Animation::RenderFrame(int frame) {
        if (frame < 0) {
            throw std::invalid_argument("invalid frame for animation: " + frame);
        }
        return _frames[_timeline[frame % _timeline.size()]];
    }

    // TODO: Excessive jank! Will be a good idea to design a better system later
    void Animation::LoadFrames(const std::string dirPath) {
        int count = 0;
        // TODO: Need to free this later?
        char** filenames = GetDirectoryFiles(dirPath.c_str(), &count);

        Texture2D curTexture;
        int prevTextureIndex = -1;
        int prevFrameNum = 0;
        for (int i = 0; i < count; i++) {
            char* filename = filenames[i];
            if (GetFileExtension(filename) != nullptr && 
                    strcmp(GetFileExtension(filename), ".png") == 0) {
                std::string combinedFileName = dirPath + filename;

                // TODO: Figure out how to load properly / animate properly
                if (i != count) {
                    curTexture = LoadTexture(combinedFileName.c_str());
                    _frames.push_back(curTexture);
                }
                const char* onlyFileName = GetFileNameWithoutExt(filename);

                int frameNum = atoi(onlyFileName);

                for (int j = prevFrameNum; j < frameNum; j++) {
                    _timeline.push_back(prevTextureIndex);
                }

                prevTextureIndex++;
                prevFrameNum = frameNum;
            }
        }
        // The last frame is the end of the animation
        // only used for timing
        //_timeline.push_back(prevTextureIndex);
    }

    void Animation::UnloadFrames() {
        LoadTexture("C:/Users/Eric Yoon/Documents/Git/ggpoHaFight/build/vs2019/src/apps/hafight/Assets/Sprites/SubaruExport/Idle/frame0000.png");
    }
}