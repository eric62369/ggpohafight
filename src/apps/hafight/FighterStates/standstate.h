#pragma once
#ifndef _STANDSTATE_H_
#define _STANDSTATE_H_

#include "fighterstate.h"

namespace Player {
    class StandState : public FighterState {
    public:
        StandState(int* frame);
        ~StandState();
        FighterState* HandleInput(BaseFighter& fighter, InputAction input) override;
        void Enter(BaseFighter& fighter) override;
        void Update(BaseFighter& fighter) override;
        void LoadState(int frame) override;
        int SaveState() override;
    };
}

#endif