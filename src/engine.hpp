#include <vector>
#include <raymath.h>
#include <rayoverloads.h>

#include "ball.hpp"


class Engine
{
private:
    struct
    {
        const Vector2 gravity{ 0.0f, 0.5f };
    } Settings;


    std::vector<Ball> balls{};
    int currentOpenIndex = 0;

    void updatePos(Ball& ball, float deltaTime);
    void updateWallCollisions(Ball& ball);
    void updateBallCollisions(Ball& ball);

public:
    void addBall();

    void update(float deltaTime);
    void draw();
};
