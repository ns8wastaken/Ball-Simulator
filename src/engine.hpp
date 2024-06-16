#include <vector>
#include "ball.hpp"


class Engine
{
private:
    std::vector<Ball> balls{};
    int currentOpenIndex = 0;

public:
    void addBall();
    void update(float deltaTime);
    void draw();
};
