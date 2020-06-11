#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include "menu.h"



void keyboard(int etat, SDL_Surface *screen, SDL_Surface *play, SDL_Surface *quit, SDL_Surface *setting, SDL_Surface *credits, SDL_Surface *quit1, SDL_Surface *setting1, SDL_Surface *play1, SDL_Surface *credits1, SDL_Rect positionplay, SDL_Rect positionquit, SDL_Rect positionsetting, SDL_Rect positioncredits)
{
	if (etat == 0)
	{
		SDL_BlitSurface(play1, NULL, screen, &positionplay);
		SDL_BlitSurface(setting, NULL, screen, &positionsetting);
		SDL_BlitSurface(credits, NULL, screen, &positioncredits);
		SDL_BlitSurface(quit, NULL, screen, &positionquit);
		SDL_Flip(screen);
	}
	else if (etat == 1)
	{
		SDL_BlitSurface(play, NULL, screen, &positionplay);
		SDL_BlitSurface(setting1, NULL, screen, &positionsetting);
		SDL_BlitSurface(credits, NULL, screen, &positioncredits);
		SDL_BlitSurface(quit, NULL, screen, &positionquit);
		SDL_Flip(screen);
	}
	else if (etat == 2)
	{
		SDL_BlitSurface(play, NULL, screen, &positionplay);
		SDL_BlitSurface(setting, NULL, screen, &positionsetting);
		SDL_BlitSurface(credits, NULL, screen, &positioncredits);
		SDL_BlitSurface(quit1, NULL, screen, &positionquit);
		SDL_Flip(screen);
	}
	else if (etat == 3)
	{
		SDL_BlitSurface(play, NULL, screen, &positionplay);
		SDL_BlitSurface(setting, NULL, screen, &positionsetting);
		SDL_BlitSurface(credits1, NULL, screen, &positioncredits);
		SDL_BlitSurface(quit, NULL, screen, &positionquit);
		SDL_Flip(screen);
	}
}

void menu(SDL_Surface *screen, SDL_Surface *play,SDL_Surface *menu_pic, SDL_Surface *quit, SDL_Surface *settings, SDL_Surface *credits, SDL_Rect pos_play,SDL_Rect pos_menu_pic, SDL_Rect pos_quit, SDL_Rect pos_settings, SDL_Rect pos_credits)
{

	
	SDL_BlitSurface(menu_pic, NULL, screen, &pos_menu_pic);
	SDL_BlitSurface(play, NULL, screen, &pos_play);
	SDL_BlitSurface(settings, NULL, screen, &pos_settings);
	SDL_BlitSurface(quit, NULL, screen, &pos_quit);
	SDL_BlitSurface(credits, NULL, screen, &pos_credits);

	SDL_Flip(screen);
}

void text_ttf(char chaine[20], TTF_Font *police, SDL_Surface *text, SDL_Surface *screen, SDL_Rect pos_text, SDL_Color white)
{
	police = TTF_OpenFont("a.otf", 45);
	text = TTF_RenderText_Blended(police, chaine, white);
	SDL_BlitSurface(text, NULL, screen, &pos_text);

	SDL_Flip(screen);
}

void song_fct(Mix_Music *musique)
{

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	musique = Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(musique, -1);
}
void liberation ( TTF_Font *police ,SDL_Surface *screen,SDL_Surface*menu_pic ,SDL_Surface *song ,SDL_Surface *game ,SDL_Surface *mute ,SDL_Surface *full , SDL_Surface *back , SDL_Surface *text2 ,SDL_Surface *fond1 , SDL_Surface *fond2, SDL_Surface *fond3, SDL_Surface *fond4 ,SDL_Surface *text, SDL_Surface *play, SDL_Surface *quit, SDL_Surface *setting, SDL_Surface *credits, SDL_Surface *quit1, SDL_Surface *setting1, SDL_Surface *play1, SDL_Surface *credits1)
{

   TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(text);
	SDL_FreeSurface(play);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(screen);
	SDL_FreeSurface(menu_pic);
	SDL_FreeSurface(back);
	SDL_FreeSurface(full);
	SDL_FreeSurface(credits);
	SDL_FreeSurface(credits1);
	SDL_FreeSurface(mute);
	SDL_FreeSurface(song);
	SDL_FreeSurface(quit1);
	SDL_FreeSurface(play1);
	SDL_FreeSurface(setting1);
	SDL_FreeSurface(setting);
	SDL_FreeSurface(game);
	SDL_FreeSurface(text2);
	SDL_FreeSurface(fond1);
	SDL_FreeSurface(fond2);
	SDL_FreeSurface(fond3);
	SDL_FreeSurface(fond4);

    SDL_Quit();



}

void animation1 (SDL_Surface *screen,SDL_Surface *fog,SDL_Surface *m ,SDL_Surface *fond,SDL_Rect pos_fond,SDL_Rect pos_m)
{
	SDL_BlitSurface(fog, NULL, screen, &pos_m);
	 SDL_BlitSurface(fond, NULL, screen, &pos_fond);
	SDL_Flip(screen);
	SDL_Delay(60);
	SDL_BlitSurface(m, NULL, screen,&pos_m );
}