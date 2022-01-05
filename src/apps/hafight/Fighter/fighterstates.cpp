#include "fighterstates.h"
#include "gameinterfaces.h"
#include "inputinterpreter.h"

namespace Player {
    FighterState::FighterState() {
        _frame = 0;
    }
    FighterState* FighterState::HandleInput(BaseFighter& fighter, InputAction input) {
    }
    void FighterState::Enter(BaseFighter& fighter) {
        _frame = 0;
    };
    void FighterState::Update(BaseFighter& fighter) {
        _frame += 1;
    }
    void FighterState::LoadState(int frame) {
        _frame = frame;
    }

    StandState::StandState() :
        FighterState() {
    }
    StandState::~StandState(){
    }
    FighterState* StandState::HandleInput(BaseFighter& fighter, InputAction input) {
        if (input == Forward) {
            return new ForwardWalkState();
        }
        else if (input == Backward) {
            return new BackwardWalkState();
        }
    }
    void StandState::Enter(BaseFighter& fighter) {
        FighterState::Enter(fighter);
    }
    void StandState::Update(BaseFighter& fighter) {
        FighterState::Update(fighter);
    }
    void StandState::LoadState(int frame) {
    }

    ForwardWalkState::ForwardWalkState() :
        FighterState() {
        _forwardWalkSpeed = 2;
    }
    ForwardWalkState::~ForwardWalkState(){
    }
    FighterState* ForwardWalkState::HandleInput(BaseFighter& fighter, InputAction input) {
        if (input == Neutral) {
            return new StandState();
        }
        else if (input == Backward) {
            return new BackwardWalkState();
        }
    }
    void ForwardWalkState::Enter(BaseFighter& fighter) {
        FighterState::Enter(fighter);
    }
    void ForwardWalkState::Update(BaseFighter& fighter) {
        FighterState::Update(fighter);
        fighter.MoveFighter(_forwardWalkSpeed, 0);
    }
    void ForwardWalkState::LoadState(int frame){
    }

    BackwardWalkState::BackwardWalkState() :
        FighterState() {
        _backWalkSpeed = -1;
    }
    BackwardWalkState::~BackwardWalkState(){
    }
    FighterState* BackwardWalkState::HandleInput(BaseFighter& fighter, InputAction input) {
        if (input == Neutral) {
            return new StandState();
        }
        else if (input == Forward) {
            return new ForwardWalkState();
        }
    }
    void BackwardWalkState::Enter(BaseFighter& fighter) {
        FighterState::Enter(fighter);
    }
    void BackwardWalkState::Update(BaseFighter& fighter) {
        FighterState::Update(fighter);
        fighter.MoveFighter(_backWalkSpeed, 0);
    }
    void BackwardWalkState::LoadState(int frame) {
    }
}
