#include <vector>
#include "ball.hpp"


class Engine
{
private:
    std::vector<Ball> balls{};
    int currentOpenIndex = 0;

    void updateVel(Ball& ball, float deltaTime);
    void updatePos(Ball& ball, float deltaTime);
    void updateWallCollisions(Ball& ball);
    void updateBallCollisions(Ball& ball);

public:
    void addBall();

    void update(float deltaTime);
    void draw();
};
