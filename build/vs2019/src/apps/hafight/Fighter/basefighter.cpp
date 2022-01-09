#include "basefighter.h"
#include "../FighterStates/forwardwalkstate.h"

namespace Player {
    BaseFighter::BaseFighter(Fighter* gameStateData) {
        this->_gameStateData = gameStateData;
        _state = new ForwardWalkState();
        this->_gameStateData->position.x = 100;
        this->_gameStateData->position.y = 100;
    }
    BaseFighter::~BaseFighter() {
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
        stateEnum = stateEnum + frame; // TODO: just dealing with warning for now
    }
    void BaseFighter::SaveState() {}
    void BaseFighter::MoveFighter(int dx, int dy) {
        _gameStateData->position.x += dx;
        _gameStateData->position.y += dy;
    }
}
