#pragma once
#ifndef _FIGHTERSTATES_H_
#define _FIGHTERSTATES_H_

#include "inputinterpreter.h"

namespace Player {
    class FighterState {
    public:
        FighterState();
        virtual FighterState* HandleInput(BaseFighter& fighter, InputAction input) {}
        virtual void Enter(BaseFighter& fighter);
        virtual void Update(BaseFighter& fighter);
        virtual void LoadState(int frame);

    protected:
        int _frame; // Which frame in this state are we in? count from 0 to x
    };

    class StandState : public FighterState {
    public:
        StandState() {
        }
        ~StandState() {
        }
        FighterState* HandleInput(BaseFighter& fighter, InputAction input) {
            if (input == Forward) {
                return new ForwardWalkState();
            }
            else if (input == Backward) {
                return new BackwardWalkState();
            }
        }
        void Enter(BaseFighter& fighter) {
        }
        void Update(BaseFighter& fighter) {
        }
        void LoadState(int frame) {
        }
    };

    class ForwardWalkState : public FighterState {
    public:
        ForwardWalkState();
        ~ForwardWalkState();
        FighterState* HandleInput(BaseFighter& fighter, InputAction input);
        void Enter(BaseFighter& fighter);
        void Update(BaseFighter& fighter);
        void LoadState(int frame);
    protected:
        int _forwardWalkSpeed;
    };

    class BackwardWalkState : public FighterState {
    public:
        BackwardWalkState();
        ~BackwardWalkState();
        FighterState* HandleInput(BaseFighter& fighter, InputAction input);
        void Enter(BaseFighter& fighter);
        void Update(BaseFighter& fighter);
        void LoadState(int frame);
    protected:
        int _backWalkSpeed;
    };
}

#endif