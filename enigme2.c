#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include "enigme2.h"


int resultatenigme2(char reponses[],char rep[],int nb)
{
	int j,i;
	FILE* preponses=NULL; char ch[5]; char rep1[5];
	
	preponses=fopen(reponses,"r");
	
	if(preponses==NULL)
	{
	printf("Error fopen reponses\n") ;
	}
	else 
	{
		for(j=1;j<=3;j++)
		{ 
		fscanf(preponses,"%s",ch);
		
		for(i=0;i<(strlen(rep));i++)
		{
		rep1[i]=rep[i]-32;
		}

		if((j==nb)&&(nb!=1)&&(strcmp(ch,rep1)==0) )
		{
		return 1;
		}
		else if((j==nb)&&(strcmp(ch,rep)==0))
		{
		return 1 ; 		
		}
		else if	(j==nb)
		{
		return 0;
		}
		}
	}
	fclose(preponses);

return 3;



}



int enigme2( int   vie, char questions[10], char reponses[10])
{
	TTF_Font *police=NULL;
	SDL_Color couleurnoir={0,0,0};	
	SDL_Rect pos; SDL_Surface *image; SDL_Surface *screen; SDL_Surface *texte=NULL ;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	screen = SDL_SetVideoMode(1600,1000 ,32 , SDL_HWSURFACE);


	

	
	pos.x=10  ;
	pos.y=10;
	FILE* pquestions=NULL; int nb,j; char qs[10];char rep[10];
	       


	pquestions=fopen(questions,"r");
	
	if(pquestions==NULL)
	{
	printf("Error fopen questions\n");	
	}
	else
		{
	//printf("tapez ** pour quitter");
	do
	{
	nb=rand()%4;
	for(j=1;j<=3;j++)
	{
	fscanf(pquestions,"%s",qs);
	if(j==nb)
		{
	police=TTF_OpenFont("a.otf",65);
	texte=TTF_RenderText_Blended(police,qs,couleurnoir);

	scanf("%s",rep);
	if(strcmp(rep,"**")) { /*return 0 ;*/  }	
	else if(resultatenigme2(reponses,rep,nb))
	{
	// le scénario continuera 
		return 0 ;
	}		
	else
	{
	image=IMG_Load("incorrect.png");
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	SDL_BlitSurface(image, NULL, screen, &pos);
	SDL_Flip(screen);
		
	vie--;	
	}
		}	
	}
	fclose(pquestions);
	}while(vie>0);	
return 0 ;
	
// afficher Game over et initialiser le jeu 

	
		}

}
