#include "hero.h"
#include "closhard.h"
#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED



typedef struct 
{
    SDL_Surface *fire;
    SDL_Rect posfire;
    SDL_Rect posfiregauche[6];
    int frame;
} fireball;

int collision_aa(SDL_Surface*screen , hero * he ,fireball * fireball);
void initfire(fireball *fireball);
void initfire2(fireball *fireball);
void setfire(fireball *fireball);
void deplacer(fireball** fireball);
void updateennemi(SDL_Surface *screen, fireball *fireball, hero *player, Clochard *ennemi, int d,int * r,int * col);

#endif 