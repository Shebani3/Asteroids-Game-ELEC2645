#include "Bullet.h"

Bullet::Bullet(int x, int y, int speed, Direction d){
_bx=x;
_by=y;
_speed=speed;
r=d;  // direction when fired stored
}

void Bullet::pos_update(){  // Bullet position update depending on direction when fired
  if (r==SE){
(_bx)-=_speed;
(_by)-=_speed;
 }else if (r==SW){
(_bx)+=_speed;
(_by)-=_speed;
 }else if (r==NE){
(_bx)-=_speed;
(_by)+=_speed;
  }else if (r==NW){
(_bx)+=_speed;
(_by)+=_speed;
 }else if(r==N){
(_by)+=_speed;
 }else if(r==S){
(_by)-=_speed;   
 }else if(r==E){
(_bx)-=_speed;
 }else if(r==W){
(_bx)+=_speed;
 }else if(r==CENTRE){
(_bx)+=100;
 }
}

void Bullet::drawit(N5110 &lcd) {  
    lcd.drawCircle(_bx,_by,1,FILL_TRANSPARENT);
       lcd.refresh();
    
}


bool Bullet::collision(SpaceObject s1){
     int a= pow(((s1.get_x())-(_bx)),2)+pow(((s1.get_y())-(_by)),2);
    int dist = sqrt(a);
   // printf("#  %i # ", (*it).get_size());
    if ((dist)<=(s1).get_size()){
        
        printf(" Bullet hit! ");
        printf(" size %i ", s1._size);
       // s1.set_size(6);
         return true;
         //status =0;
       
    }else{return false;}

 
}