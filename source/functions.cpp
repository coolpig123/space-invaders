#include "../headers/functions.h"
#include "raylib.h"
#include <vector>
using namespace std;
void drawBullets(vector<Rectangle> bullets,vector<Rectangle> invaderBullets){
    for(Rectangle i : bullets){
        DrawRectangleRec(i,GREEN);
    }
    for(Rectangle i : invaderBullets){
        DrawRectangleRec(i,GREEN);  
    }
}
void moveBullets(vector<Rectangle>* bullets,vector<Rectangle>* invaderBullets){
    for(int i = 0;i<(*bullets).size();i++){
        (*bullets)[i].y -= 6;
    }
    for(int i = 0;i<(*invaderBullets).size();i++){
        (*invaderBullets)[i].y += 6; 
    }
}