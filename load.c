#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include "load.h"
#include <string.h>


s_load init_menu1()
{
 s_load l;

 l.load1=IMG_Load("load.png");
 l.new1=IMG_Load("new.png");
 l.menu=IMG_Load("load_bg.png");
 l.try=IMG_Load ("bois.png");   
 
 l.pos_load.x= 700;
 l.pos_load.y=403;

 l.pos_new.x=700;
 l.pos_new.y=535;

 l.pos_smenu.x=600;
 l.pos_smenu.y=300;

 l.pos_try.x=0;
 l.pos_try.y=0;

 return l;

}



int afficher_sous_menu1(SDL_Surface *screen, s_load s, int a )
{
    SDL_Event eve;
   

    while (a == 1)
    {
        SDL_BlitSurface(s.menu, NULL, screen, &s.pos_smenu);
        SDL_BlitSurface(s.load1, NULL, screen, &s.pos_load);
        SDL_BlitSurface(s.try, NULL, screen, &s.pos_try);
        SDL_BlitSurface(s.new1, NULL, screen, &s.pos_new);
          SDL_Flip(screen);
        
        while (SDL_PollEvent(&eve))
        {

            switch (eve.type)
            {

            case SDL_MOUSEMOTION:
            {
                if (eve.motion.x >= s.pos_load.x && eve.motion.x <= (s.pos_load.x + 136) && eve.motion.y >= s.pos_load.y && eve.motion.y <= (s.pos_load.y + 96))
                {
                     s.load1 = IMG_Load("load copy.png");
                     s.new1 = IMG_Load("new.png");
                    SDL_BlitSurface(s.load1, NULL, screen, &s.pos_load);
                    SDL_BlitSurface(s.new1, NULL, screen, &s.pos_new);

                } 
       
        if (eve.motion.x >= s.pos_new.x && eve.motion.x <= (s.pos_new.x + 136) && eve.motion.y >= s.pos_new.y && eve.motion.y <= (s.pos_new.y + 96))
                {   
                     s.load1 = IMG_Load("load.png");
                      s.new1 = IMG_Load("new copy.png");
                    SDL_BlitSurface(s.load1, NULL, screen, &s.pos_load);
                    SDL_BlitSurface(s.new1, NULL, screen, &s.pos_new);

                 
                }
                break; 
            } 
            case SDL_MOUSEBUTTONDOWN:
            {
                if (eve.motion.x >= s.pos_load.x && eve.motion.x <= (s.pos_load.x + 136) && eve.motion.y >= s.pos_load.y && eve.motion.y <= (s.pos_load.y + 96))
                {
                    if (eve.button.button == SDL_BUTTON_LEFT)
                    {
                     
                        a = 2;
                    }
                }

             else if (eve.motion.x >= s.pos_new.x && eve.motion.x <= (s.pos_new.x + 136) && eve.motion.y >= s.pos_new.y && eve.motion.y <= (s.pos_new.y + 96))
                {

                    if (eve.button.button == SDL_BUTTON_LEFT)
                        a = 0;
                }
                 else if (eve.motion.x >= s.pos_try.x && eve.motion.x <= (s.pos_try.x + 248) && eve.motion.y >= s.pos_try.y && eve.motion.y <= (s.pos_try.y + 92))
                {

                    if (eve.button.button == SDL_BUTTON_LEFT)
                        a = 3;
                }

                break;
            }

            } //switch closedo

        } //while eve

    } //while a
return a;
} //funct