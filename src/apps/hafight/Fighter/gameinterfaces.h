#pragma once
#ifndef _GAMEINTERFACES_H_
#define _GAMEINTERFACES_H_

#include "fighterstates.h"
#include "../gamestate.h"

namespace Player {
    class IFighter {
    public:
        IFighter(Fighter* _gameStateData) {
            _state = new StandState();
            _gameStateData->position.x = 100;
            _gameStateData->position.y = 100;
        }
        virtual void HandleInput(InputAction input) {
            FighterState* new_state = _state->HandleInput(*this, input);
            if (new_state != nullptr) {
                delete _state;
                _state = new_state;
                _state->Enter(*this);
            }

        }
        virtual void Update() {
            _state->Update(*this);
        }
        virtual void LoadState(int stateEnum, int frame) {
        }
        virtual void SaveState() {
        }
        virtual void MoveFighter(int dx, int dy) {
            _gameStateData->position.x += dx;
            _gameStateData->position.y += dy;
        }

    protected:
        FighterState* _state;
        Fighter* _gameStateData;
    };

    class InputInterpreter {
    public:
        InputInterpreter() {
        }
        virtual InputAction ParseInput() {
        }
    };

    enum InputAction {
        Forward,
        Backward,
        Neutral,
    };
}

#endif