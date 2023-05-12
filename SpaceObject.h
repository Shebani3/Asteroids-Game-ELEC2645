

#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include "mbed.h"
#include "N5110.h"

#include <cstdio>
#include <cmath>


class SpaceObject{
public:
int _size;
SpaceObject();
void init(int x, int y, float dx, float dy, int size);
void set_x(int xc);
void set_y(int yc);
void set_dx(int dx);
void set_dy(int dy);
void set_size(int size);
int get_x();
int get_y();
int get_size();
int get_dx();
int get_dy();
void drawit(N5110 &lcd);
void updateAst(int c);
void wrapped_coord();

private:
int _x;
int _y;
float _dx;
float _dy;
};
#endif
