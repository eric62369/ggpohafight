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
    int Animator::GetCenterX(StateEnum state) {
        return (*_animations[state]).GetCenterX();
    }
    int Animator::GetCenterY(StateEnum state) {
        return (*_animations[state]).GetCenterY();
    }

    void Animator::LoadAnimations(const std::string dirPath) {
        Animation* animation = new Animation(dirPath + "Idle/");
        animation->SetCenter(231, 846);
        _animations.push_back(animation);

        animation = new Animation(dirPath + "2B/");
        animation->SetCenter(606, 430);
        _animations.push_back(animation);

        animation = new Animation(dirPath + "Run/");
        animation->SetCenter(356, 680);
        _animations.push_back(animation);
    }
    void Animator::UnloadAnimations() {
        for (Animation* anim : _animations) {
            delete anim;
        }
    }
}