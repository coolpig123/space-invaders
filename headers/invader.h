#pragma once
#include "raylib.h"
#include <vector>
using namespace std;
struct Invader{
    float x;
    float y;
    float width;
    float height;
    int* fps;
    int invaderFps = 0;
    int xVelocity = 2;
    int yVelocity = 8;
    int* score;
    Texture2D* invaderTexture;
    vector<Rectangle>* bullets;
    vector<Rectangle>* invaderBullets;
    Sound* invaderKilled;
    Rectangle invaderRectangle;
    Rectangle textureRectangle;
    Invader(float X,float Y,float Width,float Height,Texture2D* InvaderTexture,vector<Rectangle>* Bullets,Sound* InvaderKilled,int* Fps,vector<Rectangle>* InvaderBullets,int* Score);
    void draw();
    bool checkCollisionBullets();
    void handleBullets();
};