#include "raylibrenderer.h"
#include "raylib.h"
#include <stdio.h>
#include <string>

RaylibRenderer::RaylibRenderer()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    _drawFPS = true;
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
    if (_drawFPS) {
        std::string tmp = std::to_string(GetFPS());
        char const* fps_char = tmp.c_str();
        DrawText(fps_char, 120, 10, 10, DARKGRAY);
    }
    
    std::string tmp1 = std::to_string(ngs.periodic.framenumber);
    char const* framecount_char = tmp1.c_str();
    std::string tmp2 = std::to_string(ngs.periodic.checksum);
    char const* checksum_char = tmp2.c_str();
    DrawText(framecount_char, 10, 20, 8, DARKGRAY);
    DrawText(checksum_char, 10, 30, 8, DARKGRAY);

    DrawCircleV({ (float)gs._fighters[0].position.x, (float)gs._fighters[0].position.y }, 12, MAROON);
    DrawCircleV({ (float)gs._fighters[1].position.x, (float)gs._fighters[1].position.y }, 12, BLUE);

    EndDrawing();
}

void
RaylibRenderer::SetStatusText(const char* text)
{
    strncpy_s(_status, sizeof(_status), text, sizeof(text));
}

void
RaylibRenderer::ToggleFPS()
{
    _drawFPS = !_drawFPS;
}

