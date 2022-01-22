#include "../headers/player.h"
#include "../headers/invader.h"
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
    InitAudioDevice();
    Sound shoot = LoadSound("../resources/shoot.wav");
    Sound invaderKilled = LoadSound("../resources/invaderKilled.wav");
    Texture2D playerTexture = LoadTexture("../resources/player.png");
    Texture2D invaderTexture = LoadTexture("../resources/invaderOne.png");
    vector<Rectangle> bullets;
    vector<Invader> invaders;
    for(int i = 0 ; i < 10 ;i++){
        invaders.push_back(Invader(i*100,0,89,64,&invaderTexture,&bullets,&invaderKilled));
        invaders.push_back(Invader(i*100,65,89,64,&invaderTexture,&bullets,&invaderKilled));
    }
    Player player(0,screenHeight-playerHeight,playerWidth,playerHeight,&playerTexture,&bullets,&shoot);
    SetTargetFPS(120);          
    while (!WindowShouldClose())    
    {
        BeginDrawing();
            ClearBackground(BLACK);
            player.draw();
            player.move();
            player.handleBullets();
            for(int i = 0 ; i<invaders.size();i++){
                invaders[i].draw();
                if(invaders[i].checkCollisionBullets()){
                    invaders.erase(invaders.begin() + i);
                }
            }
        EndDrawing();
    }
    UnloadTexture(playerTexture);
    UnloadTexture(invaderTexture);
    UnloadSound(shoot); 
    UnloadSound(invaderKilled);      
    CloseAudioDevice(); 
    CloseWindow();           
}