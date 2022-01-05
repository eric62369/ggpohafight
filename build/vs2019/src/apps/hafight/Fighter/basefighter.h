#pragma once
#ifndef _BASEFIGHTER_H_
#define _BASEFIGHTER_H_

#include "inputinterpreter.h"
#include "../FighterStates/fighterstate.h"
#include "../../../../../../src/apps/hafight/gamestate.h"

namespace Player {
    class FighterState;

    class BaseFighter {
    public:
        BaseFighter(Fighter* _gameStateData);
        ~BaseFighter();
        void HandleInput(InputAction input);
        void Update();
        void LoadState(int stateEnum, int frame);
        void SaveState();
        void MoveFighter(int dx, int dy);

    private:
        Fighter* _gameStateData;
        FighterState* _state;
    };
}

#endif