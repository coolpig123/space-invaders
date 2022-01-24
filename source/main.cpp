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
    Texture2D invaderTextureOne = LoadTexture("../resources/invaderOne.png");
    Texture2D invaderTextureTwo = LoadTexture("../resources/invaderTwo.png");
    vector<Rectangle> playerBullets;
    vector<Rectangle> invaderBullets;
    Player player(screenWidth/2-playerWidth/2,screenHeight-playerHeight,playerWidth,playerHeight,&playerTexture,&playerBullets,&shoot,&invaderBullets);
    vector<Invader> invaders;
    for(int i = 0 ; i < 8 ;i++){
        invaders.push_back(Invader(i*(screenWidth/8)+8,40,89,64,&invaderTextureOne,&playerBullets,&invaderKilled,&fps,&invaderBullets,&score));
        invaders.push_back(Invader(i*(screenWidth/8)+8,120,96,64,&invaderTextureTwo,&playerBullets,&invaderKilled,&fps,&invaderBullets,&score));
    }
    SetTargetFPS(fps);          
    while (!WindowShouldClose())    
    {

        BeginDrawing();
        if(health != 0){
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
            if(player.isShot()) health--;
            if(invaders.size() == 0){
                for(int i = 0 ; i < 8 ;i++){
                    invaders.push_back(Invader(i*(screenWidth/8)+8,40,89,64,&invaderTextureOne,&playerBullets,&invaderKilled,&fps,&invaderBullets,&score));
                    invaders.push_back(Invader(i*(screenWidth/8)+8,120,96,64,&invaderTextureTwo,&playerBullets,&invaderKilled,&fps,&invaderBullets,&score));
                }
            }
        }   
        else {
            BeginDrawing();
                ClearBackground(BLACK);
                DrawText("game over",screenWidth/2-200, screenHeight/2-100, 80, WHITE);
                DrawText("to start press space",screenWidth/2-300, screenHeight/2, 60, WHITE);
            EndDrawing();
            if(IsKeyDown(KEY_SPACE)){
                health = 3;
                score = 0;
                player.x = screenWidth/2-playerWidth/2;
                invaders.clear();
                for(int i = 0 ; i < 8 ;i++){
                    invaders.push_back(Invader(i*(screenWidth/8)+8,40,89,64,&invaderTextureOne,&playerBullets,&invaderKilled,&fps,&invaderBullets,&score));
                    invaders.push_back(Invader(i*(screenWidth/8)+8,120,96,64,&invaderTextureTwo,&playerBullets,&invaderKilled,&fps,&invaderBullets,&score));
                }
            }

        }
    }
    UnloadTexture(playerTexture);
    UnloadTexture(invaderTextureOne);
    UnloadTexture(invaderTextureTwo);
    UnloadSound(shoot); 
    UnloadSound(invaderKilled);      
    CloseAudioDevice(); 
    CloseWindow();           
}