#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

clock_t initchrono(TTF_Font **police,SDL_Surface **black)
{
    clock_t debut;
    (*police) = TTF_OpenFont("a.otf", 35);
    (*black) = IMG_Load("resources/bois.png");
    debut = clock();
    return debut;
}

int chrono(clock_t debut, SDL_Surface *screen,TTF_Font *police,SDL_Surface *black,int t)
{
    clock_t fin;
    long clk_tck = CLOCKS_PER_SEC;
    int difference = 0; 
    char temps[4];
    SDL_Surface *timee;
    SDL_Rect pos_clock, pos, pos1;
    SDL_Color couleurNoire = {0, 0, 0};

    pos1.x = 50;
    pos1.y = 90;

    pos.x = 0;
    pos.y = 100;
    

    
    fin = clock();
    difference = (int)(fin - debut) / (int)clk_tck;
    sprintf(temps, "%i", difference+t);
    timee = TTF_RenderText_Blended(police, temps, couleurNoire);
    SDL_BlitSurface(black, NULL, screen, &pos);
    SDL_BlitSurface(timee, NULL, screen, &pos1);
    SDL_Flip(screen);
    return difference;
}
