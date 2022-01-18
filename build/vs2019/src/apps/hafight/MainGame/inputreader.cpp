#include "stdio.h"
#include "raylib.h"
#include "inputreader.h"

/*
 * ReadInputs --
 *
 * Read the inputs for player 1 from the keyboard.  We never have to
 * worry about player 2.  GGPO will handle remapping his inputs
 * transparently.
 */
int
ReadInputs()
{
    static const struct {
        int      key;
        int      input;
    } inputtable[] = {
       { KEY_W,       INPUT_THRUST },
       { KEY_S,     INPUT_BREAK },
       { KEY_A,     INPUT_ROTATE_LEFT },
       { KEY_D,    INPUT_ROTATE_RIGHT },
       { KEY_J,         INPUT_FIRE },
       { KEY_K,         INPUT_BOMB },
    };
    static const struct {
        int      key;
        int      input;
    } padinputtable[] = {
       { 1,       INPUT_THRUST },
       { 3,     INPUT_BREAK },
       { 4,     INPUT_ROTATE_LEFT },
       { 2,    INPUT_ROTATE_RIGHT },
       { 8,         INPUT_FIRE },
       { 5,         INPUT_BOMB },
    };
    int i, inputs = 0;

    if (IsGamepadAvailable(0)) {
        for (i = 0; i < (int)(sizeof(padinputtable) / sizeof(padinputtable[0])); i++) {
            if (GetGamepadButtonPressed() == (padinputtable[i].key)) {
                inputs |= padinputtable[i].input;
            }
        }
    }
    else {
        for (i = 0; i < (int)(sizeof(inputtable) / sizeof(inputtable[0])); i++) {
            if (IsKeyDown(inputtable[i].key)) {
                inputs |= inputtable[i].input;
            }
        }
    }

    
    return inputs;
}
