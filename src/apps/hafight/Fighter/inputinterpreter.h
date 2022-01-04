#pragma once
#ifndef _INPUTINTERPRETER_H_
#define _INPUTINTERPRETER_H_

#include "../gamestate.h"

namespace Player {
    class InputInterpreter {
    public:
        InputInterpreter() {
        }
        virtual InputAction ParseInput(int inputs) {
            if (inputs & INPUT_ROTATE_RIGHT) {
                return Forward;
            }
            else if (inputs & INPUT_ROTATE_LEFT) {
                return Backward;
            }
            else {
                return Neutral;
            }
        }
    };

    enum InputAction {
        Forward,
        Backward,
        Neutral,
    };
}

#endif