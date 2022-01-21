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
    Rectangle playerRectangle;
    Player(float X,float Y,float Width,float Height,Texture2D* PlayerTexture,vector<Rectangle>* Bullets);
    void draw();
    void move();
    void handleBullets();
};