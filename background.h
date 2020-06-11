#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUNG_H_INCLUDED


typedef struct
{
    SDL_Surface *bg;
    SDL_Rect position;
    SDL_Rect scroll;

    int speed;
    int stage;
} Background;
 
void init_bk(Background *b);

void afficher_bk(Background *bk, SDL_Surface *fenetre);

void scrollingbg(Background *bg, SDL_Surface *mario, SDL_Rect mario_position);

//SDL_Rect scrolling(int d, SDL_Rect camera, PERSO_PRINCIPALE pers);

#endif // STRUCT_H_INCLUDED
