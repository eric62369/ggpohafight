#include "runner.h"
#include "raylib.h"
#include "hafight.h"
#include <chrono>

#include <stdio.h>


using namespace std::chrono;

/*
 * runner.h --
 *
 * Abstract class used to render the game state.
 *
 */

int RunMainLoop(unsigned long (*getTime)(void)) {
    // Main game loop
    int next, now;
    //next = (int)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    next = getTime();
    now = next;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        //now = (int)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        now = getTime();
        HAFight_Idle(std::max(0, next - now - 1));

        if (now >= next) {
            //printf("If   %d %d %d\n", now, next, next - now - 1);
            HAFight_RunFrame();
            next = now + (1000 / 60);
        }
        else {
            //printf("Else %d %d %d\n", now, next, next - now - 1);
        }

    }
    HAFight_Exit();

    return 0;
}