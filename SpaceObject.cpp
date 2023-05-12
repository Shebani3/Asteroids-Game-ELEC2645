#include "SpaceObject.h"


SpaceObject::SpaceObject() {
}

void SpaceObject::init(int x, int y, float dx, float dy, int size ) {

    _size = size;
    _x = x;
    _y = y;
    _dx = dx;
   _dy = dy;
   
}

void SpaceObject::drawit(N5110 &lcd) {
    lcd.drawCircle(_x,_y,_size,FILL_TRANSPARENT);
    
    
}


void SpaceObject::wrapped_coord(){ //wrapped coordinates for asteroids 
    if (_x >84){
        _x = 0;
    }if (_y < 0){
        _y = 48;
    }if (_x<0){
        _x = 84;
    }if (_y>48){
        _y = 0;
    }

}

void SpaceObject::updateAst(int c){ //update asteroid posiitoon based on random variable
   
    if (c==0){
    _x-=_dx;
    _y+=_dy;

   }
   else if (c==1){
        _x+=_dx;
    _y-=_dy;
    }

    else if (c==2){
        _x+=_dx;
    
    }

    else if (c==3){
        _x-=_dx;
    
    }
    else if (c==4){
        
    _y-=_dy;
    }
    else if (c==5){
      
    _y+=_dy;
    }
    else if (c==6){
      _x+=_dx;
    _y+=_dy;
    }
    else if (c==7){
      _x-=_dx;
    _y-=_dy;
    }



}
////////////mutators
void SpaceObject::set_x(int x){
    _x=x;
};
void SpaceObject::set_y(int y){
    _y=y;
};

void SpaceObject::set_dx(int dx){
    _dx=dx;
};
void SpaceObject::set_dy(int dy){
    _dy=dy;
};

void SpaceObject::set_size(int size){
    _size=size;
};


///////////accessors
int SpaceObject::get_size(){
return _size;
}
int SpaceObject::get_x(){
return _x;
}
int SpaceObject::get_y(){
return _y;
}
int SpaceObject::get_dx(){
return _dx;
}
int SpaceObject::get_dy(){
return _dy;
}

