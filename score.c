#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include "score.h"
#include <string.h>


void initialiserScore(  Score *score )
{
	char string[20];
	SDL_Color couleurRose = {0,0,0};
	
	score->posScore.x=300 ;
	score->posScore.y=100;
	score->posFond.x=score->posScore.x-20;
	score->posFond.y=score->posScore.y-20;	

	score->fondScore = IMG_Load("resources/bois.png");
	(score->police) = TTF_OpenFont("resources/coolvetica condensed rg.ttf", 35);

	score->scoreActuel=0;
	sprintf(string, "score = %d ", score->scoreActuel);

	(score->texteScore)=TTF_RenderText_Blended(score->police ,string, couleurRose);		
}
void initialiserScore2(  Score *score )
{
	char string[20];
	SDL_Color couleurRose = {0,0,0};
	
    score->posScore.x = 300;
    score->posScore.y = 550;
	score->posFond.x=score->posScore.x-20;
	score->posFond.y=score->posScore.y-20;	

	score->fondScore = IMG_Load("resources/bois.png");
	(score->police) = TTF_OpenFont("resources/coolvetica condensed rg.ttf", 35);

	score->scoreActuel=0;
	sprintf(string, "score = %d ", score->scoreActuel);

	(score->texteScore)=TTF_RenderText_Blended(score->police ,string, couleurRose);		
}


void afficherScore(SDL_Surface *ecran , Score *score ,int s )
{

		
	SDL_Color couleurRose = {0,0,0};
	
	char string[20];
	
	//score->scoreActuel=bg.position.x*0.1+50*collision;
	score->scoreActuel=s;
	sprintf(string, "score = %d ", score->scoreActuel);
	
	score->texteScore =TTF_RenderText_Blended(score->police,string, couleurRose);
	
	SDL_BlitSurface(score->fondScore, NULL, ecran, &score->posFond);
	SDL_BlitSurface(score->texteScore, NULL, ecran, &score->posScore);
}
