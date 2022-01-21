#include "../headers/player.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 500;
    const int playerWidth = 100;
    const int playerHeight = 100;
    InitWindow(screenWidth, screenHeight, "space-invaders");
    Texture2D playerTexture = LoadTexture("../resources/player.png");
    vector<Rectangle> bullets;
    Player player(0,screenHeight-playerHeight,playerWidth,playerHeight,&playerTexture,&bullets);
    SetTargetFPS(60);               
    while (!WindowShouldClose())    
    {
        BeginDrawing();
            ClearBackground(BLACK);
            player.draw();
            player.move();
            player.handleBullets();
        EndDrawing();
    }
    UnloadTexture(playerTexture);
    CloseWindow();           
}