#include "standstate.h"
#include "forwardwalkstate.h"
#include "backwardwalkstate.h"

namespace Player {
    StandState::StandState(int* frame) : FighterState(frame) {
    }
    StandState::~StandState() {}
    FighterState* StandState::HandleInput(BaseFighter& fighter, InputAction input) {
        fighter = fighter; // TODO: removing warning
        if (input == InputAction::Forward) {
            return new ForwardWalkState(_frame);
        }
        else if (input == InputAction::Backward) {
            return new BackwardWalkState(_frame);
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
        fighter.MoveFighter(0, 0);
    }
    void StandState::LoadState(int frame) {
        FighterState::LoadState(frame);
    }
    int StandState::SaveState() {
        return Stand;
    }
}