#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <SDL/SDL_mixer.h>



int main()
{
	int vie=3,res;
	
	char questions[15];
	char reponses[15];

	strcpy(questions,"questions");
	strcpy(reponses,"reponses");
	
	enigme2(vie,questions,reponses);
}
