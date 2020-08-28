#include <enemy.h>

void Enemy::MoveandDraw(){
    if(active == false){
            x = GetRandomValue(0, screenWidth-width);
            y = GetRandomValue(height*-1, screenHeight*-1);
            active = true;
        }
        else{
            DrawRectangle(x, y, width, height, RED);
            y += speed;
        }
}
void Enemy::Die(){
    active = false;
}
Enemy::Enemy(){
    width = 40;
    height = 40;
    x = GetRandomValue(0, screenWidth-width);
    y = GetRandomValue(height*-1, screenHeight*-1);
    speed = 10;
    active = true;
}