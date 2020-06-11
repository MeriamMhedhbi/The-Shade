#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include "vie.h"
#include "score.h"
#include <string.h>



  
Vie initialiserVie()
{
	Vie vi;

	vi.vie_img1=IMG_Load("resources/vie 0.png");  
	vi.vie_img2=IMG_Load("resources/vie 1.png");
	vi.vie_img3=IMG_Load("resources/vie 2.png");
	vi.vie_img4=IMG_Load("resources/vie 3.png");
	vi.posVie.x=1300;
	vi.posVie.y=100;
	vi.valVie=3; 
	
	return vi;
}
Vie initialiserVie2()
{
	Vie vi;

	vi.vie_img1=IMG_Load("resources/vie 0.png");  
	vi.vie_img2=IMG_Load("resources/vie 1.png");
	vi.vie_img3=IMG_Load("resources/vie 2.png");
	vi.vie_img4=IMG_Load("resources/vie 3.png");
	vi.posVie.x=1300;
	vi.posVie.y=550;
	vi.valVie=3; 
	
	return vi;
}
int nbVie(int gameOver ,Vie vie, SDL_Surface *screen)
{

	 if (vie.valVie==0)
	{
		gameOver=0;
		SDL_BlitSurface(vie.vie_img1, NULL, screen,&vie.posVie);
	}
 	else if (vie.valVie==1)
	{
		SDL_BlitSurface(vie.vie_img2, NULL, screen, &vie.posVie);
	}
	 else if (vie.valVie==2)
	{
		SDL_BlitSurface(vie.vie_img3, NULL, screen, &vie.posVie);
	}
	 else if (vie.valVie==3)
	{
		SDL_BlitSurface(vie.vie_img4, NULL, screen, &vie.posVie);
	}
	SDL_Flip(screen);

	return gameOver;
} 

