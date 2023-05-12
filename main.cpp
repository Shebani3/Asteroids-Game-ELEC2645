
 /*  Asteroids
 written by: el21sm */

#include "mbed.h"
#include "N5110.h"
#include "Joystick.h" 
#include "Player.h" 
#include <cstdio>
#include <vector>
#include "Bullet.h"
#include <stdlib.h> 
#include <ctime> 
#include "SpaceObject.h"
#include "GameEngine.h"
#include <ctime>

//Pin assignment format:  lcd(IO, Ser_TX, Ser_RX, MOSI, SCLK, PWM)  
N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
Joystick joystick(PC_3, PC_2);
InterruptIn joystick_button(PC_10);
DigitalIn buttonA(PC_8);
DigitalIn buttonB(BUTTON1); 

void game_over(); // display 'Game Over'
void joystick_button_isr(); //interrupt service routine
void welcome(); // display 'Welome'
bool Win_case(SpaceObject s1); // check if win condition acheieved or not
void game_won(); // display 'Won!'
int win=0;
int status=0;
volatile int g_buttonA_flag = 0; //interrupt flag

char buffer[14] = {0};
int fps = 100;

GameEngine game;


int main(){
  
    int lives = 1; 
    joystick.init();  //initialise for LPH7366-1 LCD (Options are LPH7366_1 and LPH7366_6)
    lcd.init(LPH7366_1);
    lcd.setContrast(0.55);      //set contrast to 55%
    lcd.setBrightness(0.5);     //set brightness to 50% (utilises the PWM)
    Vector2D coord = joystick.get_mapped_coord();
    joystick_button.fall(&joystick_button_isr); // falling edge interrupt
    joystick_button.mode(PullUp); 
    welcome();
    GameEngine game;
	Direction d;

  srand(time(0)); //Randomly generated variables
    int x1 = rand()%10+2; //2-11(inc)
    int x2 = rand()%10+2; //2-11(inc)
    int y1 = rand()%80+1; //1-80(inc)
    int y2 = rand()%80+1;//1-80(inc)
    int speed1 = rand()%3+1;//1-3(inc)
    int d1 = rand()%8; //random number between 0 and 7
    int d2 = rand()%8; //random number between 0 and 7
    int size1 = rand()%8+4; //4-11(inc)
    int size2 = rand()%8+4; //4-11(inc)
    int speed2 = rand()%3+1;// 0-3(inc)

    game.init(x1,x2,y1,y2,speed1,d1,d2,speed2,size1,size2); //function iniisitalises player and asteroids

   while(lives>0&win==0){

    lcd.clear();  
    d= joystick.get_direction(); //get real time user direction input
    game.draw_objs(lcd); //draw player and asteroids
    lcd.refresh();

    if(g_buttonA_flag){ //when interrupt flag is set 
    g_buttonA_flag=0;
    game.fire(d); //pass real time user joystick position
    thread_sleep_for(1000/fps);
    }

   game.update(joystick.get_angle(),  buttonA.read(),  d,d1,d2); //updates player position
   game.bullet_update(); //
    
    for(int i=0;i<game.Bulletvec.size();i++){
    game.Bulletvec[i].drawit(lcd);} //draw all bullets in the bullet vector.

    thread_sleep_for(100);
    game.collision_ast_player(&lives); //check for collsion btw player and asteroid and change global variable 'lives' if collision.

    if(Win_case(game.Asteroid[0])&&Win_case(game.Asteroid[1])){win=1;} //check if win case is true and set global variable 'win'.
    }

   if (win==1){
    game_won();
   }else{
    game_over();}

}

 void game_over() { // splash screen 
    while (1) {
        lcd.clear();
        lcd.printString("  Game Over ",0,2);  
        lcd.refresh();
        ThisThread::sleep_for(250ms);
        lcd.clear();
        lcd.refresh();
        ThisThread::sleep_for(250ms);
    }
}

void game_won() { // splash screen 
    while (1) {
        lcd.clear();
        lcd.printString("  Game Won! ",0,2);  
        lcd.refresh();
        ThisThread::sleep_for(250ms);
        lcd.clear();
        lcd.refresh();
        ThisThread::sleep_for(250ms);
    }
}

void joystick_button_isr(){
  g_buttonA_flag = 1;  
}

void welcome() { // splash screen
    lcd.printString("   Asteroids",0,1);  
    lcd.printString(" Nucleo-button",0,3);
    lcd.printString("!! BE QUICK !!",0,4);
    lcd.refresh();

        while (buttonB.read() == 1){

         ThisThread::sleep_for(100ms);
      
        }
}

bool Win_case(SpaceObject s1) {
if(s1.get_size()<=1){
    return true;}
    else{
    return false;}
}