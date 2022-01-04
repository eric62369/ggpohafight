#pragma once
#ifndef _FIGHTERSTATES_H_
#define _FIGHTERSTATES_H_

#include "fighterstates.h"
#include "inputinterpreter.h"

namespace Player {

    class StandState : public FighterState {
    public:
        FighterState* HandleInput(IFighter& fighter, InputAction input) {
            if (input == Forward) {
                return new ForwardWalkState();
            }
            else if (input == Backward) {
                return new BackwardWalkState();
            }
        }
        void Enter(IFighter& fighter) {
            FighterState::Enter(fighter);
        };
        void Update(IFighter& fighter) {
            FighterState::Update(fighter);
        }
    };

    class ForwardWalkState : public FighterState {
    public:
        ForwardWalkState() {
            _forwardWalkSpeed = 2;
        }
        FighterState* HandleInput(IFighter& fighter, InputAction input) {
            if (input == Neutral) {
                return new StandState();
            }
            else if (input == Backward) {
                return new BackwardWalkState();
            }
        }
        void Enter(IFighter& fighter) {
            FighterState::Enter(fighter);
        };
        void Update(IFighter& fighter) {
            FighterState::Update(fighter);
            fighter.MoveFighter(_forwardWalkSpeed, 0);
        }
    protected:
        int _forwardWalkSpeed;
    };

    class BackwardWalkState : public FighterState {
    public:
        virtual ~BackwardWalkState() {
            _backWalkSpeed = -1;
        }
        FighterState* HandleInput(IFighter& fighter, InputAction input) {
            if (input == Neutral) {
                return new StandState();
            }
            else if (input == Forward) {
                return new ForwardWalkState();
            }
        }
        void Enter(IFighter& fighter) {
            FighterState::Enter(fighter);
        };
        void Update(IFighter& fighter) {
            FighterState::Update(fighter);
            fighter.MoveFighter(_backWalkSpeed, 0);
        }
    protected:
        int _backWalkSpeed;
    };
}

#endif