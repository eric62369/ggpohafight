#include "raylibrenderer.h"
#include "raylib.h"
#include <stdio.h>
#include <string>

Camera2D _camera;
const int screenWidth = 800;
const int screenHeight = 450;

RaylibRenderer::RaylibRenderer()
{
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    _camera = { 0 };
    _camera.target = { 0.0f, 0.0f };
    _camera.offset = { screenWidth / 2.0f, screenHeight / 2.0f };
    _camera.rotation = 0.0f;
    _camera.zoom = 1.0f;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    _drawFPS = true;                // Yes, display FPS
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

        BeginMode2D(_camera);
            DrawCircleV({ (float)gs._fighters[0].position.x, (float)gs._fighters[0].position.y }, 12, MAROON);
            DrawCircleV({ (float)gs._fighters[1].position.x, (float)gs._fighters[1].position.y }, 12, BLUE);

            DrawLine((int)_camera.target.x, (int) (-screenHeight * 0.1), (int)_camera.target.x, (int)(screenHeight * 0.1), GREEN);
            DrawLine((int)(-screenWidth * 0.1), (int)_camera.target.y, (int)(screenWidth * 0.1), (int)_camera.target.y, GREEN);
        EndMode2D();
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

