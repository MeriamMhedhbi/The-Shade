/**
*@file save.h
*@author meriam mhedhbi
*@brief save
*/
#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED
 
typedef struct 
{
   SDL_Surface * menu,*yes,*no;
   SDL_Rect pos_smenu,pos_yes,pos_no;

}s_menu;

int afficher_sous_menu(SDL_Surface *screen, s_menu s, int a, char nom_fich[],int ou ,int perso,int cc,int mini,int pos_cam,int score , int nbr_vie,int time, SDL_Rect pos_perso,SDL_Rect pos_background);
s_menu init_menu();

#endif 
