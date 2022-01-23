#include "../headers/player.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std; 
Player::Player(float X,float Y,float Width,float Height,Texture2D* PlayerTexture,vector<Rectangle>* Bullets,Sound* Shoot,vector<Rectangle>* InvaderBullets){
    x = X;
    y = Y;
    width = Width;
    height = Height;
    playerTexture = PlayerTexture;
    bullets = Bullets;
    shoot = Shoot;
    invaderBullets = InvaderBullets;
    playerRectangle.x = x;
    playerRectangle.y = y;
    playerRectangle.height = height;
    playerRectangle.width = width;
}
void Player::draw(){
    DrawTexture(*playerTexture,playerRectangle.x,playerRectangle.y,WHITE);
}
void Player::move(){
    if(IsKeyDown(KEY_LEFT) && playerRectangle.x > 0){
        playerRectangle.x -= 4;
    }else if(IsKeyDown(KEY_RIGHT) && playerRectangle.x < GetScreenWidth()-width){
        playerRectangle.x += 4;
    }
}
void Player::handleBullets(){
    if(IsKeyPressed(KEY_SPACE)){
        (*bullets).push_back(Rectangle{playerRectangle.x+playerRectangle.width/2-5,playerRectangle.y,10,25});
        PlaySound(*shoot);
    }
    for(int i = 0;i<(*bullets).size();i++){
        if((*bullets)[i].y <= -1*(*bullets)[i].width){
            (*bullets).erase((*bullets).begin()+i);
        }
    }
}
bool Player::isShot(){
    for(int i = 0;i<(*invaderBullets).size();i++){
        if(CheckCollisionRecs((*invaderBullets)[i],playerRectangle)){
            (*invaderBullets).erase((*invaderBullets).begin() + i);
            return true;
        }
    }
    return false;
}