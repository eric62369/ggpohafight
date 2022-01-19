#include "fighterstate.h"
#include "forwardwalkstate.h"
#include "backwardwalkstate.h"
#include "standstate.h"

namespace Player {

    ForwardWalkState::ForwardWalkState(int* frame) : FighterState(frame) {
        _forwardWalkSpeed = 5;
    }
    ForwardWalkState::~ForwardWalkState() {}
    FighterState* ForwardWalkState::HandleInput(BaseFighter& fighter, InputAction input) {
        fighter = fighter; // TODO: removing warning
        if (input == InputAction::Neutral) {
            return new StandState(_frame);
        }
        else if (input == InputAction::Backward) {
            return new BackwardWalkState(_frame);
        }
        else {
            return nullptr;
        }
    }
    void ForwardWalkState::Enter(BaseFighter& fighter) {
        FighterState::Enter(fighter);
    }
    void ForwardWalkState::Update(BaseFighter& fighter) {
        FighterState::Update(fighter);
        fighter._rb.SetVelX(_forwardWalkSpeed);
    }
    void ForwardWalkState::LoadState(int frame) {
        FighterState::LoadState(frame);
    }
    int ForwardWalkState::SaveState() {
        return ForwardWalk;
    }
}