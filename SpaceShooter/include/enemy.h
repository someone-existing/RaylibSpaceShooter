#pragma once
#include "public.h"

class Enemy{
public:
    int width, height, x, y, speed;
    bool active;
    Enemy();
    void MoveandDraw();
    void Die();
};