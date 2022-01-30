#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <string>
#include <vector>
#include "../FighterStates/fighterstate.h"
#include "raylib.h"


namespace Player {
    class Animation {
    public:
        Animation(std::string fileName);
        ~Animation();
        Texture2D RenderFrame(int frame);
    private:
        void LoadFrames(const std::string dirPath);
        void UnloadFrames();

        StateEnum _state;
        std::vector<int> _timeline; // frame -> textureIndex
        std::vector<Texture2D> _frames;
    };
}

#endif