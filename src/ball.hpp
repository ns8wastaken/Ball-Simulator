#pragma once
#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"


struct Ball
{
    Ball(Vector2 pos) : m_currentPos(pos), m_previousPos(pos) {}
    Ball(Vector2 pos, Vector2 previousPos) : m_currentPos(pos), m_previousPos(previousPos) {}

    void draw();

    Vector2 m_currentPos;
    Vector2 m_previousPos;

    // unsigned char m_radius = std::rand() % 30 + 8; // Random value from 10 - 50
    unsigned int m_radius = 20;
};
