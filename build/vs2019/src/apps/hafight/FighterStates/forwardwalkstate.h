#pragma once
#ifndef _FORWARDWALKSTATE_H_
#define _FORWARDWALKSTATE_H_

#include "fighterstate.h"

namespace Player {
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
}

#endif