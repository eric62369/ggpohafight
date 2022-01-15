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

int RunMainLoop() {
    // Main game loop
    int next, now;
    next = (int)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    now = next;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        now = (int)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        HAFight_Idle(std::max(0, next - now - 1));

         printf("%d %d %d\n", now, next, next - now - 1);

        if (now >= next) {
            HAFight_RunFrame();
            next = now + (1000 / 60);
        }

    }
    HAFight_Exit();

    return 0;
}