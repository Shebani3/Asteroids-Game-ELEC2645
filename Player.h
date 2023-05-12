

#ifndef PLAYER_H
#define PLAYER_H

#include "mbed.h"
#include "N5110.h"

#include <cstdio>
#include <cmath>
#include "Joystick.h" 
class Player{
public:

Player();
void initialise();
void pos_update(float angle,  bool thrust,Direction d);
void drawPlayer(N5110 &lcd);

void set_xc(int xc);
void set_yc(int yc);

int get_x1();
int get_y1();

int _xc,_yc;
void wrapped_coord();

private:
int _x0,_y0,_x1,_y1,_x2,_y2,_speed,_size;
void move_angle(Direction d);
float rad(float angle); //convert angle in degress to radian
};

#endif
