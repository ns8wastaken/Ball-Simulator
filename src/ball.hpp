#pragma once
#include "raylib.h"
#include "raymath.h"


struct Ball
{
    Vector2 m_currentPos;
    Vector2 m_previousPos;
    unsigned char m_radius = 50;

    void draw();

    Ball(Vector2 pos) : m_currentPos(pos), m_previousPos(pos) {}
    Ball(Vector2 pos, Vector2 previousPos) : m_currentPos(pos), m_previousPos(previousPos) {}
};
