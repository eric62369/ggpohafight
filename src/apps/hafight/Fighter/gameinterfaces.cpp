#include "gameinterfaces.h"
#include "fighterstates.h"
#include "inputinterpreter.h"

namespace Player {
    BaseFighter::BaseFighter(Fighter* _gameStateData) {
        _state = new StandState();
        _gameStateData->position.x = 100;
        _gameStateData->position.y = 100;
    }
    void BaseFighter::HandleInput(InputAction input) {
        FighterState* new_state = _state->HandleInput(*this, input);
        if (new_state != nullptr) {
            delete _state;
            _state = new_state;
            _state->Enter(*this);
        }

    }
    void BaseFighter::Update() {
        _state->Update(*this);
    }
    void BaseFighter::LoadState(int stateEnum, int frame) {
    }
    void BaseFighter::SaveState() {
    }
    void BaseFighter::MoveFighter(int dx, int dy) {
        _gameStateData->position.x += dx;
        _gameStateData->position.y += dy;
    }
}