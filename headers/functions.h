#pragma once
#include "invader.h"
#include "player.h"
#include "raylib.h"
#include <vector>
using namespace std;
void drawBullets(vector<Rectangle> bullets,vector<Rectangle> invaderBullets);
void moveBullets(vector<Rectangle>* bullets,vector<Rectangle>* invaderBullets);
void resetInvaders(vector<Invader>* invaders,int screenWidth,Texture2D* invaderTextureOne,Texture2D* invaderTextureTwo,Texture2D* invaderTextureThree,Sound* invaderKilled,int* fps,vector<Rectangle>* invaderBullets,int* score,vector<Rectangle>* playerBullets);
void gameOverScreen(int screenWidth,int screenHeight);
bool collisionPlayerInvaders(vector<Invader> invaders,Player player);
bool invadersUnderScreen(vector<Invader>* invaders,int screenHeight);
void moveInvaders(vector<Invader>* invaders,int screenWidth,int* xVelocity);

