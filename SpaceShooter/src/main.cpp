#include "enemy.h"
#include "bullet.h"
#include "player.h"

int main(int argc, char* argv[])
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(screenWidth, screenHeight, "Space Shooter");
    SetTargetFPS(60);
    Player player;
    Bullet bullet[MAX_BULLETS];
    Enemy enemy[MAX_ENEMIES];
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(10, 10);
        player.Draw();
        player.Move();
        player.Shoot(bullet);
        for(int i = 0; i < MAX_BULLETS; i++){
            if(bullet[i].active == true){
                bullet[i].Update(enemy);
            }
        }
        for(int i = 0; i < MAX_ENEMIES; i++){
            enemy[i].MoveandDraw();
            if(enemy[i].y > screenHeight){
                enemy[i].Die();
            }
            if((enemy[i].x < player.x+player.width && enemy[i].x+enemy[i].width > player.x) && (enemy[i].y+enemy[i].height > player.y)){
                player.Die();
            }
        }
        EndDrawing();
        
    }

    CloseWindow();
    return 0;
}
