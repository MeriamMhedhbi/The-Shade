
#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "background.h"
#include <string.h>

void init_bk(Background *b)
{
	char ch[35];
	b->position.x = 0;
	b->position.y = 0;

	b->scroll.x = 0;
	b->scroll.y = 0;
	b->scroll.w = 800;
	b->scroll.h = 600;
	b->stage = 1;
	//sprintf(ch,"map.png",b->stage);
	b->bg=IMG_Load("new real bk.png");
	
}




