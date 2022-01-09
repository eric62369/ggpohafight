#pragma once
#ifndef _INPUTINTERPRETER_H_
#define _INPUTINTERPRETER_H_

#include "../../../../../../src/apps/hafight/inputreader.h"

namespace Player {
    enum class InputAction {
        Forward,
        Backward,
        Neutral,
    };

    class InputInterpreter {
    public:
        InputInterpreter() {
        }
        InputAction ParseInput(int inputs) {
            if (inputs & INPUT_ROTATE_RIGHT) {
                return InputAction::Forward;
            }
            else if (inputs & INPUT_ROTATE_LEFT) {
                return InputAction::Backward;
            }
            else {
                return InputAction::Neutral;
            }
        }
    };
}

#endif