#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include <string>
#include <vector>
#include "fighterstate.h"
#include "raylib.h"


namespace Player {
    class Animation {
    public:
        Animation(std::string fileName);
        ~Animation();
        Texture2D RenderFrame(int frame);
        void SetCenter(int x, int y);
        int GetCenterX();
        int GetCenterY();

    private:
        void LoadFrames(const std::string dirPath);
        void UnloadFrames();

        std::vector<int> _timeline; // frame -> textureIndex
        std::vector<Texture2D> _frames;

        int _centerX;
        int _centerY;
    };
}

#endif