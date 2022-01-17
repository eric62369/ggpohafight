#include "fighterstate.h"
#include "backwardwalkstate.h"
#include "forwardwalkstate.h"
#include "standstate.h"

namespace Player {

    BackwardWalkState::BackwardWalkState(int* frame) : FighterState(frame) {
        _backwardWalkSpeed = 1.5656f;
        _walkSpeedSize = 15;
        for (int i = 0; i < _walkSpeedSize; i++) {
            _walkSpeed.push_back(1 + 0.266f*i);
        }
    }
    BackwardWalkState::~BackwardWalkState() {}
    FighterState* BackwardWalkState::HandleInput(BaseFighter& fighter, InputAction input) {
        fighter = fighter; // TODO: removing warning
        if (input == InputAction::Neutral) {
            return new StandState(_frame);
        }
        else if (input == InputAction::Forward) {
            return new ForwardWalkState(_frame);
        }
        else {
            return nullptr;
        }
    }
    void BackwardWalkState::Enter(BaseFighter& fighter) {
        FighterState::Enter(fighter);
    }
    void BackwardWalkState::Update(BaseFighter& fighter) {
        FighterState::Update(fighter);
        if (*_frame > 2 * _walkSpeedSize) {
            fighter._rb.SetVelX(-_walkSpeed[_walkSpeedSize - 1]);
        }
        else {
            fighter._rb.SetVelX(-_walkSpeed[(int)(*_frame / 2)]);
        }
    }
    void BackwardWalkState::LoadState(int frame) {
        FighterState::LoadState(frame);
    }
    int BackwardWalkState::SaveState() {
        return BackwardWalk;
    }
}