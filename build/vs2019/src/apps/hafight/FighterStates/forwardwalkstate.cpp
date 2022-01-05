#include "forwardwalkstate.h"

namespace Player {
    ForwardWalkState::ForwardWalkState() {
        _forwardWalkSpeed = 2;
    }
    ForwardWalkState::~ForwardWalkState() {}
    FighterState* ForwardWalkState::HandleInput(BaseFighter& fighter, InputAction input) {
        fighter = fighter; // TODO: removing warning
        if (input == Neutral) {
            return new ForwardWalkState();
        }
        else if (input == Backward) {
            return new ForwardWalkState();
        }
        else {
            return nullptr;
        }
    }
    void ForwardWalkState::Enter(BaseFighter& fighter) {
        //FighterState::Enter(fighter);
        fighter = fighter;
    }
    void ForwardWalkState::Update(BaseFighter& fighter) {
        //FighterState::Update(fighter);
        fighter = fighter;
        fighter.MoveFighter(_forwardWalkSpeed, 0);
    }
    void ForwardWalkState::LoadState(int frame) {
        frame = frame;
    }
}