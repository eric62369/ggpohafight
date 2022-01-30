#pragma once
#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_

#include <string>
#include <vector>
#include "../FighterStates/fighterstate.h"
#include "animation.h"
#include "raylib.h"

namespace Player {
    class Animator {
    public:
        Animator(const std::string dirPath);
        ~Animator();
        Texture2D RenderFrame(StateEnum state, int frame);
    private:
        void LoadAnimations(const std::string dirPath);
        void UnloadAnimations();
        std::vector<Animation*> _animations;
    };
}

#endif