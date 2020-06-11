/**
*@file load.h
*@author meriam mhedhbi
*@brief load
*/
#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED

typedef struct 
{
   SDL_Surface * menu,*new1,*load1,*try;
   SDL_Rect pos_smenu,pos_new,pos_load,pos_try;

}s_load;

int afficher_sous_menu1(SDL_Surface *screen, s_load s, int a );
s_load init_menu1();
#endif
