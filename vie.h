#ifndef VIE_H_INCLUDED
#define VIE_H_INCLUDED



//********* HEAD vie *******

typedef struct Vie
{
	SDL_Surface* vie_img1;
	SDL_Surface* vie_img2;
	SDL_Surface* vie_img3;
	SDL_Surface* vie_img4; 
	SDL_Rect posVie;
	int valVie;	
}Vie;

Vie initialiserVie();
Vie initialiserVie2();
int nbVie(int gameOver ,Vie vie, SDL_Surface *screen);

#endif
