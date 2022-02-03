#include "basefighter.h"
#include "rigidbody.h"
#include "forwardwalkstate.h"
#include "standstate.h"
#include "backwardwalkstate.h"

namespace Player {
    BaseFighter::BaseFighter(Fighter* gameStateData) :
        _rb (&gameStateData->position.x,
            &gameStateData->position.y,
            &gameStateData->velocity.dx,
            &gameStateData->velocity.dy) {
        this->_gameStateData = gameStateData;
        _state = new ForwardWalkState(&(_gameStateData->frame));
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
        _rb.Update();
        SaveState();
    }
    void BaseFighter::LoadState(int stateEnum, int frame) {
        delete _state;
        switch (stateEnum) {
            case Stand:
                _state = new StandState(&(_gameStateData->frame));
                break;
            case ForwardWalk:
                _state = new ForwardWalkState(&(_gameStateData->frame));
                break;
            case BackwardWalk:
                _state = new BackwardWalkState(&(_gameStateData->frame));
                break;
        }
        _state->LoadState(frame);
    }
    void BaseFighter::SaveState() {
        _gameStateData->state = _state->SaveState();
        _gameStateData->frame = _state->GetFrame();
    }
}
