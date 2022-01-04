#pragma once
#ifndef _GAMEINTERFACES_H_
#define _GAMEINTERFACES_H_

#include "fighterstates.h"
#include "../gamestate.h"

namespace Player {
    class IFighter {
    public:
        virtual ~IFighter() {
            _state = new StandState();
        }
        virtual void HandleInput(InputAction input) {
            _state->HandleInput(*this, input);
        }
        virtual void Update() {
            _state->Update(*this);
        }
        virtual void LoadState(int stateEnum, int frame) {
        }
        virtual void SaveState() {
        }
        virtual void MoveFighter(int x, int y) {

        }

    protected:
        FighterState* _state;
        Fighter* _gameStateData;
    };

    class InputInterpreter {
    public:
        virtual ~InputInterpreter() {
        }
        virtual InputAction ParseInput() {
        }
    };

    class InputAction {
    public:
        
        virtual ~InputAction() {
        }
    };
}

#endif