#include "../headers/player.h"
#include "../headers/invader.h"
#include "../headers/functions.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    const int screenWidth = 1600;
    const int screenHeight = 1000;
    const int playerWidth = 120;
    const int playerHeight = 80;
    int fps = 120;
    int score = 0;
    int health = 3;
    int xVelocity = 1;
    InitWindow(screenWidth, screenHeight, "space-invaders");
    InitAudioDevice();
    Sound shoot = LoadSound("../resources/shoot.wav");
    Sound explosion = LoadSound("../resources/explosion.wav");
    Sound invaderKilled = LoadSound("../resources/invaderKilled.wav");
    Texture2D playerTexture = LoadTexture("../resources/player.png");
    Texture2D invaderTextureOne = LoadTexture("../resources/invaderOne.png");
    Texture2D invaderTextureTwo = LoadTexture("../resources/invaderTwo.png");
    Texture2D invaderTextureThree = LoadTexture("../resources/invaderThree.png");
    vector<Rectangle> playerBullets;
    vector<Rectangle> invaderBullets;
    Player player(screenWidth/2-playerWidth/2,screenHeight-playerHeight,playerWidth,playerHeight,&playerTexture,&playerBullets,&shoot,&invaderBullets);
    vector<Invader> invaders;
    resetInvaders(&invaders,screenWidth,&invaderTextureOne,&invaderTextureTwo,&invaderTextureThree,&invaderKilled,&fps,&invaderBullets,&score,&playerBullets);
    SetTargetFPS(fps);          
    while (!WindowShouldClose())    
    {
        if(health != 0){
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
                    invaders[i].handleBullets();
                }
            EndDrawing();
            moveInvaders(&invaders,screenWidth,&xVelocity);
            if(player.isShot()) health--;
            if(invaders.size() == 0) resetInvaders(&invaders,screenWidth,&invaderTextureOne,&invaderTextureTwo,&invaderTextureThree,&invaderKilled,&fps,&invaderBullets,&score,&playerBullets);
            if(collisionPlayerInvaders(invaders,player)) health = 0,PlaySound(explosion);
            if(health == 0) PlaySound(explosion);
            if(invadersUnderScreen(&invaders,screenHeight)) resetInvaders(&invaders,screenWidth,&invaderTextureOne,&invaderTextureTwo,&invaderTextureThree,&invaderKilled,&fps,&invaderBullets,&score,&playerBullets);
        }else{
            gameOverScreen(screenWidth,screenHeight);
            if(IsKeyDown(KEY_SPACE)){
                health = 3;
                score = 0;
                player.x = screenWidth/2-player.width/2;
                resetInvaders(&invaders,screenWidth,&invaderTextureOne,&invaderTextureTwo,&invaderTextureThree,&invaderKilled,&fps,&invaderBullets,&score,&playerBullets);
            }
        }
    }
    UnloadTexture(playerTexture);
    UnloadTexture(invaderTextureOne);
    UnloadTexture(invaderTextureTwo);
    UnloadTexture(invaderTextureThree);
    UnloadSound(shoot); 
    UnloadSound(explosion);  
    UnloadSound(invaderKilled);      
    CloseAudioDevice(); 
    CloseWindow();           
}