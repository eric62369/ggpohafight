#include "standstate.h"
#include "forwardwalkstate.h"
#include "backwardwalkstate.h"

namespace Player {
    StandState::StandState() : FighterState() {
    }
    StandState::~StandState() {}
    FighterState* StandState::HandleInput(BaseFighter& fighter, InputAction input) {
        fighter = fighter; // TODO: removing warning
        if (input == InputAction::Forward) {
            return new ForwardWalkState();
        }
        else if (input == InputAction::Backward) {
            return new BackwardWalkState();
        }
        else {
            return nullptr;
        }
    }
    void StandState::Enter(BaseFighter& fighter) {
        FighterState::Enter(fighter);
    }
    void StandState::Update(BaseFighter& fighter) {
        FighterState::Update(fighter);
    }
    void StandState::LoadState(int frame) {
        FighterState::LoadState(frame);
    }
    int StandState::SaveState() {
        return Stand;
    }
}