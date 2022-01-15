#include "fighterstate.h"
#include "backwardwalkstate.h"
#include "forwardwalkstate.h"
#include "standstate.h"

namespace Player {

    BackwardWalkState::BackwardWalkState(int* frame) : FighterState(frame) {
        _backwardWalkSpeed = 1.5656f;
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
        fighter.MoveFighter(-_backwardWalkSpeed, 0);
    }
    void BackwardWalkState::LoadState(int frame) {
        FighterState::LoadState(frame);
    }
    int BackwardWalkState::SaveState() {
        return BackwardWalk;
    }
}