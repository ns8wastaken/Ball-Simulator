#pragma once
#include "raylib.h"
#include "raymath.h"


class Ball
{
private:
    void updateVel(float deltaTime);
    void updatePos();

public:
    Vector2 m_pos{ 0.0f, 0.0f };
    Vector2 m_vel{ 0.0f, 0.0f };

    void update(float deltaTime);
    void draw();

    Ball() {}
    Ball(Vector2 pos) : m_pos(pos) {}
};
