#include "raylibrenderer.h"
#include "raylib.h"
#include <string.h>

RaylibRenderer::RaylibRenderer()
{
   //
}

RaylibRenderer::~RaylibRenderer()
{
   //
}

void
RaylibRenderer::Draw(GameState &gs, NonGameState &ngs) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText(_status, 10, 10, 10, DARKGRAY);
    DrawText(ngs.periodic.framenumber + " " + ngs.periodic.checksum, 10, 10, 10, DARKGRAY);

    DrawCircleV({ (float) gs._fighters[0].position.x, (float) gs._fighters[0].position.y }, 12, MAROON);
    DrawCircleV({ (float) gs._fighters[1].position.x, (float) gs._fighters[1].position.y }, 12, BLUE);

    EndDrawing();
}

void
RaylibRenderer::SetStatusText(const char *text)
{
   strncpy_s(_status, sizeof(_status), text, sizeof(text));
}
