#pragma once
#include "raylib.h"
#include <vector>
using namespace std;
void drawBullets(vector<Rectangle> bullets,vector<Rectangle> invaderBullets);
void moveBullets(vector<Rectangle>* bullets,vector<Rectangle>* invaderBullets);