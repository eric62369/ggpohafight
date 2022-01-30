#include "animator.h"
#include <stdexcept>

namespace Player {
    Animator::Animator(const std::string dirPath) {
        LoadAnimations(dirPath);
    }
    Animator::~Animator() {}
    Texture2D Animator::RenderFrame(StateEnum state, int frame) {
        if (state < 0 || state >= _animations.size()) {
            throw std::invalid_argument("invalid state for animation: " + std::to_string(state));
        }
        return (*_animations[state]).RenderFrame(frame);
    }

    void Animator::LoadAnimations(const std::string dirPath) {
        Animation* animation = new Animation(dirPath + "Idle/");
        _animations.push_back(animation);

        animation = new Animation(dirPath + "Run/");
        _animations.push_back(animation);

        animation = new Animation(dirPath + "2B/");
        _animations.push_back(animation);
    }
    void Animator::UnloadAnimations() {
    }
}