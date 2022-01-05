#pragma once
#ifndef _GAMEINTERFACES_H_
#define _GAMEINTERFACES_H_

#include "fighterstates.h"
#include "inputinterpreter.h"

namespace Player {
    class IFighter {
    public:
        virtual void HandleInput(InputAction input) = 0;
        virtual void Update() = 0;
        virtual void LoadState(int stateEnum, int frame) = 0;
        virtual void SaveState() = 0;
    protected:
        FighterState* _state;
        Fighter* _gameStateData;
    };

    class BaseFighter : IFighter {
    public:
        void HandleInput(InputAction input);
        void Update();
        void LoadState(int stateEnum, int frame);
        void SaveState();
        void MoveFighter(int dx, int dy);
    };
}

#endif