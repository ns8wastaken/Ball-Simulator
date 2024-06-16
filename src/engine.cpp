#include "engine.hpp"


#define GRAVITY 500

#define BALL_BOUCE 1.6f


void Engine::addBall()
{
    balls.push_back(Ball(GetMousePosition(), { 1000, 0 }));
}


void Engine::updateVel(Ball& ball, float deltaTime)
{
    ball.m_vel.y += GRAVITY * deltaTime;
}


void Engine::updatePos(Ball& ball, float deltaTime)
{
    ball.m_pos = Vector2Add(ball.m_pos, Vector2Scale(ball.m_vel, deltaTime));
}


void Engine::updateWallCollisions(Ball& ball)
{
    if (ball.m_pos.x + ball.m_radius >= GetScreenWidth()) {
        ball.m_pos.x = GetScreenWidth() - ball.m_radius;
        // ball.m_vel.x *= -0.8f;
        ball.m_vel = Vector2Add(ball.m_vel, { -ball.m_vel.x * BALL_BOUCE, 0 });
    }
    else if (ball.m_pos.x - ball.m_radius <= 0) {
        ball.m_pos.x = ball.m_radius;
        // ball.m_vel.x *= -0.8f;
        ball.m_vel = Vector2Add(ball.m_vel, { -ball.m_vel.x * BALL_BOUCE, 0 });
    }

    if (ball.m_pos.y + ball.m_radius >= GetScreenHeight()) {
        ball.m_pos.y = GetScreenHeight() - ball.m_radius;
        // ball.m_vel.y *= -0.8f;
        ball.m_vel = Vector2Add(ball.m_vel, { 0, -ball.m_vel.y * BALL_BOUCE });
    }
    else if (ball.m_pos.y - ball.m_radius <= 0) {
        ball.m_pos.y = ball.m_radius;
        // ball.m_vel.y *= -0.8f;
        ball.m_vel = Vector2Add(ball.m_vel, { 0, -ball.m_vel.y * BALL_BOUCE });
    }
}


void Engine::updateBallCollisions(Ball& ball)
{
    for (Ball& otherBall : balls) {
        if (&ball == &otherBall) continue;

        const Vector2 vec = Vector2Subtract(otherBall.m_pos, ball.m_pos);
        const float vecLength = Vector2Length(vec);

        if (vecLength < ball.m_radius + otherBall.m_radius) {
            const float delta = (ball.m_radius + otherBall.m_radius) - vecLength;
            const Vector2 n = Vector2Scale(Vector2Scale(Vector2Scale(vec, 1 / vecLength), 0.5f), delta);
            ball.m_pos = Vector2Subtract(ball.m_pos, n);
            otherBall.m_pos = Vector2Add(otherBall.m_pos, n);
        }
    }
}


void Engine::update(float deltaTime)
{
    for (Ball& ball : balls) {
        updateVel(ball, deltaTime);
        updatePos(ball, deltaTime);
        updateWallCollisions(ball);
        updateBallCollisions(ball);
    }
}


void Engine::draw()
{
    for (Ball& ball : balls)
        ball.draw();
}
