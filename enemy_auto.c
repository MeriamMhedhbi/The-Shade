#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "closhard.h"
#include "hero.h"
#include "enemy.h"
#include "collision.h"

void initfire(fireball *fireball)
{
    fireball->fire = NULL;
    fireball->posfire.x = 500;
    fireball->posfire.y = 700;
    fireball->posfire.w=43;
    fireball->posfire.h=60;
    fireball->frame = 0;
    fireball->fire = IMG_Load("fire.png");
}
void initfire2(fireball *fireball)
{
    fireball->fire = NULL;
    fireball->posfire.x = 500;
    fireball->posfire.y = 258;
    fireball->posfire.w=43;
    fireball->posfire.h=60;
    fireball->frame = 0;
    fireball->fire = IMG_Load("fire.png");
}

void setfire(fireball *fireball)
{
    for (int i = 0; i < 6; i++) 
    {
        fireball->posfiregauche[i].x = 255 - i * 43;
        fireball->posfiregauche[i].y = 0;
        fireball->posfiregauche[i].w = 43;
        fireball->posfiregauche[i].h = 59;
    }
}

void deplacer(fireball **fireball)
{  
    
    if ((*fireball)->frame <= 5)
    {
        (*fireball)->frame += 1;
    }

    if ((*fireball)->frame > 5)
    {
        (*fireball)->frame = 0;
    }
    (*fireball)->posfire.x -= 10;
}

void blitfire(fireball *fireball, SDL_Surface *screen)
{
    SDL_BlitSurface(fireball->fire, &(fireball->posfiregauche[fireball->frame]), screen, &(fireball->posfire));
    SDL_Flip(screen);
    SDL_Delay(50);
}

/*void afficherennemi(Clochard *c, SDL_Surface *screen)
{
    SDL_BlitSurface(c->sprite, NULL, screen, &c->c_pos);
    SDL_Flip(screen);
}*/

int collision_aa(SDL_Surface *screen, hero *he, fireball *fireball)
{
    int c = 0;

    if ((he->positionhero.x + 80== fireball->posfire.x) && (he->positionhero.y +200 == fireball->posfire.y))
        c = 1;
    else
    {
        c = 0;
    }

    return c;
}

void updateennemi(SDL_Surface *screen, fireball *fireball, hero *player, Clochard *ennemi, int d, int * r,int *col5)
{
    int c = 0;
      //fireball->posfire=ennemi->c_pos ;

    if (d < 600 && d > 400) // following 
    {
        (*r) = 1;
        ennemi->c_pos.x = ennemi->c_pos.x - 10;
        SDL_BlitSurface(ennemi->sprite, NULL, screen, &ennemi->c_pos);
        SDL_Flip(screen);
    }

    else if (d <= 400 && d > 285) //following+acceleration 
    {
        ennemi->c_pos.x = ennemi->c_pos.x - 20;
        SDL_BlitSurface(ennemi->sprite, NULL, screen, &ennemi->c_pos);
        SDL_Flip(screen);
    }

    else if (d <= 285 && d > 0) //attacking
    { 
          SDL_BlitSurface(ennemi->sprite, NULL, screen, &ennemi->c_pos);
        setfire(fireball);
         blitfire(fireball, screen);
        deplacer(&fireball);
       
       
       c=collision(screen,player->positionhero, fireball->posfire, player->positionhero.w, player->positionhero.h, fireball->posfire.w, fireball->posfire.h);
       
       
        if (c == 1)
        {
            (*col5)++;
            printf("col est %d",(*col5));
        }


    }
    
     
}
