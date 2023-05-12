#include "GameEngine.h"

GameEngine::GameEngine(){  }    


    void GameEngine::init(int a1, int a2, int b1 ,int b2,int c,int d1,int d2,int c2, int size1,int size2){
   
    
     P1.initialise();
    SpaceObject A1;
   
    for (int i = 0; i < 2; i++) {
    Asteroid.push_back(A1);   //SpaceObjects pushed into Asteroid vector
    }
     Asteroid[0].init(a1,b1,c,c,size1);  //Hard coded. sets asetroids initial xpos, ypos, xspeed, yspeed and size
     Asteroid[1].init(a2,b2,c2,c2,size2);

    } 

    void GameEngine::draw_objs(N5110 &lcd){ //Asteroids and Player drawn

        Asteroid[0].drawit(lcd);
        Asteroid[1].drawit(lcd);
        P1.drawPlayer(lcd); 
    }
  
  void GameEngine::update(float angle, bool buttonA,  Direction d,int d1,int d2){ //Position of asteroid and player updated including wrapped coordinates
 P1.pos_update(angle,  buttonA,  d); 
    Asteroid[1].updateAst(d1);
    Asteroid[0].updateAst(d2);
    Asteroid[0].wrapped_coord(); 
   Asteroid[1].wrapped_coord(); 
   P1.wrapped_coord();
    }

    void GameEngine::collision_ast_player(int *l){  //check if radius is larger than distance between the player and asteroid's centres.

        for (int i =0; i<2; i++){
    int a= pow((((Asteroid[i]).get_x())-(P1._xc)),2)+pow((((Asteroid[i]).get_y())-(P1._yc)),2);
    int dist = sqrt(a);
    if ((dist)<=(Asteroid[i]).get_size()){
        printf(" COLLIDE!!! ");
         (*l)=0;
       break;
    }
    }
    }

 void GameEngine::bullet_update(){  //Bullet position updated, if bullet goes outside screen bullet popped from vector, bullet asteroid collision detcted.
     if (Bulletvec.size()>0){
        for(int i=0;i<Bulletvec.size();i++){
        if((Bulletvec[i]._bx<84) & (Bulletvec[i]._bx>0) & (Bulletvec[i]._by>0)& (Bulletvec[i]._by<48)){
      Bulletvec[i].pos_update();
      if(Bulletvec[i].collision(Asteroid[0])){
          Asteroid[0]._size-=2;  //asteroid size gets smaller
           Bulletvec.erase(Bulletvec.begin()); //the bullet are also possed from vectore when they collide with asteroids.
      }
       if(Bulletvec[i].collision(Asteroid[1])){
          Asteroid[1]._size-=2;
           Bulletvec.erase(Bulletvec.begin());
      }}
      else{
          Bulletvec.erase(Bulletvec.begin());}
    }}
    }

     void GameEngine::fire(Direction d){ //Bullets are pushed back into bullet vector and initialed with player's xpos,ypos,speed and direction
        Bullet b1(P1.get_x1(),P1.get_y1(),7,d);
        Bulletvec.push_back(b1);
     }
