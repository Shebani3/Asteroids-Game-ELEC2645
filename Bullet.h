
#ifndef BULLET_H
#define BULLET_H
#include "Joystick.h"
#include "N5110.h"
#include "SpaceObject.h"

class Bullet{
public:
int collision_status=0;
int _bx, _by, _speed;
Direction r;
Bullet(int x, int y,int speed,Direction d);
//void init();
void pos_update();
void drawit( N5110&lcd);
bool collision(SpaceObject s1);


};

#endif
