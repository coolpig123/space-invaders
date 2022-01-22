#include "../headers/invader.h"
#include "raylib.h"
#include <vector>
using namespace std;
Invader::Invader(float X,float Y,float Width,float Height,Texture2D* InvaderTexture,vector<Rectangle>* Bullets,Sound* InvaderKilled){
    x = X;
    y = Y;
    width = Width;
    height = Height;
    invaderTexture = InvaderTexture;
    bullets = Bullets;
    invaderKilled = InvaderKilled;
    invaderRectangle.x = x;
    invaderRectangle.y = y;
    invaderRectangle.height = height;
    invaderRectangle.width = width;
}
void Invader::draw(){
    DrawRectangleRec(invaderRectangle,BLACK);
    DrawTexture(*invaderTexture,invaderRectangle.x,invaderRectangle.y,WHITE);
}
bool Invader::checkCollisionBullets(){
    for(int i = 0;i<(*bullets).size();i++){
        if(CheckCollisionRecs((*bullets)[i],invaderRectangle)){
            (*bullets).erase((*bullets).begin() + i);
            PlaySound(*invaderKilled);
            return true;
        }
    }
    return false;
}

