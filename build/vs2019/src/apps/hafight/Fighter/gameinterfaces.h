#pragma once
#ifndef _GAMEINTERFACES_H_
#define _GAMEINTERFACES_H_

#include "fighterstates.h"
#include "../../src/apps/hafight/gamestate.h"

namespace Player {
    class IFighter {
    public:
        virtual ~IFighter() {
            _state = StandState;
        }
        virtual void HandleInput(Input input) {
            _state->HandleInput(*this, input);
        }
        virtual void Update() {
            _state->Update(*this);
        }
        virtual void LoadState(int frame) {
        }
        virtual void MoveFighter(int x, int y) {

        }

    protected:
        FighterState* _state;
        Fighter* _gameStateData;
    };

}

#endif