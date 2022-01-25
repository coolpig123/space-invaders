#include "../headers/functions.h"
#include "../headers/invader.h"
#include "../headers/player.h"
#include "raylib.h"
#include <vector>
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
void resetInvaders(vector<Invader>* invaders,int screenWidth,Texture2D* invaderTextureOne,Texture2D* invaderTextureTwo,Sound* invaderKilled,int* fps,vector<Rectangle>* invaderBullets,int* score,vector<Rectangle>* playerBullets){
    (*invaders).clear();
    for(int i = 0 ; i < 8 ;i++){
        (*invaders).push_back(Invader(i*(screenWidth/8)+8,40,89,64,invaderTextureOne,playerBullets,invaderKilled,fps,invaderBullets,score));
        (*invaders).push_back(Invader(i*(screenWidth/8)+8,120,96,64,invaderTextureTwo,playerBullets,invaderKilled,fps,invaderBullets,score));
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