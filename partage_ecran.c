#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include "scrolling.h"
#include "colis.h"
#include "t.h"
#include <time.h>
#include "vie.h"
#include "score.h"
#include "enigme3.h"
#include "scrolling.h"
#include "background.h"
#include "collision.h"
#include "save.h"
#include "hero.h"
#include "closhard.h"
#include "enemy.h"
#include "enigme2.h"
#include "enig1.h"
#include "enig4.h"
#include "partage_ecran.h"

int partage(SDL_Surface *screen)
{
    hero h1, h2;

    init(&h1);
    init2(&h2);

    h1.positionhero.y = 250;
    h2.positionhero.y = 790;

    SDL_Rect pos1, pos2;
    pos1.x = 0;
    pos1.y = 0;

    pos2.x = 0;
    pos2.y = 500;

    ///

    int camsuivi;
    SDL_Rect camera, camera1;
    camera.x = 0;
    camera.y = 0;
    camera.h = 1000;
    camera.w = 1600;
    camera1.x = 0;
    camera1.y = 0;
    camera1.h = 1000;
    camera1.w = 1600;

    SDL_Color col1 = {0, 0, 0}, col2 = {255, 255, 0}, col3 = {255, 0, 0}, col4 = {0, 255, 0}, col5 = {0, 0, 255};

    SDL_Surface *a_mask = NULL, *black = NULL, *bk = NULL, *bk2 = NULL, *mask2 = NULL;

    int continuer = 1;

    clock_t debut;
    int a = 0, s = 0, s2 = 0, c = 0, g = 0, col = 0, d = 0,d2=0, colis5 = 0, arret = 0,arret2 = 0;

    int col2_res = 1, col3_res = 1, col4_res = 1, col5_res = 1;

    TTF_Font *police;
    Vie v, v2;

    Clochard cl, cl2;
    Score ss, ss2;
    fireball fi,fi2;

    initfire(&fi);
    fi.posfire.y=814;
    initfire2(&fi2);

    char questions[15];
    char reponses[15];

    strcpy(questions, "questions");
    strcpy(reponses, "reponses");

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

    initialiserScore(&ss);
    initialiserScore2(&ss2);



    v = initialiserVie();
    v2= initialiserVie2();
    a_mask = IMG_Load("mono_mask.png");
    bk = IMG_Load("mono_bk.png");
    mask2 = IMG_Load("mono_mask.png");
    bk2 = IMG_Load("mono_bk.png");
    SDL_BlitSurface(bk, &camera, screen, &pos1);
    SDL_BlitSurface(bk2, &camera1, screen, &pos2);
    SDL_Flip(screen);
    debut = initchrono(&police, &black);
    CLOCHARD_Init(&cl);
    cl.c_pos.y=250;
    CLOCHARD_Init2(&cl2);


    setright(&h1);
    setleft(&h1);

    blithero(&h1, screen, 1);

    setright2(&h2);
    setleft2(&h2);

    blithero(&h2, screen, 1);

    int time = 0;

    SDL_EnableKeyRepeat(10, 10);
    while (continuer)
    {

        d = cl.c_pos.x - h1.positionhero.x;
        d2 = cl2.c_pos.x - h2.positionhero.x;
        a = chrono(debut, screen, police, black, time);

        if (colis5 == 4)
        {
            v.valVie--;
            colis5 = 0;
        }

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {

            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    h1.directionhero = 1;
                    scrolling(&camera, &h1.testt);
                    deplacerhero(&h1);



                    cl.c_pos.x -= 20;
                    s += 30;

                    if (collision_parfaite(a_mask, h1.heroright, h1.testt, col2) == 1 && col2_res != 0)
                    {
                        col2_res = eni4(screen, &v.valVie);
                    }

                    if (collision_parfaite(a_mask, h1.heroright, h1.testt, col3) == 1 && col3_res != 0)
                    {

                        col3_res = enigme2(v.valVie, "questions", "reponses");
                    }

                    if (collision_parfaite(a_mask, h1.heroright, h1.testt, col4) == 1 && col4_res != 0)
                    {
                        col4_res = eni3(screen, &v.valVie);
                    }

                    if (collision_parfaite(a_mask, h1.heroright, h1.testt, col5) == 1 && col5_res != 0)
                    {

                        col5_res = enigme3(v.valVie);
                    }

                    if (collision_parfaite(mask2, h1.heroright, h1.testt, col1) == 1)
                    {   
                          
            
                    printf("collision \n");     
                        h1.positionhero.x -= 50;
                        h1.testt.x -= 50;
                        col++;
                    }

                    if (collision(screen, h1.positionhero, cl.c_pos, h1.positionhero.w, h1.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                    {
                        h1.positionhero.x -= 50;
                        h1.testt.x -= 50;
                        col++;
                    }
                    if (col == 3)
                    {
                        v.valVie--;
                        col = 0;
                    }

                    break;

                case SDLK_LEFT:
                    h1.directionhero = 2;
                    deplacerhero(&h1);
                    scrollingb(&camera, &h1.testt);
                    cl.c_pos.x += 20;
                    s += 30;

                    if (collision_parfaite(a_mask, h1.heroleft, h1.testt, col1) == 1)
                    {
                        h1.positionhero.x += 50;
                        h1.testt.x += 50;
                        col++;
                    }
                    if (collision(screen, h1.positionhero, cl.c_pos, h1.positionhero.w, h1.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                    {
                        h1.positionhero.x += 50;
                        h1.testt.x += 50;
                        col++;
                    }
                    if (col == 3)
                    {
                        v.valVie--;
                        col = 0;
                    }

                    break;

                case SDLK_UP:

                {
                    h1.heroisjumping = 1;

                    break;
                }

                case SDLK_d:

                    h2.directionhero = 1;
                    deplacerhero(&h2);
                    scrolling(&camera1, &h2.testt);

                    cl2.c_pos.x -= 20;
                    s2 += 30;

                    if (collision_parfaite(mask2, h2.heroright, h2.testt, col2) == 1 && col2_res != 0)
                    {
                        col2_res = eni4(screen, &v2.valVie);
                    }

                    if (collision_parfaite(mask2, h2.heroright, h2.testt, col3) == 1 && col3_res != 0)
                    {

                        col3_res = enigme2(v2.valVie, "questions", "reponses");
                    }

                    if (collision_parfaite(mask2, h2.heroright, h2.testt, col4) == 1 && col4_res != 0)
                    {
                        col4_res = eni3(screen, &v2.valVie);
                    }

                    if (collision_parfaite(mask2, h2.heroright, h2.testt, col5) == 1 && col5_res != 0)
                    {

                        col5_res = enigme3(v2.valVie);
                    }

                    if (collision_parfaite(mask2, h2.heroright, h2.testt, col1) == 1)
                    {

                        h2.positionhero.x -= 50;
                        h2.testt.x -= 50;
                        col++;
                    }

                    if (collision(screen, h2.positionhero, cl.c_pos, h2.positionhero.w, h2.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                    {
                        h2.positionhero.x -= 50;
                        h2.testt.x -= 50;
                        col++;
                    }
                    if (col == 3)
                    {
                        v2.valVie--;
                        col = 0;
                    }

                    break;

                case SDLK_q:
                    h2.directionhero = 2;
                    scrollingb(&camera1, &h2.testt);
                    cl2.c_pos.x += 20;
                    s2 += 30;

                    deplacerhero(&h2);

                    if (collision_parfaite(mask2, h2.heroleft, h2.testt, col1) == 1)
                    {
                        h2.positionhero.x += 50;
                        h2.testt.x += 50;
                        col++;
                    }
                    if (collision(screen, h2.positionhero, cl.c_pos, h2.positionhero.w, h2.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                    {
                        h2.positionhero.x += 50;
                        h2.testt.x += 50;
                        h2.positionhero.y += 100;
                        h2.testt.y += 100;
                        col++;
                    }
                    if (col == 10)
                    {
                        v2.valVie--;
                        col = 0;
                    }

                    break;

                case SDLK_z:

                {
                    h2.heroisjumping = 1;

                    if (collision(screen, h2.positionhero, cl.c_pos, h2.positionhero.w, h2.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                    {

                        col++;
                    }
                    if (col == 3)
                    {
                        v2.valVie--;
                        col = 0;
                    }
                    break;
                }
                }

                //switch

                break;

            } //switch2
            break;

        } //taskiret pollevent

        jump(&h1);
        jump(&h2);

        SDL_BlitSurface(a_mask, &camera, screen, &pos1);
        SDL_BlitSurface(bk, &camera, screen, &pos1); //top clip

        SDL_BlitSurface(mask2, &camera1, screen, &pos2);
        SDL_BlitSurface(bk2, &camera1, screen, &pos2); //bottom clip

        afficherScore(screen, &ss, s);
        afficherScore(screen, &ss2, s2);

        if (nbVie(continuer, v, screen) == 0)
            continuer = 0;

      if (nbVie(continuer, v2, screen) == 0)
            continuer = 0;

        if (arret == 0 || d < 0)
            CLOCHARD_Render(&cl, &screen); //enemy_mvt

         if (arret2 == 0 || d2 < 0)
            CLOCHARD_Render(&cl2, &screen);    

       

            blithero(&h2, screen, h2.directionhero);
            blithero(&h1, screen, h1.directionhero);

         

        updateennemi(screen, &fi, &h2, &cl, d, &arret, &colis5);
         updateennemi(screen, &fi2, &h1, &cl2, d2, &arret2, &colis5);

        SDL_Flip(screen);
    }

    SDL_FreeSurface(bk);
    SDL_FreeSurface(h1.heroright);
    SDL_FreeSurface(h1.heroleft);

    return continuer;
}