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
#include "scorefin.h"

int playing(SDL_Surface *screen, int ou, int perso, int cc, int mini, int pos_cam, int score, int nb_vie, int time, int pos_perso, int test)
{
    SDL_Rect testt;
    int camsuivi;
    SDL_Rect camera;
    camera.x = 0;
    camera.y = 0;
    camera.h = 1000;
    camera.w = 1600;

    SDL_Color col1 = {0, 0, 0}, col2 = {255, 255, 0}, col3 = {255, 0, 0}, col4 = {0, 255, 0}, col5 = {0, 0, 255};

    SDL_Surface *a_mask = NULL, *black = NULL;

    int continuer = 1;

    clock_t debut;
    int a = 0, s = 0, c = 0, g = 0, col = 0, d = 0, colis5 = 0, arret = 0, fin = 0;

    int col2_res = 1, col3_res = 1, col4_res = 1, col5_res = 1, run = 1;

    // int h = 1000, w = 1600;

    TTF_Font *police;
    s_menu sm;
    Vie v;

    Background b;
    Clochard cl, c2, c3;
    Score ss;
    fireball fi;

    initfire(&fi);

    char questions[15];
    char reponses[15];

    strcpy(questions, "questions");
    strcpy(reponses, "reponses");

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

    initialiserScore(&ss);
    v = initialiserVie();
    a_mask = IMG_Load("masknew.png");
    init_bk(&b);
    SDL_BlitSurface(b.bg, &camera, screen, &b.position);
    debut = initchrono(&police, &black);

    CLOCHARD_Init(&cl);
    

    CLOCHARD_Init3(&c2);
    

   /* CLOCHARD_Init(&c3);
    c3.sprite = IMG_Load("zied.png");
    c3.sprite2 = IMG_Load("zied.png");
    c3.c_pos.x = 9500;
    c3.c_pos.y = 710;*/

    mm m;

    initminimap(&m);
    sm = init_menu();

    hero hero;

    if (perso == 0)

    {
        init(&hero);

        setright(&hero);
        setleft(&hero);
    }

    else if (perso == 1)
    {
        init2(&hero);

        setright2(&hero);
        setleft2(&hero);
    }

    blithero(&hero, screen, 1);
    blitminimap(&m, screen, 1);

    s = score;
    v.valVie = nb_vie;
    a = time;
    hero.positionhero.x = pos_perso;
    hero.testt.x = test;
    camera.x = pos_cam;
    m.positionarrow.x = mini;
    m.positionminihero.x = mini;
    cl.c_pos.x = cc;

    SDL_EnableKeyRepeat(10, 10);
    while (continuer)
    {

        d = cl.c_pos.x - hero.positionhero.x;
        a = chrono(debut, screen, police, black, time);

        //printf("col 5 egale %d",colis5);
        if (colis5 == 4)
        {
            v.valVie--;
            colis5 = 0;
        }
        if (hero.testt.x == 12086)
            continuer = 0;

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_MOUSEBUTTONDOWN:

                if (ou == 3)
                {
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {

                        hero.mouselocation = event.button.x;

                        if (hero.mouselocation >= hero.positionhero.x + 10)
                        {
                            cl.c_pos.x -= 20;
                            s += 30;
                            hero.directionhero = 1;
                            hero.compteurmouse = 0;
                            hero.directionmouse = 1;
                            hero.compteurmouse = hero.mouselocation - hero.positionhero.x - 10;
                        }
                        else if (hero.mouselocation < hero.positionhero.x)
                        {
                            cl.c_pos.x += 20;
                            s += 30;
                            hero.directionhero = 2;
                            hero.compteurmouse = 0;
                            hero.directionmouse = 2;
                            hero.compteurmouse = hero.positionhero.x - hero.mouselocation;
                        }
                    }
                }

                break;
            }

            switch (event.type)
            {

            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {

                case SDLK_ESCAPE:

                    continuer = afficher_sous_menu(screen, sm, continuer, "save.txt", ou, perso, cl.c_pos.x, m.positionminihero.x, camera.x, s, v.valVie, a, hero.positionhero, hero.testt);
                    break;
                }

                if (ou == 0)
                {
                    switch (event.key.keysym.sym)
                    {

                    case SDLK_RIGHT:
                        hero.directionhero = 1;
                        scrolling(&camera, &hero.testt);

                        cl.c_pos.x -= 20;
                       c2.c_pos.x-=20;
                       // c3.c_pos.x-=20;
                        s += 30;
                        deplacerhero(&hero);
                        deplacementminihero(&m, 1);

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col2) == 1 && col2_res != 0)
                        {
                            col2_res = eni4(screen, &v.valVie);
                        }

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col3) == 1 && col3_res != 0)
                        {

                            col3_res = enigme2(v.valVie, "questions", "reponses");
                        }

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col4) == 1 && col4_res != 0)
                        {
                            col4_res = eni3(screen, &v.valVie);
                        }

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col5) == 1 && col5_res != 0)
                        {

                            col5_res = enigme3(v.valVie);
                        }

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col1) == 1)
                        {

                            hero.positionhero.x -= 50;
                            hero.testt.x -= 50;
                            col++;
                        }

                        if (collision(screen, hero.positionhero, cl.c_pos, hero.positionhero.w, hero.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                        {
                            hero.positionhero.x -= 50;
                            hero.testt.x -= 50;
                            col++;
                        }
                        if (collision(screen, hero.positionhero, c3.c_pos, hero.positionhero.w, hero.positionhero.h, c3.c_pos.w, c3.c_pos.h) == 1)
                        {
                            hero.positionhero.x -= 50;
                            hero.testt.x -= 50;
                            col++;
                        }

                        if (collision(screen, hero.positionhero, c2.c_pos, hero.positionhero.w, hero.positionhero.h, c2.c_pos.w, c2.c_pos.h) == 1)
                        {
                            hero.positionhero.x -= 50;
                            hero.testt.x -= 50;
                            col++;
                        }

                        if (col == 3)
                        {
                            v.valVie--;
                            col = 0;
                        }

                        break;

                    case SDLK_LEFT:
                        hero.directionhero = 2;
                        scrollingb(&camera, &hero.testt);
                        s += 30;

                        deplacerhero(&hero);

                        deplacementminihero(&m, 2);

                        if (collision_parfaite(a_mask, hero.heroleft, hero.testt, col1) == 1)
                        {
                            hero.positionhero.x += 50;
                            hero.testt.x += 50;
                            col++;
                        }
                        if (collision(screen, hero.positionhero, cl.c_pos, hero.positionhero.w, hero.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                        {
                            hero.positionhero.x += 50;
                            hero.testt.x += 50;
                            col++;
                        }
                        if (collision(screen, hero.positionhero, c2.c_pos, hero.positionhero.w, hero.positionhero.h, c2.c_pos.w, c2.c_pos.h) == 1)

                        {
                            hero.positionhero.x += 50;
                            hero.testt.x += 50;
                            col++;
                        }
                        if (collision(screen, hero.positionhero, c3.c_pos, hero.positionhero.w, hero.positionhero.h, c3.c_pos.w, c3.c_pos.h) == 1)

                        {
                            hero.positionhero.x += 50;
                            hero.testt.x += 50;
                            col++;
                        }
                        if (col == 3)
                        {
                            v.valVie--;
                            col = 0;
                        }

                        break;

                    case SDLK_UP:
                        hero.heroisjumping = 1;

                        break;
                    }
                }

                if (ou == 1)
                {
                    switch (event.key.keysym.sym)
                    {

                    case SDLK_d:
                        hero.directionhero = 1;
                        scrolling(&camera, &hero.testt);

                        cl.c_pos.x -= 20;
                        s += 30;
                        deplacerhero(&hero);
                        deplacementminihero(&m, 1);

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col2) == 1 && col2_res != 0)
                        {
                            col2_res = eni4(screen, &v.valVie);
                        }

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col3) == 1 && col3_res != 0)
                        {

                            col3_res = enigme2(v.valVie, "questions", "reponses");
                        }

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col4) == 1 && col4_res != 0)
                        {
                            col4_res = eni3(screen, &v.valVie);
                        }

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col5) == 1 && col5_res != 0)
                        {

                            col5_res = enigme3(v.valVie);
                        }

                        if (collision_parfaite(a_mask, hero.heroright, hero.testt, col1) == 1)
                        {

                            hero.positionhero.x -= 50;
                            hero.testt.x -= 50;
                            col++;
                        }

                        if (collision(screen, hero.positionhero, cl.c_pos, hero.positionhero.w, hero.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                        {
                            hero.positionhero.x -= 50;
                            hero.testt.x -= 50;
                            col++;
                        }
                          if (collision(screen, hero.positionhero, c3.c_pos, hero.positionhero.w, hero.positionhero.h, c3.c_pos.w, c3.c_pos.h) == 1)
                        {
                            hero.positionhero.x -= 50;
                            hero.testt.x -= 50;
                            col++;
                        }

                        if (collision(screen, hero.positionhero, c2.c_pos, hero.positionhero.w, hero.positionhero.h, c2.c_pos.w, c2.c_pos.h) == 1)
                        {
                            hero.positionhero.x -= 50;
                            hero.testt.x -= 50;
                            col++;
                        }
                        if (col == 3)
                        {
                            v.valVie--;
                            col = 0;
                        }

                        break;

                    case SDLK_q:
                        hero.directionhero = 2;
                        scrollingb(&camera, &hero.testt);
                        s += 30;

                        deplacerhero(&hero);

                        deplacementminihero(&m, 2);

                        if (collision_parfaite(a_mask, hero.heroleft, hero.testt, col1) == 1)
                        {
                            hero.positionhero.x += 50;
                            hero.testt.x += 50;
                            
                            col++;
                        }
                        if (collision(screen, hero.positionhero, cl.c_pos, hero.positionhero.w, hero.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                        {
                            hero.positionhero.x += 50;
                            hero.testt.x += 50;
                            hero.positionhero.y += 100;
                            hero.testt.y += 100;
                            col++;
                        }
                          if (collision(screen, hero.positionhero, c2.c_pos, hero.positionhero.w, hero.positionhero.h, c2.c_pos.w, c2.c_pos.h) == 1)

                        {
                             hero.positionhero.x += 50;
                            hero.testt.x += 50;
                            hero.positionhero.y += 100;
                            hero.testt.y += 100;
                            col++;
                        }
                        if (collision(screen, hero.positionhero, c3.c_pos, hero.positionhero.w, hero.positionhero.h, c3.c_pos.w, c3.c_pos.h) == 1)

                        {
                            hero.positionhero.x += 50;
                            hero.testt.x += 50;
                            col++;
                        }
                        if (col == 10)
                        {
                            v.valVie--;
                            col = 0;
                        }

                        break;

                    case SDLK_z:

                    {
                        hero.heroisjumping = 1;

                        if (collision(screen, hero.positionhero, cl.c_pos, hero.positionhero.w, hero.positionhero.h, cl.c_pos.w, cl.c_pos.h) == 1)

                        {

                            col++;
                        }
                        if (col == 3)
                        {
                            v.valVie--;
                            col = 0;
                        }
                        break;
                    }
                    }
                }
                //switch

                break;

            } //switch2
            break;

        } //taskiret pollevent
          // printf("%d // \n",hero.positionhero.x);

        jump(&hero);
        miniJump(&m, &hero);

        SDL_BlitSurface(a_mask, &camera, screen, &b.position);
        SDL_BlitSurface(b.bg, &camera, screen, &b.position);

        afficherScore(screen, &ss, s);

        if (nbVie(continuer, v, screen) == 0 )

        {
            run = 1;
            while (run)
            {

                SDL_Event event2;
                while (SDL_PollEvent(&event2))
                {
                    scorefin(screen, s, a);
                    switch (event2.type)
                    {
                    case SDL_QUIT:
                        run = 0;
                         continuer = 0;
                        break;
                    }
                    
                }
            }
        }


        CLOCHARD_Render(&c2, &screen);
       // printf("%d\n",c2.c_pos.x);

        if (arret == 0 || d < 0)
            CLOCHARD_Render(&cl, &screen); //enemy_mvt

       // CLOCHARD_Render(&c3, &screen);

        mousemovement(&hero, &camera, &testt, &m);

        blitminimap(&m, screen, hero.directionhero);
        blithero(&hero, screen, hero.directionhero);

        updateennemi(screen, &fi, &hero, &cl, d, &arret, &colis5);

        SDL_Flip(screen);
    }

    SDL_FreeSurface(b.bg);
    SDL_FreeSurface(hero.heroright);
    SDL_FreeSurface(hero.heroleft);

    return continuer;
}
