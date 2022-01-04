#pragma once
#ifndef _FIGHTERSTATES_H_
#define _FIGHTERSTATES_H_

#include "gameinterfaces.h"

namespace Player {
    class FighterState {
    public:
        virtual ~FighterState() {
            _frame = 0;
        }
        virtual void HandleInput(IFighter& fighter, Input input) = 0;
        virtual void Update(IFighter& fighter) {
            _frame++;
        }
        virtual void LoadState(int frame) {
            _frame = frame;
        }

    protected:
        int _frame; // Which frame in this state are we in? count from 0 to x
    };

    class StandState : FighterState {
    public:
        virtual void Update(IFighter& fighter) {
        }
    };

    class ForwardWalkState : FighterState {
    public:
        virtual ~ForwardWalkState() {
            _forwardWalkSpeed = 2;
        }
        virtual void Update(IFighter& fighter) {
            fighter.MoveFighter(_forwardWalkSpeed, 0);
        }
    protected:
        int _forwardWalkSpeed;
    };

    class BackwardWalkState : FighterState {
    public:
        virtual ~BackwardWalkState() {
            _backWalkSpeed = -1;
        }
        virtual void Update(IFighter& fighter) {
            fighter.MoveFighter(_backWalkSpeed, 0);
        }
    protected:
        int _backWalkSpeed;
    };
}

#endif