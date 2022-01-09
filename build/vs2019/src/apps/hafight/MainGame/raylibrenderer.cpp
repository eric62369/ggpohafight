#include "raylibrenderer.h"
#include "raylib.h"
#include <string.h>
#include <stdio.h>

RaylibRenderer::RaylibRenderer()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
}

RaylibRenderer::~RaylibRenderer()
{
    CloseWindow();
}

void
RaylibRenderer::Draw(GameState& gs, NonGameState& ngs) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText(_status, 10, 10, 10, DARKGRAY);

    printf("%d %d\n", ngs.periodic.framenumber, ngs.periodic.checksum);
    printf("%f\n", gs._fighters[0].position.x);

    DrawCircleV({ (float)gs._fighters[0].position.x, (float)gs._fighters[0].position.y }, 12, MAROON);
    DrawCircleV({ (float)gs._fighters[1].position.x, (float)gs._fighters[1].position.y }, 12, BLUE);

    EndDrawing();
}

void
RaylibRenderer::SetStatusText(const char* text)
{
    strncpy_s(_status, sizeof(_status), text, sizeof(text));
}
