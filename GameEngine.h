#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "mbed.h"
#include "N5110.h"
#include "Joystick.h" 
#include "Player.h" //utils header file is the issue 
#include <cstdio>
#include <vector>
#include "Bullet.h"
#include <stdlib.h> 
#include <ctime> 
#include "SpaceObject.h"

class GameEngine {
    public:
        GameEngine();  // pass in the lcd object from the main file
        void init(int a1, int a2, int b1 ,int b2,int c,int d1,int d2,int c2,int size1,int size2);
       void draw_objs(N5110 &lcd);
   void update(float angle, bool buttonA,  Direction d,int d1,int d2);
   void collision_ast_player( int *l);
   void bullet_update();
   void fire( Direction d);
       
    public:
       
        
         vector<SpaceObject> Asteroid;
         vector<Bullet> Bulletvec;
        Player P1;
        
};

#endif