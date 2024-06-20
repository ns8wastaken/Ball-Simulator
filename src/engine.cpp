#include "engine.hpp"


void Engine::addBall()
{
    balls.push_back(Ball(GetMousePosition()));
}


void Engine::updatePos(Ball& ball, float deltaTime)
{
    const Vector2 velocity = ball.m_currentPos - ball.m_previousPos;
    ball.m_previousPos = ball.m_currentPos;
    ball.m_currentPos += velocity + (Settings.gravity - velocity) * (deltaTime * deltaTime);
}


void Engine::updateWallCollisions(Ball& ball)
{
    if (ball.m_currentPos.x + ball.m_radius >= GetScreenWidth()) {
        ball.m_currentPos.x = GetScreenWidth() - ball.m_radius;
    }
    else if (ball.m_currentPos.x - ball.m_radius <= 0) {
        ball.m_currentPos.x = ball.m_radius;
    }

    if (ball.m_currentPos.y + ball.m_radius >= GetScreenHeight()) {
        ball.m_currentPos.y = GetScreenHeight() - ball.m_radius;
    }
    else if (ball.m_currentPos.y - ball.m_radius <= 0) {
        ball.m_currentPos.y = ball.m_radius;
    }
}


void Engine::updateBallCollisions(Ball& ball)
{
    for (Ball& otherBall : balls) {
        if (&ball == &otherBall)
            continue;

        const Vector2 vec = otherBall.m_currentPos - ball.m_currentPos;
        const float vecLength = Vector2Length(vec);

        if (vecLength < ball.m_radius + otherBall.m_radius) {
            const float delta = (ball.m_radius + otherBall.m_radius) - vecLength;
            const Vector2 offset = (vec / vecLength) * delta * 0.5f;
            ball.m_currentPos -= offset;
            otherBall.m_currentPos += offset;
        }
    }
}


void Engine::update(float deltaTime)
{
    for (Ball& ball : balls) {
        updatePos(ball, deltaTime);
        updateBallCollisions(ball);
        updateWallCollisions(ball);
    }
}


void Engine::draw()
{
    for (Ball& ball : balls)
        ball.draw();
}
