#include "raylib.h"

int main()
{
    InitWindow(800, 800, "Raylib Default Window");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("It works!", 20, 20, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
