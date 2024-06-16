#include <raylib.h>
#include <raymath.h>

#include "src/ball.cpp"
#include "src/engine.cpp"


int main()
{
    constexpr size_t screenWidth = 800;
    constexpr size_t screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Ball Simulator");

    Engine engine;

    float time = 0;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        if (IsWindowFocused()) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                engine.addBall();

            time += GetFrameTime();

            if (time > 0.5) {
                time = 0.0f;
                // engine.addBall();
            }

            engine.update(deltaTime);
        }

        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawFPS(5, 5);

        engine.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
