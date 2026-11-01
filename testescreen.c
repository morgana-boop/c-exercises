#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Meu jogo em C");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawCircle(400, 300, 400, PURPLE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}