#include "../headers/player.h"
#include "../headers/invader.h"
#include "../headers/functions.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 800;
    const int playerWidth = 120;
    const int playerHeight = 80;
    int fps = 120;
    int score = 0;
    int health = 3;
    InitWindow(screenWidth, screenHeight, "space-invaders");
    InitAudioDevice();
    Sound shoot = LoadSound("../resources/shoot.wav");
    Sound invaderKilled = LoadSound("../resources/invaderKilled.wav");
    Texture2D playerTexture = LoadTexture("../resources/player.png");
    Texture2D invaderTexture = LoadTexture("../resources/invader.png");
    vector<Rectangle> playerBullets;
    vector<Rectangle> invaderBullets;
    Player player(screenWidth/2-playerWidth/2,screenHeight-playerHeight,playerWidth,playerHeight,&playerTexture,&playerBullets,&shoot,&invaderBullets);
    vector<Invader> invaders;
    for(int i = 0 ; i < 10 ;i++){
        invaders.push_back(Invader(i*100,40,89,64,&invaderTexture,&playerBullets,&invaderKilled,&fps,&invaderBullets,&score));
        invaders.push_back(Invader(i*100,105,89,64,&invaderTexture,&playerBullets,&invaderKilled,&fps,&invaderBullets,&score));
    }
    SetTargetFPS(fps);          
    while (!WindowShouldClose() && health > 0)    
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangle(0,0,screenWidth,40,DARKGRAY);
            DrawText(TextFormat("score : %i",score), 0, 0, 40, GREEN);
            DrawText(TextFormat("health : %i",health), 400, 0, 40, GREEN);
            drawBullets(playerBullets,invaderBullets);
            moveBullets(&playerBullets,&invaderBullets);
            player.draw();
            player.move();
            player.handleBullets();
            for(int i = 0 ; i<invaders.size();i++){
                invaders[i].draw();
                if(invaders[i].checkCollisionBullets()){
                    invaders.erase(invaders.begin() + i);
                }
                invaders[i].move();
                invaders[i].handleBullets();
            }
        EndDrawing();
        if(player.isShot()){
            health--;
        }
    }
    UnloadTexture(playerTexture);
    UnloadTexture(invaderTexture);
    UnloadSound(shoot); 
    UnloadSound(invaderKilled);      
    CloseAudioDevice(); 
    CloseWindow();           
}