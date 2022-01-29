#include "../headers/invader.h"
#include "raylib.h"
#include <vector>
using namespace std;
#include <iostream>
using namespace std;
Invader::Invader(float X,float Y,float Width,float Height,Texture2D* InvaderTexture,vector<Rectangle>* Bullets,Sound* InvaderKilled,int* Fps,vector<Rectangle>* InvaderBullets,int* Score){
    x = X;
    y = Y;
    width = Width;
    height = Height;
    invaderTexture = InvaderTexture;
    bullets = Bullets;
    fps = Fps;
    score = Score;
    invaderBullets = InvaderBullets;
    invaderKilled = InvaderKilled;
    invaderRectangle.x = x;
    invaderRectangle.y = y;
    invaderRectangle.height = height;
    invaderRectangle.width = width;
    textureRectangle.x = 0;
    textureRectangle.y = 0;
    textureRectangle.width = width;
    textureRectangle.height = height;

}
void Invader::draw(){
    if(invaderFps == *fps && textureRectangle.x == 0){
        textureRectangle.x = width;
        invaderFps = 0;
    }else if(invaderFps == *fps && textureRectangle.x == width){
        textureRectangle.x = 0;
        invaderFps = 0;
    } 
    DrawTextureRec(*invaderTexture,textureRectangle,Vector2{x,y},WHITE);
    
    invaderFps++;
}
bool Invader::checkCollisionBullets(){
    for(int i = 0;i<(*bullets).size();i++){
        if(CheckCollisionRecs((*bullets)[i],invaderRectangle)){
            (*bullets).erase((*bullets).begin() + i);
            PlaySound(*invaderKilled);
            *score += 20;
            return true;
        }
    }
    return false;
}
void Invader::handleBullets(){
    if(GetRandomValue(0,7000) == 50){
        (*invaderBullets).push_back({x+width/2,y+height,10,25});
    }
}