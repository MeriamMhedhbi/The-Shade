#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "hero.h"
#include "scrolling.h"

void init(hero *hero)
{
	hero->heroright = NULL;
	hero->heroleft = NULL;
	hero->positionhero.x = 50;
	hero->positionhero.y = 680;
	hero->positionhero.w = 80;
	hero->positionhero.h = 200;

	hero->testt.x = 50; //scrolling de perso
	hero->testt.y = 680;
	hero->directionhero = 1;
	hero->frame = 0;
	hero->heroright = IMG_Load("right.png");
	hero->heroleft = IMG_Load("left.png");

	hero->heroisjumping = 0;
	hero->speedup = 1;
	hero->speeddown = 20;
	hero->ground = 680;
	hero->gravity = 0;

	hero->compteurmouse = 0;
	hero->mouselocation = 0;
	hero->directionmouse = 0;
}

void init2(hero *hero)
{
	hero->heroright = NULL;
	hero->heroleft = NULL;
	hero->positionhero.x = 50;
	hero->positionhero.y = 680;
	hero->positionhero.w = 80;
	hero->positionhero.h = 200;

	hero->testt.x = 50; //scrolling de perso
	hero->testt.y = 680;
	hero->directionhero = 1;
	hero->frame = 0;
	hero->heroright = IMG_Load("right1.png");
	hero->heroleft = IMG_Load("left1.png");

	hero->heroisjumping = 0;
	hero->speedup = 1;
	hero->speeddown = 20;
	hero->ground = 680;
	hero->gravity = 0;

	hero->compteurmouse = 0;
	hero->mouselocation = 0;
	hero->directionmouse = 0;
}

void mousemovement(hero *hero, SDL_Rect *camera, SDL_Rect *testt, mm *m)
{
	if (hero->mouselocation != 0)
	{
		switch (hero->directionmouse)
		{
		case 1:
		{
			if (hero->compteurmouse >= 10)
			{
				deplacerhero(hero);
				deplacementminihero(m, 1);
				scrolling(camera, testt);
				hero->compteurmouse -= 30;
			}
			if (hero->compteurmouse <= 5)
			{
				hero->mouselocation = 0;
			}
		}
		break;

		case 2:
		{
			if (hero->compteurmouse >= 10)
			{
				deplacerhero(hero);
				scrollingb(camera, testt);
				deplacementminihero(m, 2);
				hero->compteurmouse -= 30;
			}
			if (hero->compteurmouse <= 5)
			{
				hero->mouselocation = 0;
			}
		}
		break;

		} //switch
	}	  //ifmouse
} //void
void setright(hero* hero)
{
        hero->rectright[0].x = 0;
        hero->rectright[0].y = 0;
        hero->rectright[0].w = 54;
        hero->rectright[0].h = 200;

	hero->rectright[1].x = 55;
        hero->rectright[1].y = 0;
        hero->rectright[1].w = 48;
        hero->rectright[1].h = 200;

        hero->rectright[2].x = 104;
        hero->rectright[2].y = 0;
        hero->rectright[2].w = 48;
        hero->rectright[2].h = 200;


	hero->rectright[3].x = 153;
        hero->rectright[3].y = 0;
        hero->rectright[3].w = 48;
        hero->rectright[3].h = 200;

	hero->rectright[4].x = 203;
        hero->rectright[4].y = 0;
        hero->rectright[4].w = 48;
        hero->rectright[4].h = 200;
    
	hero->rectright[5].x = 252;
        hero->rectright[5].y = 0;
        hero->rectright[5].w = 48;
        hero->rectright[5].h = 200;
}


void setleft(hero* hero)
{
        hero->rectleft[0].x = 0;
        hero->rectleft[0].y = 0;
        hero->rectleft[0].w = 48;
        hero->rectright[0].h = 200;

	hero->rectleft[1].x = 49;
        hero->rectleft[1].y = 0;
        hero->rectleft[1].w = 48;
        hero->rectleft[1].h = 200;

        hero->rectleft[2].x = 99;
        hero->rectleft[2].y = 0;
        hero->rectleft[2].w = 48;
        hero->rectleft[2].h = 200;


	hero->rectleft[3].x = 148;
        hero->rectleft[3].y = 0;
        hero->rectleft[3].w = 48;
        hero->rectleft[3].h = 200;

	hero->rectleft[4].x = 197;
        hero->rectleft[4].y = 0;
        hero->rectleft[4].w = 48;
        hero->rectleft[4].h = 200;
    
	hero->rectleft[5].x = 246;
        hero->rectleft[5].y = 0;
        hero->rectleft[5].w = 54;
        hero->rectleft[5].h = 200;
}

void setright2(hero* hero)
{
    for(int i = 0; i < 6 ; i ++ )
    {
        hero->rectright[i].x = i*99;
        hero->rectright[i].y = 0;
        hero->rectright[i].w = 99;
        hero->rectright[i].h = 200;
    }
    hero->rectright[5].x = 500 ;
    hero->rectright[5].y = 0;
    hero->rectright[5].w = 99;
    hero->rectright[5].h = 200;
}


void setleft2(hero* hero)
{
    for(int i = 0; i < 6; i ++ )
    {
        hero->rectleft[i].x = 495 - i*99;
        hero->rectleft[i].y = 0;
        hero->rectleft[i].w = 99;
        hero->rectleft[i].h = 200;
    }
}


void deplacerhero(hero *hero)
{
	if (hero->frame <= 5)
	{
		hero->frame += 1;
	}

	if (hero->frame > 5)
	{
		hero->frame = 0;
	}

	//printf("%d\n",hero->frame );
	switch (hero->directionhero)
	{
	case 1:
	{
		hero->positionhero.x += 4;
		hero->testt.x += 4; ////
	}
	break;

	case 2:
	{
		hero->positionhero.x -= 4;
		hero->testt.x -= 4; ////
	}
	break;
	}
}

void blithero(hero *hero, SDL_Surface *screen, int choix)
{
	switch (choix)
	{
	case 1:
	{
		SDL_BlitSurface(hero->heroright, &(hero->rectright[hero->frame]), screen, &(hero->positionhero));
		SDL_Flip(screen);
	}
	break;
	case 2:
	{
		SDL_BlitSurface(hero->heroleft, &(hero->rectleft[hero->frame]), screen, &(hero->positionhero));
		SDL_Flip(screen);
	}
	break;
	}
	SDL_Delay(70);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////JUMP :)
//////////////////////////////////////////////////////////////////////////

void jump(hero *hero)
{
	if (hero->heroisjumping == 1)
	{
		if (hero->gravity == 0)
		{
			hero->positionhero.y -= (hero->positionhero.y / 10) + 5;
			hero->testt.y -= (hero->testt.y / 10) + 5;
			SDL_Delay(hero->speedup);
		}
		if (hero->speedup <= 10)
		{
			hero->speedup += 1;
		}

		if (hero->positionhero.y <= 300)
		{
			hero->gravity = 1;
		}
		if (hero->gravity == 1)
		{
			SDL_Delay(hero->speeddown);
			if (hero->speeddown >= 1)
			{
				hero->speeddown -= 1;
			}
			if (hero->positionhero.y >= hero->ground)
			{
				hero->positionhero.y = hero->ground;
				hero->testt.y = hero->ground;
				restart_jump(hero);
				hero->heroisjumping = 0;
			}
			if (hero->positionhero.y != hero->ground)
			{
				hero->positionhero.y += (hero->positionhero.y / 10) + 2;
				hero->testt.y += (hero->testt.y / 10) + 2;
			}
		}

	} //taskiret heroisjumping
}

void restart_jump(hero *hero)
{
	hero->speedup = 1;
	hero->gravity = 0;
	hero->speeddown = 20;
}

////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////MINI MAP/////////////////////////////////////////////

void initminimap(mm *m)
{

	m->minimap = NULL;
	m->arrow = NULL;

	m->miniheroright = NULL;
	m->miniheroleft = NULL;

	m->positionminihero.x = 610;
	m->positionminihero.y = 198;

	m->positionminimap.x = 600;
	m->positionminimap.y = 100;

	m->positionarrow.x = 612;
	m->positionarrow.y = 189;

	m->miniheroright = IMG_Load("miniheroright.png");
	m->miniheroleft = IMG_Load("miniheroleft.png");

	m->arrow = IMG_Load("miniarrow.png");
	m->minimap = IMG_Load("minimap.png");

	m->mgravite = 0;
}

void blitminimap(mm *m, SDL_Surface *screen, int choix)
{

	switch (choix)
	{

	case 1:
		SDL_BlitSurface(m->minimap, NULL, screen, &(m->positionminimap));
		SDL_BlitSurface(m->miniheroright, NULL, screen, &(m->positionminihero));
		SDL_BlitSurface(m->arrow, NULL, screen, &(m->positionarrow));

		break;

	case 2:
		SDL_BlitSurface(m->minimap, NULL, screen, &(m->positionminimap));
		SDL_BlitSurface(m->miniheroleft, NULL, screen, &(m->positionminihero));
		SDL_BlitSurface(m->arrow, NULL, screen, &(m->positionarrow));

		break;
	}
}

void miniJump(mm *m, hero *hero)
{

	if (hero->heroisjumping == 1)

	{
		if (m->mgravite == 0)
		{
			m->positionminihero.y -= (m->positionminihero.y / 33) + 5;
			m->positionarrow.y -= (m->positionarrow.y / 33) + 5;
		}

		if (m->positionminihero.y <= 135)
		{
			m->mgravite = 1;
		}

		if (m->mgravite == 1)
		{

			if (m->positionminihero.y >= 198)
			{
				m->positionminihero.y = 198;
				m->positionarrow.y = 189;

				m->mgravite = 0;
			}
			if (m->positionminihero.y != 198)
			{
				m->positionminihero.y += (m->positionminihero.y / 33) + 3;
				m->positionarrow.y += (m->positionarrow.y / 33) + 3;
			}
		}
	}
}

void deplacementminihero(mm *m, int direction)
{

	switch (direction)
	{
	case 1:
		if (m->positionminihero.x < 1100)
		{
			m->positionminihero.x += 2;
			m->positionarrow.x += 2;
		}
		break;

	case 2:

		if (m->positionminihero.x > 600)
		{
			m->positionminihero.x -= 1.5;
			m->positionarrow.x -= 1.5;
		}

		break;
	}
}
