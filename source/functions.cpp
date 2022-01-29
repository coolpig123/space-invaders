#include "../headers/functions.h"
#include "../headers/invader.h"
#include "../headers/player.h"
#include "raylib.h"
#include <vector>
#include <iostream>
using namespace std;
void drawBullets(vector<Rectangle> bullets,vector<Rectangle> invaderBullets){
    for(Rectangle i : bullets){
        DrawRectangleRec(i,GREEN);
    }
    for(Rectangle i : invaderBullets){
        DrawRectangleRec(i,GREEN);  
    }
}
void moveBullets(vector<Rectangle>* bullets,vector<Rectangle>* invaderBullets){
    for(int i = 0;i<(*bullets).size();i++){
        (*bullets)[i].y -= 6;
    }
    for(int i = 0;i<(*invaderBullets).size();i++){
        (*invaderBullets)[i].y += 6; 
    }
}
void resetInvaders(vector<Invader>* invaders,int screenWidth,Texture2D* invaderTextureOne,Texture2D* invaderTextureTwo,Texture2D* invaderTextureThree,Sound* invaderKilled,int* fps,vector<Rectangle>* invaderBullets,int* score,vector<Rectangle>* playerBullets){
    (*invaders).clear();
    for(int i = 0 ; i < 11 ;i++){
        (*invaders).push_back(Invader(i*104+16,40+(72*0),64,64,invaderTextureThree,playerBullets,invaderKilled,fps,invaderBullets,score));
        (*invaders).push_back(Invader(i*104+4,40+(72*1),89,64,invaderTextureOne,playerBullets,invaderKilled,fps,invaderBullets,score));
        (*invaders).push_back(Invader(i*104+4,40+(72*2),89,64,invaderTextureOne,playerBullets,invaderKilled,fps,invaderBullets,score));
        (*invaders).push_back(Invader(i*(96+8),40+(72*3),96,64,invaderTextureTwo,playerBullets,invaderKilled,fps,invaderBullets,score));
        (*invaders).push_back(Invader(i*(96+8),40+(72*4),96,64,invaderTextureTwo,playerBullets,invaderKilled,fps,invaderBullets,score));
    }
}
void gameOverScreen(int screenWidth,int screenHeight){
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("game over",screenWidth/2-200, screenHeight/2-100, 80, WHITE);
        DrawText("to start press space",screenWidth/2-300, screenHeight/2, 60, WHITE);
    EndDrawing();
}
bool collisionPlayerInvaders(vector<Invader> invaders,Player player){
    for(Invader i : invaders){
        if(CheckCollisionRecs(player.playerRectangle,i.invaderRectangle)){
            return true;
        }
    }
    return false;
}
bool invadersUnderScreen(vector<Invader>* invaders,int screenHeight){
    bool isUnderScreen;
    for(int i = 0;i<55;i+=6){
        if((*invaders)[i].y < screenHeight){
            return false;
        }
    }
    return true;
}
void moveInvaders(vector<Invader>* invaders,int screenWidth,int* xVelocity){
    bool biggestX = false;
    bool smallestX = false;
    if(*xVelocity == 1){
        for(int i = 0;i<(*invaders).size();i++){
            if(((*invaders)[i].x+(*invaders)[i].width) == screenWidth){
                biggestX = true;
            }
            (*invaders)[i].x += *xVelocity;
            (*invaders)[i].invaderRectangle.x = (*invaders)[i].x;
        }
    }else{
        for(int i = 0;i<(*invaders).size();i++){
            if((*invaders)[i].x == 0){
                smallestX = true;
            }
            (*invaders)[i].x += *xVelocity;
            (*invaders)[i].invaderRectangle.x = (*invaders)[i].x;
        }
        
    }
    
    if(biggestX && *xVelocity == 1){
        *xVelocity = -1;
        for(int i = 0;i<(*invaders).size();i++){
            (*invaders)[i].y += 64;
            (*invaders)[i].invaderRectangle.y = (*invaders)[i].y;
        }
    }else if(smallestX && *xVelocity == -1){
        *xVelocity = 1;
        for(int i = 0;i<(*invaders).size();i++){
            (*invaders)[i].y += 64;
            (*invaders)[i].invaderRectangle.y = (*invaders)[i].y;
        }
    }
}