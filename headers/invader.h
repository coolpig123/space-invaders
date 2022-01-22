#pragma once
#include "raylib.h"
#include <vector>
using namespace std;
struct Invader{
    float x;
    float y;
    float width;
    float height;
    Texture2D* invaderTexture;
    vector<Rectangle>* bullets;
    Sound* invaderKilled;
    Rectangle invaderRectangle;
    Invader(float X,float Y,float Width,float Height,Texture2D* InvaderTexture,vector<Rectangle>* Bullets,Sound* InvaderKilled);
    void draw();
    bool checkCollisionBullets();
};