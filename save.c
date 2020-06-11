#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include "save.h"
#include <string.h>
//menu save 
    
s_menu init_menu()
{
    s_menu s;

    s.pos_smenu.x = 600;
    s.pos_smenu.y = 400;

    s.pos_yes.x = 650;
    s.pos_yes.y = 550;

    s.pos_no.x = 850;
    s.pos_no.y = 550;
 
    s.menu = IMG_Load("sous_menu.png");
    s.yes = IMG_Load("yes.png");
    s.no = IMG_Load("no.png");
    

    return s;
}

int afficher_sous_menu(SDL_Surface *screen, s_menu s, int a, char nom_fich[],int ou,int perso,int cc,int mini ,int pos_cam,int score , int nbr_vie,int time, SDL_Rect pos_perso,SDL_Rect pos_background)
{
    SDL_Event eve;
    FILE *f = NULL;

    while (a == 1)
    {
        SDL_BlitSurface(s.menu, NULL, screen, &s.pos_smenu);
        SDL_BlitSurface(s.yes, NULL, screen, &s.pos_yes);
        SDL_BlitSurface(s.no, NULL, screen, &s.pos_no);
          SDL_Flip(screen);
        
        while (SDL_PollEvent(&eve))
        {

            switch (eve.type)
            {

            case SDL_MOUSEMOTION:
            {
                if (eve.motion.x >= s.pos_yes.x && eve.motion.x <= (s.pos_yes.x + 136) && eve.motion.y >= s.pos_yes.y && eve.motion.y <= (s.pos_yes.y + 96))
                {
                     s.yes = IMG_Load("yes copy.png");
                     s.no = IMG_Load("no.png");
                    SDL_BlitSurface(s.yes, NULL, screen, &s.pos_yes);
                    SDL_BlitSurface(s.no, NULL, screen, &s.pos_no);

                } 
       
        if (eve.motion.x >= s.pos_no.x && eve.motion.x <= (s.pos_no.x + 136) && eve.motion.y >= s.pos_no.y && eve.motion.y <= (s.pos_no.y + 96))
                {   
                     s.yes = IMG_Load("yes.png");
                      s.no = IMG_Load("no copy.png");
                    SDL_BlitSurface(s.yes, NULL, screen, &s.pos_yes);
                    SDL_BlitSurface(s.no, NULL, screen, &s.pos_no);

                 
                }
                break; 
            } 
            case SDL_MOUSEBUTTONDOWN:
            {
                if (eve.motion.x >= s.pos_yes.x && eve.motion.x <= (s.pos_yes.x + 136) && eve.motion.y >= s.pos_yes.y && eve.motion.y <= (s.pos_yes.y + 96))
                {
                    if (eve.button.button == SDL_BUTTON_LEFT)
                    {
                        f = fopen(nom_fich, "w");
                        if (f != NULL)
                        {
                            fprintf(f, "%d %d %d %d %d %d %d %d %d %d ",ou,perso,cc, mini,pos_cam,score, nbr_vie, time, pos_perso.x, pos_background.x);

                           
                        }
                     fclose(f);
                        a = 0;
                    }
                }

             else if (eve.motion.x >= s.pos_no.x && eve.motion.x <= (s.pos_no.x + 136) && eve.motion.y >= s.pos_no.y && eve.motion.y <= (s.pos_no.y + 96))
                {

                    if (eve.button.button == SDL_BUTTON_LEFT)
                        a = 0;
                }

                break;
            }

            } //switch closedo

        } //while eve

    } //while a
return a;
} //funct


//////////////////////////nouvelle partie //////////

