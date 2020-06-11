
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include "amelioration_menu.h"

int personnage(SDL_Surface *screen)
{
    SDL_Rect pos[3], position;
    SDL_Surface *background[2], *boutons[6];
    int i, continuer = 1, perso = 0, j;
    SDL_Event event;

    background[0] = IMG_Load("choice nour.png");
    background[1] = IMG_Load("hejer choice.png");
    boutons[0] = IMG_Load("prec.png");
    boutons[1] = IMG_Load("prec copy.png");
    boutons[2] = IMG_Load("suiv.png");
    boutons[3] = IMG_Load("suiv copy.png");
    boutons[4] = IMG_Load("save.png");
    boutons[5] = IMG_Load("save copy.png");

    position.x = 580;
    position.y = 200;
    pos[0].x = 600;
    pos[0].y = 500;
    pos[1].x = 1000;
    pos[1].y = 500;
    pos[2].x = 770;
    pos[2].y = 630;

    SDL_BlitSurface(background[0], NULL, screen, &position);
    for (i = 0, j = 0; i < 3, j < 5; i++, j = j + 2)
        SDL_BlitSurface(boutons[j], NULL, screen, &pos[i]);
    SDL_Flip(screen);
    while (continuer)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEMOTION: //les bouttons
                for (i = 0, j = 0; i < 3, j < 5; i++, j = j + 2)
                {
                    if (i < 2)
                    {
                        if (event.motion.x >= pos[i].x && event.motion.x <= (pos[i].x + 108) && event.motion.y >= pos[i].y && event.motion.y <= pos[i].y + 95)
                        {
                            SDL_BlitSurface(boutons[j + 1], NULL, screen, &pos[i]);
                            SDL_Flip(screen);
                        }
                        else
                        {
                            SDL_BlitSurface(boutons[j], NULL, screen, &pos[i]);
                            SDL_Flip(screen);
                        }
                    }
                    else
                    {
                        if (event.motion.x >= pos[i].x && event.motion.x <= (pos[i].x + 195) && event.motion.y >= pos[i].y && event.motion.y <= pos[i].y + 51)
                        {
                            SDL_BlitSurface(boutons[j + 1], NULL, screen, &pos[i]);
                            SDL_Flip(screen);
                        }
                        else
                        {
                            SDL_BlitSurface(boutons[j], NULL, screen, &pos[i]);
                            SDL_Flip(screen);
                        }
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN: //les bouttons
                if (event.motion.x >= pos[0].x && event.motion.x <= (pos[0].x + 108) && event.motion.y >= pos[0].y && event.motion.y <= pos[0].y + 95)
                {
                    perso--;
                    if (perso < 0)
                        perso = 1;
                    SDL_BlitSurface(background[perso], NULL, screen, &position);
                    for (i = 0, j = 0; i < 3, j < 5; i++, j = j + 2)
                        SDL_BlitSurface(boutons[j], NULL, screen, &pos[i]);
                }
                else if (event.motion.x >= pos[1].x && event.motion.x <= (pos[1].x + 108) && event.motion.y >= pos[1].y && event.motion.y <= pos[1].y + 95)
                {
                    perso++;
                    if (perso > 1)
                        perso = 0;
                    SDL_BlitSurface(background[perso], NULL, screen, &position);
                    for (i = 0, j = 0; i < 3, j < 5; i++, j = j + 2)
                        SDL_BlitSurface(boutons[j], NULL, screen, &pos[i]);
                }
                else if (event.motion.x >= pos[2].x && event.motion.x <= (pos[2].x + 195) && event.motion.y >= pos[2].y && event.motion.y <= pos[2].y + 51)
                {
                    continuer = 0;
                }
                break;
            }
            SDL_Flip(screen);
        }
    }
    for (i = 0; i < 6; i++)
        SDL_FreeSurface(boutons[i]);
    for (i = 0; i < 2; i++)
        SDL_FreeSurface(background[i]);
    return perso;
}

int outil(SDL_Surface *screen)
{
    int ou = 7;
    SDL_Surface *menu = NULL, *c1 = NULL, *c2 = NULL, *mouse = NULL, *controller = NULL;
    SDL_Rect pos_menu, pos_c1, pos_c2, pos_mo, pos_co;

    pos_menu.x = 580;
    pos_menu.y = 240;

    pos_c1.x = 770;
    pos_c1.y = 500;

    pos_c2.x = 900;
    pos_c2.y = 500;

    pos_co.x = 750;
    pos_co.y = 550;

    pos_mo.x = 750;
    pos_mo.y = 650;

    menu = IMG_Load("Group 1.png");
    c1 = IMG_Load("1m.png");
    c2 = IMG_Load("2m.png");
    controller = IMG_Load("controller.png");
    mouse = IMG_Load("mouse.png");

    SDL_Event eve;

    while (ou == 7)
    {
        SDL_BlitSurface(menu, NULL, screen, &pos_menu);
        SDL_BlitSurface(c1, NULL, screen, &pos_c1);
        SDL_BlitSurface(c2, NULL, screen, &pos_c2);
        SDL_BlitSurface(controller, NULL, screen, &pos_co);
        SDL_BlitSurface(mouse, NULL, screen, &pos_mo);
        SDL_Flip(screen);

        while (SDL_PollEvent(&eve))
        {

            switch (eve.type)
            {

            case SDL_MOUSEMOTION:
            {
                if (eve.motion.x >= pos_c1.x && eve.motion.x <= (pos_c1.x + 40) && eve.motion.y >= pos_c1.y && eve.motion.y <= (pos_c1.y + 25))
                {
                    c1 = IMG_Load("1 copy.png");
                    c2 = IMG_Load("2m.png");
                    controller = IMG_Load("controller.png");
                    mouse = IMG_Load("mouse.png");

                    SDL_BlitSurface(c1, NULL, screen, &pos_c1);
                    SDL_BlitSurface(c2, NULL, screen, &pos_c2);
                    SDL_BlitSurface(controller, NULL, screen, &pos_co);
                    SDL_BlitSurface(mouse, NULL, screen, &pos_mo);
                }

                else if (eve.motion.x >= pos_c2.x && eve.motion.x <= (pos_c2.x + 40) && eve.motion.y >= pos_c2.y && eve.motion.y <= (pos_c2.y + 25))
                {
                    c1 = IMG_Load("1m.png");
                    c2 = IMG_Load("2 copy.png");
                    controller = IMG_Load("controller.png");
                    mouse = IMG_Load("mouse.png");

                    SDL_BlitSurface(c1, NULL, screen, &pos_c1);
                    SDL_BlitSurface(c2, NULL, screen, &pos_c2);
                    SDL_BlitSurface(controller, NULL, screen, &pos_co);
                    SDL_BlitSurface(mouse, NULL, screen, &pos_mo);
                }

                else if (eve.motion.x >= pos_co.x && eve.motion.x <= (pos_co.x + 198) && eve.motion.y >= pos_co.y && eve.motion.y <= (pos_co.y + 53))
                {
                    c1 = IMG_Load("1m.png");
                    c2 = IMG_Load("2m.png");
                    controller = IMG_Load("controller copy.png");
                    mouse = IMG_Load("mouse.png");

                    SDL_BlitSurface(c1, NULL, screen, &pos_c1);
                    SDL_BlitSurface(c2, NULL, screen, &pos_c2);
                    SDL_BlitSurface(controller, NULL, screen, &pos_co);
                    SDL_BlitSurface(mouse, NULL, screen, &pos_mo);
                }
                   else if (eve.motion.x >= pos_mo.x && eve.motion.x <= (pos_mo.x + 198) && eve.motion.y >= pos_mo.y && eve.motion.y <= (pos_mo.y + 53))
                {
                    c1 = IMG_Load("1m.png");
                    c2 = IMG_Load("2m.png");
                    controller = IMG_Load("controller.png");
                    mouse = IMG_Load("mouse copy.png");

                    SDL_BlitSurface(c1, NULL, screen, &pos_c1);
                    SDL_BlitSurface(c2, NULL, screen, &pos_c2);
                    SDL_BlitSurface(controller, NULL, screen, &pos_co);
                    SDL_BlitSurface(mouse, NULL, screen, &pos_mo);
                }
                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                if (eve.motion.x >= pos_c1.x && eve.motion.x <= (pos_c1.x + 40) && eve.motion.y >= pos_c1.y && eve.motion.y <= (pos_c1.y + 25))
                {
                    if (eve.button.button == SDL_BUTTON_LEFT)
                    {

                        ou= 0;
                    }
                }

               else if (eve.motion.x >= pos_c2.x && eve.motion.x <= (pos_c2.x + 40) && eve.motion.y >= pos_c2.y && eve.motion.y <= (pos_c2.y + 25))
                {

                    if (eve.button.button == SDL_BUTTON_LEFT)
                        ou = 1;
                }

              else if (eve.motion.x >= pos_co.x && eve.motion.x <= (pos_co.x + 198) && eve.motion.y >= pos_co.y && eve.motion.y <= (pos_co.y + 53))
                {

                    if (eve.button.button == SDL_BUTTON_LEFT)
                        ou = 2;
                }

                else if (eve.motion.x >= pos_mo.x && eve.motion.x <= (pos_mo.x + 198) && eve.motion.y >= pos_mo.y && eve.motion.y <= (pos_mo.y + 53))
                {

                    if (eve.button.button == SDL_BUTTON_LEFT)
                        ou = 3;
                }

                break;
            }

            } //switch closedo

        } //while eve
    }

    return ou;
}