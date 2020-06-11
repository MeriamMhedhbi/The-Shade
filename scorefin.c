#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <SDL/SDL_mixer.h>
#include "scorefin.h"



void scorefin( SDL_Surface* screen ,int score, int temps)
{
	TTF_Font *police=NULL;
	SDL_Color couleurnoir={0,0,0};
	SDL_Surface *texte=NULL ;
	SDL_Rect pos;
	pos.x =500;
	pos.y=100;	

	
	
	
	char ch1[40]="great game your score is  "; char ch2[60]; 
 char ch4[20]; char ch5[20]=" time in seconds ";

	sprintf(ch2, "%d", score);
	sprintf(ch4,"%d", temps);
	 strcat(ch1,ch2);
	  strcat(ch5,ch4);
	 strcat(ch1,ch5);
	
	
	police=TTF_OpenFont("a.otf",35);
	texte=TTF_RenderText_Blended(police,ch1,couleurnoir);
	SDL_BlitSurface(texte, NULL, screen, &pos);

	SDL_Flip(screen);
	
	
	

}

 