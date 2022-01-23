#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;
struct Player{
    float x;
    float y;
    float width;
    float height;
    Texture2D* playerTexture;
    vector<Rectangle>* bullets;
    vector<Rectangle>* invaderBullets;
    Sound* shoot;
    Rectangle playerRectangle;
    Player(float X,float Y,float Width,float Height,Texture2D* PlayerTexture,vector<Rectangle>* Bullets,Sound* Shoot,vector<Rectangle>* InvaderBullets);
    void draw();
    void move();
    void handleBullets();
    bool isShot();
};