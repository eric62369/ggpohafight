#pragma once
#ifndef _BACKWARDWALKSTATE_H_
#define _BACKWARDWALKSTATE_H_

#include "fighterstate.h"

namespace Player {
    class BackwardWalkState : public FighterState {
    public:
        BackwardWalkState();
        ~BackwardWalkState();
        FighterState* HandleInput(BaseFighter& fighter, InputAction input) override;
        void Enter(BaseFighter& fighter) override;
        void Update(BaseFighter& fighter) override;
        void LoadState(int frame) override;
        int SaveState() override;
    protected:
        int _backwardWalkSpeed;
    };
}

#endif