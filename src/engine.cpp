#include "engine.hpp"


void Engine::addBall()
{
    balls.push_back(Ball(GetMousePosition()));
}


void Engine::update(float deltaTime)
{
    for (Ball& ball : balls)
        ball.update(deltaTime);
}


void Engine::draw()
{
    for (Ball& ball : balls)
        ball.draw();
}
