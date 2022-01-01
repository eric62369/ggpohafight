#include "runner.h"
#include "raylib.h"
#include "hafight.h"
#include <chrono>


using namespace std::chrono;

/*
 * runner.h --
 *
 * Abstract class used to render the game state.
 *
 */

int RunMainLoop() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

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

        // printf("%d %d %d\n", now, next, next - now - 1);

        if (now >= next) {
            HAFight_RunFrame();
            next = now + (1000 / 60);
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    HAFight_Exit();
    //--------------------------------------------------------------------------------------
    
    return 0;
}