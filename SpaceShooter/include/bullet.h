#pragma once
#include "public.h"
#include "enemy.h"
class Bullet{
public:
    int width, height, x, y, speed;
    bool active;
    Bullet();
    void Update(Enemy enemy[]);
};