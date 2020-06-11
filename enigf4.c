#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig4.h"

void init_enigme2(enigme222 *e) //
{
	e->p.x = 0;
	e->p.y = 0;
	e->img = NULL;
}

void generate_afficher2(SDL_Surface *screen, char image[], enigme222 *e, int *alea)
{
	int test = *alea;
	srand(time(NULL));
	do
	{
		*alea = 1 + rand() % 8;
	} while (*alea == test);
	sprintf(image, "%da.png", *alea);
	e->img = IMG_Load(image);
	SDL_BlitSurface(e->img, NULL, screen, &(e->p));
	SDL_Flip(screen);
}

int solution_e2(char image[])
{
	int solution = 0;

	if (strcmp(image, "1a.png") == 0)
	{
		solution = 2;
	}
	else if (strcmp(image, "2a.png") == 0)
	{
		solution = 2;
	}
	else if (strcmp(image, "3a.png") == 0)
	{
		solution = 1;
	}
	else if (strcmp(image, "4a.png") == 0)
	{
		solution = 1;
	}
	else if (strcmp(image, "5a.png") == 0)
	{
		solution = 3;
	}
	else if (strcmp(image, "6a.png") == 0)
	{
		solution = 3;
	}
	else if (strcmp(image, "7a.png") == 0)
	{
		solution = 1;
	}
	else if (strcmp(image, "8a.png") == 0)
	{
		solution = 2;
	}

	return solution;
}

int resolution2(int *running, int *run) //
{
	SDL_Event event;
	int r = 0;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		*running = 0;
		*run = 0;
		break;

	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			r = 1;
			break;
		case SDLK_z:
			r = 2;
			break;
		case SDLK_e:
			r = 3;
			break;
		}
		break;
	}
	return r;
}

void afficher_resultat2(SDL_Surface *screen, int s, int r, enigme222 *en) //
{

	if (r == s)
	{
		en->img = IMG_Load("11a.png");
		SDL_BlitSurface(en->img, NULL, screen, &(en->p));
		SDL_Flip(screen);
	}
	else
	{
		en->img = IMG_Load("00a.png");
		SDL_BlitSurface(en->img, NULL, screen, &(en->p));
		SDL_Flip(screen);
	}
}

int eni4(SDL_Surface *screen, int *vie)
{

	SDL_Surface  *image1;
	SDL_Rect p;
	p.x = 0;
	p.y = 0;
	enigme222 e;
	FILE *f;
	int s, r, run = 1, running = 1, alea;
	char image[30] = "";
	SDL_Event event;
	f = fopen("testa.txt", "a");



	init_enigme2(&e);

	if (e.img == NULL)
	{
		fprintf(f, "%d\n", 1800);
	}

	while (run)
	{
		running = 1, r = 0;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			run = 0;
			break;
		}
		fprintf(f, "%d\n", e.p.x);
		fprintf(f, "%d\n", e.p.y);
		generate_afficher2(screen, image, &e, &alea);
		fprintf(f, "%s\n", image);

		s = solution_e2(image);
		do
		{
			r = resolution2(&running, &run);
		} while ((r > 3 || r < 1) && running != 0);
		fprintf(f, "run=%d\n", run);
		fprintf(f, "s= %d\nr=%d\n", s, r);
		if(r!=s)
            {
	 		/*	v++;
	    	printf("%d\n",v);

			if(v==3)*/
		
		  (*vie)--;

			}
		

		while (running)
		{

			afficher_resultat2(screen, s, r, &e);
			SDL_WaitEvent(&event);
			switch (event.type)
			{
			case SDL_QUIT:
				running = 0;
				run = 0;
				break;
			case SDL_KEYDOWN:

				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = 0;
					run = 0;

					break;
				case SDLK_SPACE:
					running = 0;
					break;
				}
				break;
			}
		}
	}
	fclose(f);
	return 0;
}
