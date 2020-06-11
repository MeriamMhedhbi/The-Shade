
#ifndef CLOSHARD_H_INCLUDED
#define CLOSHARD_H_INCLUDED



typedef struct Clochard 
{
       
	SDL_Surface *sprite,*sprite2;
	SDL_Rect c_pos;                      
	int dx,cx,etat;
} Clochard;        

void CLOCHARD_Init(Clochard *c);
void CLOCHARD_Init2(Clochard *c);
void CLOCHARD_Init3(Clochard *c);
void CLOCHARD_Render(Clochard *c, SDL_Surface **screen);


#endif 


