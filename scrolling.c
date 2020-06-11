#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "scrolling.h"


void scrolling(SDL_Rect *camera, SDL_Rect *test)
{
    camera->x += 40;
    test->x += 40;
    if (camera->x >= 13000 - 1200) //si arriver a la fin(c'est tas dire la largeur final du background ki est 3837 ici )on remet la camera au debut a la position x = 0
    {
        camera->x = 11800;
    }
}

void scrollingb(SDL_Rect *camera, SDL_Rect *test)
{
    camera->x -= 40;
    test->x -= 40;
    if (camera->x <= 10) //si arriver a la fin(c'est tas dire la largeur final du background ki est 3837 ici )on remet la camera au debut a la position x = 0
    {
        camera->x = 0;
    }
}

