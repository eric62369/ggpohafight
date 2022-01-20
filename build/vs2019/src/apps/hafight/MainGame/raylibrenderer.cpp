#include "raylibrenderer.h"
#include "raylib.h"
#include <stdio.h>
#include <string>
//
//#include <direct.h>
//#include <iostream>
//#include <filesystem>

Camera2D _camera;
Texture2D _curTexture;
const int screenWidth = 800;
const int screenHeight = 450;
//
//using std::cout; using std::cin;
//using std::endl; using std::string;


RaylibRenderer::RaylibRenderer(NonGameState& ngs) :
    _status("None")
{
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    if (ngs.player_num == 0) {
        SetWindowPosition(0, 20);
    }
    else {
        SetWindowPosition(0, 500);
    }


    //char tmp[256];
    //_getcwd(tmp, 256);
    //cout << "Current working directory: " << tmp << endl;

    LoadTextures();

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
RaylibRenderer::LoadTextures() {
    _curTexture = LoadTexture("C:/Users/Eric Yoon/Documents/Git/ggpoHaFight/build/vs2019/src/apps/hafight/Assets/Sprites/SubaruExport/Idle/frame0000.png");
}

void
RaylibRenderer::DrawDebug(GameState& gs, NonGameState& ngs) {
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

    std::string tmp3 = std::to_string(gs._fighters[0].velocity.dx);
    char const* v1 = tmp3.c_str();
    DrawText(v1, 10, 40, 8, DARKGRAY);
    std::string tmp4 = std::to_string(gs._fighters[1].velocity.dx);
    char const* v2 = tmp4.c_str();
    DrawText(v2, 10, 50, 8, DARKGRAY);

    std::string tmp5 = std::to_string(ngs.player_num);
    char const* v3 = tmp5.c_str();
    DrawText(v3, 160, 10, 8, DARKGRAY);
}

void
RaylibRenderer::DrawGameState(GameState& gs) {
    DrawFighter(gs._fighters[0], 0);
    DrawFighter(gs._fighters[1], 1);

    DrawLine((int)_camera.target.x, (int)(-screenHeight * 0.1), (int)_camera.target.x, (int)(screenHeight * 0.1), GREEN);
    DrawLine((int)(-screenWidth * 0.1), (int)_camera.target.y, (int)(screenWidth * 0.1), (int)_camera.target.y, GREEN);
}

void
RaylibRenderer::DrawFighter(Fighter& ft, int num) {
    Color color = { 255, 100, 100, 255 };
    if (num == 0) {
        if (ft.state == 1) {
            color.r = (ft.frame * 10) % 255;
        }
    }
    else {
        color = { 100, 100, 255, 255 };
    }
    
    DrawCircleV({ (float)ft.position.x, (float)ft.position.y }, 120, color);
    DrawTexture(_curTexture, screenWidth / 2 - _curTexture.width / 2, screenHeight / 2 - _curTexture.height / 2, WHITE);
}

void
RaylibRenderer::Draw(GameState& gs, NonGameState& ngs) {
    BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawDebug(gs, ngs);

        BeginMode2D(_camera);
            DrawGameState(gs);
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

