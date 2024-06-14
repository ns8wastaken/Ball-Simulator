#pragma once
#include "raylib.h"
#include "raymath.h"


class Ball
{
private:
    void updateVel();
    void updatePos();

public:
    Vector2 m_pos{ 0, 0 };
    Vector2 m_vel{ 0, 0 };

    void update();
    void draw();

    Ball(Vector2 pos) : m_pos(pos) {}
};
