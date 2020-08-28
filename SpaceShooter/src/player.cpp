#include "player.h"

Player::Player(){
    width = 40;
    height = 40;
    x = screenWidth/2-width/2;
    y = screenHeight-50;
    speed = 10;
}
void Player::Die(){
    std::cout << "GAME OVER" << std::endl;
    CloseWindow();
}
void Player::Shoot(Bullet bullet[]){
    if(IsKeyPressed(KEY_SPACE)){
        for(int i = 0; i < MAX_BULLETS; i++){
            if(bullet[i].active == false){
                bullet[i].x = x + width/2 - bullet[i].width/2;
                bullet[i].y = y - bullet[i].height;
                bullet[i].active = true;
                break;
            }
        }
    }
}
void Player::Move(){
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        if(x > 0)
            x -= speed;
    }
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        if(x < screenWidth-width)
            x += speed;
    }
}
void Player::Draw(){
    DrawRectangle(x, y, width, height, BLUE);
}