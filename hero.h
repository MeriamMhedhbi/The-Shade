#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

struct hero
{
	SDL_Surface *heroright;
	SDL_Surface *heroleft;
	SDL_Rect positionhero ,testt;//// 
	SDL_Rect rectright[6],rectleft[6];
	int directionhero; 
	int frame;
	int partage ;
		///JUMP

 
	int speedup,speeddown,gravity,ground,heroisjumping;
	
	int mouselocation,directionmouse,compteurmouse;
	
};
typedef struct hero hero; 

void init(hero* hero);
void init2(hero* hero);
void setright(hero* hero); 
void setleft(hero* hero);
void setright2(hero* hero); 
void setleft2(hero* hero);
void deplacerhero(hero* hero);
void blithero (hero* hero,SDL_Surface* screen,int choix);





void jump (hero* hero);
void restart_jump ( hero* hero );


struct minimap
{
	SDL_Surface *minimap,*miniheroright,*miniheroleft,*arrow;
	SDL_Rect positionminihero,positionminimap,positionarrow;
	int mgravite;
	 
};

typedef struct minimap mm;

void mousemovement (hero* hero,SDL_Rect* camera,SDL_Rect* testt,mm *m);
void initminimap (mm *m);
void blitminimap (mm *m,SDL_Surface* screen,int choix);
void deplacementminihero (mm *m,int direction);
int playing(SDL_Surface *screen,int ou,int perso,int cc,int mini,int pos_cam,int score ,int nb_vie,int time,int pos_perso,int test) ;

void miniJump (mm *m,hero *hero);

#endif // HERO_H_INCLUDED
