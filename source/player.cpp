#include "../headers/player.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std; 
Player::Player(float X,float Y,float Width,float Height,Texture2D* PlayerTexture,vector<Rectangle>* Bullets,Sound* Shoot){
    x = X;
    y = Y;
    width = Width;
    height = Height;
    playerTexture = PlayerTexture;
    bullets = Bullets;
    shoot = Shoot;
    playerRectangle.x = x;
    playerRectangle.y = y;
    playerRectangle.height = height;
    playerRectangle.width = width;
}
void Player::draw(){
    DrawRectangleRec(playerRectangle,BLACK);
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
    for(int i = 0;i<(*bullets).size();i++){
        DrawRectangle((*bullets)[i].x,(*bullets)[i].y,(*bullets)[i].width,(*bullets)[i].height,GREEN);
        (*bullets)[i].y -= 6;
    }
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