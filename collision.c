#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "collision.h"

int collision(SDL_Surface *screen, SDL_Rect pos_perso, SDL_Rect pos_obj, int pw, int ph, int ow, int oh)
{
    int c = 0;

    if ((pos_perso.x + pw < pos_obj.x) || (pos_obj.x + ow < pos_perso.x) || (pos_perso.y + ph < pos_obj.y) || (pos_obj.y + oh < pos_perso.y))
        c = 0;
    else
    {
        c = 1;
    }

    return c;
}