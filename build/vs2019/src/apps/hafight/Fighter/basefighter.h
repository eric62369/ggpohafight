#pragma once
#ifndef _BASEFIGHTER_H_
#define _BASEFIGHTER_H_

#include "inputinterpreter.h"
#include "../FighterStates/fighterstate.h"
#include "../MainGame/gamestate.h"
#include "../Physics/rigidbody.h"

namespace Player {
    class FighterState;

    class BaseFighter {
    public:
        BaseFighter(Fighter* _gameStateData);
        ~BaseFighter();
        void HandleInput(InputAction input);
        void Update();
        void LoadState(int stateEnum, int frame);

        Physics::Rigidbody _rb;

    private:
        void SaveState();

        Fighter* _gameStateData;
        FighterState* _state;
    };
}

#endif