#pragma once
#include "invader.h"
#include "player.h"
#include "raylib.h"
#include <vector>
using namespace std;
void drawBullets(vector<Rectangle> bullets,vector<Rectangle> invaderBullets);
void moveBullets(vector<Rectangle>* bullets,vector<Rectangle>* invaderBullets);
void resetInvaders(vector<Invader>* invaders,int screenWidth,Texture2D* invaderTextureOne,Texture2D* invaderTextureTwo,Sound* invaderKilled,int* fps,vector<Rectangle>* invaderBullets,int* score,vector<Rectangle>* playerBullets);
void gameOverScreen(int screenWidth,int screenHeight);
bool collisionPlayerInvaders(vector<Invader> invaders,Player player);