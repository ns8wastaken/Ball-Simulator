#include "ball.hpp"


void Ball::draw()
{
    DrawCircleV(m_currentPos, m_radius, RAYWHITE);
}
