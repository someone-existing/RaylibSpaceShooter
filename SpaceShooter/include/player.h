#pragma once
#include "public.h"
#include "bullet.h"

class Player{
public:
    int width, height, x, y, speed;
    
    Player();
    void Move();
    void Draw();
    void Shoot(Bullet bullet[]);
    void Die();
};