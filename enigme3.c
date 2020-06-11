#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "enigme3.h"

int resultatenigme3(char ch[])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		ch[i] = ch[i] - 32;
	}

	if (strcmp(ch, "MHZNT") == 0)
		return 1;
	else
		return 0;
}

int enigme3(int vie)
{

	int d, i;
	char ch[6];
	char rep;
	SDL_Rect pos;
	SDL_Surface *image;
	SDL_Surface *screen;
	screen = SDL_SetVideoMode(1600, 1000, 32, SDL_HWSURFACE);
	pos.x = 10;
	pos.y = 10;

	do
	{

		i = 1;
		ch[0] = '\0';

		image = IMG_Load("image0.png");
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
		SDL_BlitSurface(image, NULL, screen, &pos);
		SDL_Flip(screen);

		do
		{

			do
			{
				scanf("%c", &rep);
			} while ((rep != '*') && ((rep > 'z') || (rep < 'a')) && ((rep > 'Z') || (rep < 'A')) && ((rep > '9') || (rep < '0')));

			if (rep != '*')
			{
				switch (i)
				{

				case 1:
					image = IMG_Load("image1.png");
					SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
					SDL_BlitSurface(image, NULL, screen, &pos);
					SDL_Flip(screen);
					break;

				case 2:
					image = IMG_Load("image2.png");
					SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
					SDL_BlitSurface(image, NULL, screen, &pos);
					SDL_Flip(screen);
					break;

				case 3:
					image = IMG_Load("image3.png");
					SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
					SDL_BlitSurface(image, NULL, screen, &pos);
					SDL_Flip(screen);
					break;

				case 4:
					image = IMG_Load("image4.png");
					SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
					SDL_BlitSurface(image, NULL, screen, &pos);
					SDL_Flip(screen);
					break;

				case 5:
					image = IMG_Load("image5.png");
					SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
					SDL_BlitSurface(image, NULL, screen, &pos);
					SDL_Flip(screen);
					break;
				}
				strncat(ch, &rep, 1);
				i++;
			}
			else /*afficherbackground ; deplacement ;*/
				return 0;

		} while (i <= 5);

		if (resultatenigme3(ch) == 1)
		{

			/*la porte va s'ouvrir ; deplacement ;*/
			return 0;
		}
		else
		{
			/*Loading img le code est incorrect */

			image = IMG_Load("incorrect.png");
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
			SDL_BlitSurface(image, NULL, screen, &pos);
			SDL_Delay(20);
			SDL_Flip(screen);

			vie--;
		}

	} while (vie > 0);

	/*printf("Game Over\n"); /*init jeu ; */ return 0;
}
