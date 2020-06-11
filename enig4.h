#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

typedef struct 
{
 SDL_Surface * img;
 SDL_Rect 	p;
}enigme222;

void init_enigme2(enigme222 * e) ;
void  generate_afficher2 (SDL_Surface * screen  , char image [],enigme222 *e,int *alea) ;
 int solution_e2 (char image []) ;
int resolution2 (int * running,int *run);
void afficher_resultat2 (SDL_Surface * screen,int s,int r,enigme222 *en) ;
 int eni4(SDL_Surface *screen, int *vie);