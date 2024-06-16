#pragma once
#include "raylib.h"
#include "raymath.h"


struct Ball
{
    Vector2 m_pos{ 0.0f, 0.0f };
    Vector2 m_vel{ 0.0f, 0.0f };
    unsigned char m_radius = 20;

    void draw();

    Ball(Vector2 pos) : m_pos(pos) {}
    Ball(Vector2 pos, Vector2 vel) : m_pos(pos), m_vel(vel) {}
};
