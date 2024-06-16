#include "ball.hpp"
#include <iostream>

#define GRAVITY 500
#define BALL_RADIUS 50


void Ball::draw()
{
    DrawCircleV(m_pos, BALL_RADIUS, RAYWHITE);
}


void Ball::updateVel(float deltaTime)
{
    m_vel.y += GRAVITY * deltaTime;
}


void Ball::updatePos(float deltaTime)
{
    m_pos = Vector2Add(m_pos, Vector2Scale(m_vel, deltaTime));
}


void Ball::updateCollisions()
{
    if (m_pos.x + BALL_RADIUS >= GetScreenWidth()) {
        m_vel.x *= -0.8f;
    }
    else if (m_pos.x - BALL_RADIUS <= 0) {
        m_vel.x *= -0.8f;
    }

    if (m_pos.y + BALL_RADIUS >= GetScreenHeight()) {
        m_vel.y *= -0.8f;
    }
    else if (m_pos.y - BALL_RADIUS <= 0) {
        m_vel.y *= -0.8f;
    }
}


void Ball::update(float deltaTime)
{
    updateVel(deltaTime);
    updatePos(deltaTime);
    updateCollisions();
}
