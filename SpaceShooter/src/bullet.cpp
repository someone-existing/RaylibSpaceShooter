#include "bullet.h"

Bullet::Bullet(){
    width = 10;
    height = 10;
    speed = 15;
    active = false;
}
void Bullet::Update(Enemy enemy[]){
    DrawRectangle(x, y, width, height, BLACK);
    y -= speed;
    if(y < width*-1){
        active = false;
    }
    for(int i = 0; i < MAX_ENEMIES; i++){
        if((enemy[i].y + enemy[i].height >= y && y <= enemy[i].y) && (enemy[i].x <= x+width && enemy[i].x + enemy[i].width > x)){
            //std::cout << "Enemy " << i << " died." << std::endl;
            active = false;
            enemy[i].Die();
        }
    }
}