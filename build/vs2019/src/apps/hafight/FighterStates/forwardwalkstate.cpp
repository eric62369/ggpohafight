#include "fighterstate.h"
#include "forwardwalkstate.h"
#include "backwardwalkstate.h"
#include "standstate.h"

namespace Player {

    ForwardWalkState::ForwardWalkState() : FighterState() {
        _forwardWalkSpeed = 2;
    }
    ForwardWalkState::~ForwardWalkState() {}
    FighterState* ForwardWalkState::HandleInput(BaseFighter& fighter, InputAction input) {
        fighter = fighter; // TODO: removing warning
        if (input == InputAction::Neutral) {
            return new StandState();
        }
        else if (input == InputAction::Backward) {
            return new BackwardWalkState();
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
        fighter.MoveFighter(_forwardWalkSpeed, 0);
    }
    void ForwardWalkState::LoadState(int frame) {
        FighterState::LoadState(frame);
    }
}