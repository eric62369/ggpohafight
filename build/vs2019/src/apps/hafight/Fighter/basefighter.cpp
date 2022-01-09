#include "basefighter.h"
#include "../FighterStates/forwardwalkstate.h"
#include "../FighterStates/standstate.h"
#include "../FighterStates/backwardwalkstate.h"

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
        delete _state;
        switch (stateEnum) {
            case Stand:
                _state = new StandState();
                break;
            case ForwardWalk:
                _state = new ForwardWalkState();
                break;
            case BackwardWalk:
                _state = new BackwardWalkState();
                break;
        }
        _state->LoadState(frame);
    }
    void BaseFighter::SaveState() {}
    void BaseFighter::MoveFighter(int dx, int dy) {
        _gameStateData->position.x += dx;
        _gameStateData->position.y += dy;
    }
}
