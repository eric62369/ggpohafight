#pragma once
#ifndef _GAMEINTERFACES_H_
#define _GAMEINTERFACES_H_

#include "fighterstates.h"

namespace Player {
    class IFighter {
    public:
        virtual ~IFighter() {
        }
        virtual void Update() {
        }
        virtual void LoadState(int frame) {
        }
        virtual void MoveFighter(int x, int y) {
        }

    protected:
        FighterState* _state;
    };

}

#endif