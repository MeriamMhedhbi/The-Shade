#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include"closhard.h"

void CLOCHARD_Init(Clochard *c)    

{

	c->sprite = IMG_Load("meriam.png");
    c->sprite2 = IMG_Load("meriam2.png");
    c->c_pos.x = 1700;
    c->c_pos.y = 710;
	c->dx = 0; 
	c->cx = 0;
	c->c_pos.w=88;
	c->c_pos.h=170; 
	c->etat=0;
} 
void CLOCHARD_Init2(Clochard *c)    

{
    c->sprite = IMG_Load("meriam.png");
    c->sprite2 = IMG_Load("meriam2.png");
    c->c_pos.x = 1700;
    c->c_pos.y = 710;
	c->dx = 0; 
	c->cx = 0;
	c->c_pos.w=88;
	c->c_pos.h=170; 
	c->etat=0;
} 

void CLOCHARD_Init3(Clochard *c)    

{
    c->sprite = IMG_Load("taha.png");
    c->sprite2 = IMG_Load("taha2.png");
    c->c_pos.x = 4000;
    c->c_pos.y = 710;
	c->dx = 0; 
	c->cx = 0;
	c->c_pos.w=88;
	c->c_pos.h=170; 
	c->etat=0;
} 

void CLOCHARD_Render(Clochard *c, SDL_Surface **screen)
{ 
	SDL_Rect r2 = {c->c_pos.x, c->c_pos.y};
	if(c->dx){
		c->c_pos.x += 5;
		SDL_BlitSurface(c->sprite2,NULL,*screen, &r2);
	}else{
		SDL_BlitSurface(c->sprite,NULL,*screen, &r2);
		c->c_pos.x -= 5;

	}

	c->cx++;
	if(c->cx % 10 == 0)
		c->dx = !c->dx;
}
