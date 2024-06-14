#include "ball.hpp"

#define GRAVITY 0
#define BALL_RADIUS 50


void Ball::draw()
{
    DrawCircleV(m_pos, BALL_RADIUS, RAYWHITE);
}


void Ball::updateVel()
{
    m_pos = Vector2Add(m_pos, m_vel);
}


void Ball::updatePos()
{
    m_vel.y += GRAVITY;
}


void Ball::update()
{
    updateVel();
    updatePos();
}
