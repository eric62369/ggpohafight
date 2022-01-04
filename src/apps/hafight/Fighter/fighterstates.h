#pragma once
#ifndef _FIGHTERSTATES_H_
#define _FIGHTERSTATES_H_

#include "gameinterfaces.h"

namespace Player {
    class FighterState {
    public:
        FighterState() {
            _frame = 0;
        }
        virtual FighterState* HandleInput(IFighter& fighter, InputAction input) = 0;
        virtual void Enter(IFighter& fighter) {
            _frame = 0;
        };
        virtual void Update(IFighter& fighter) {
            _frame++;
        }
        virtual void LoadState(int frame) {
            _frame = frame;
        }

    protected:
        int _frame; // Which frame in this state are we in? count from 0 to x
    };

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