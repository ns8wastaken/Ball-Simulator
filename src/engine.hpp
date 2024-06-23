#include <vector>
#include <raymath.h>
#include <rayoverloads.h>

#include "ball.hpp"


class Engine
{
public:
    void addBall();
    void addBall(Vector2 pos, Vector2 velocity);

    void update(float deltaTime);
    void draw();

private:
    struct
    {
        const Vector2 gravity{ 0.0f, 1000.0f };
    } Settings;


    std::vector<Ball> balls{};
    int currentOpenIndex = 0;

    void updatePos(Ball& ball, float deltaTime);
    void updateWallCollisions(Ball& ball);
    void updateBallCollisions(Ball& ball);
};
