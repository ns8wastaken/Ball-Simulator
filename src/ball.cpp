#include "ball.hpp"

#define GRAVITY 100
#define BALL_RADIUS 50


void Ball::draw()
{
    DrawCircleV(m_pos, BALL_RADIUS, RAYWHITE);
}


void Ball::updateVel(float deltaTime)
{
    m_vel.y += GRAVITY * deltaTime * deltaTime;
}


void Ball::updatePos()
{
    m_pos = Vector2Add(m_pos, m_vel);
}


void Ball::update(float deltaTime)
{
    updateVel(deltaTime);
    updatePos();
}
