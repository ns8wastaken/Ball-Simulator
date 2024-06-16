#include <raylib.h>
#include <raymath.h>

#include "src/ball.cpp"
#include "src/engine.cpp"


int main()
{
    constexpr size_t screenWidth = 800;
    constexpr size_t screenHeight = 800;
    InitWindow(800, 800, "Ball Simulator");

    Engine engine;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            engine.addBall();
        }

        engine.update(deltaTime);

        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawFPS(5, 5);

        engine.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
