#include <raylib.h>
#include <raymath.h>

#include <vector>
#include "src/ball.cpp"
#include <iostream>


int main()
{
    InitWindow(800, 800, "Ball Simulator");

    std::vector<Ball> balls;

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            balls.push_back(Ball(GetMousePosition()));


        for (Ball& ball : balls)
            ball.update();


        BeginDrawing();
        ClearBackground(DARKGRAY);

        DrawFPS(5, 5);

        for (Ball& ball : balls)
            ball.draw();


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
