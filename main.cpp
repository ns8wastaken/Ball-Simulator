#include <raylib.h>
#include <raymath.h>
#include <rayoverloads.h>

#include "src/ball.cpp"
#include "src/engine.cpp"


int main()
{
    constexpr size_t screenWidth = 800;
    constexpr size_t screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Ball Simulator");
    // SetTargetFPS(144);

    Engine engine;

    float time = 0;

    while (!WindowShouldClose()) {
        if (IsWindowFocused()) {
            float deltaTime = GetFrameTime();

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                engine.addBall();

            // time += GetFrameTime();

            // if (time > 0.1) {
            //     time = 0.0f;
            //     engine.addBall({ 10.0f, 10.0f }, { 0.3f, 0.2f });
            // }

            engine.update(deltaTime);
        }

        BeginDrawing();
        ClearBackground(DARKGRAY);
        engine.draw();
        DrawFPS(5, 5);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
