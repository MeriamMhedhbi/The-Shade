#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "colis.h"



SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y)
{
    SDL_Color color;
    Uint32 col = 0;
    //Determine position
    char *pPosition = (char *)pSurface->pixels;
    pPosition += (pSurface->pitch * y); 
    pPosition += (pSurface->format->BytesPerPixel * x);
    memcpy(&col, pPosition, pSurface->format->BytesPerPixel);
    //convertir color
    SDL_GetRGB(col, pSurface->format, &color.r, &color.g, &color.b);
    return (color);
}

int collision_parfaite(SDL_Surface *surfM, SDL_Surface *mario, SDL_Rect pos_mario,SDL_Color co)
{
    SDL_Color col;
    SDL_Rect pos[8];
    int collision = 0;
    int i,w,h;
    col.r = 0;
    col.g = 0; 
    col.b = 0;
   

    w = 80; 
    h = 200;

   
    pos[0].x = pos_mario.x;
    pos[0].y = pos_mario.y; /*gauche_sup*/
    pos[1].x = pos_mario.x;
    pos[1].y = pos_mario.y + h / 2; /*gauche*/
    pos[2].x = pos_mario.x;
    pos[2].y = pos_mario.y + h; /*gauche_inf*/
    pos[3].x = pos_mario.x + w / 2;
    pos[3].y = pos_mario.y; /*top_milieu*/
    pos[4].x = pos_mario.x + w / 2;
    pos[4].y = pos_mario.y +h; /*bottom_milieu*/
    pos[5].x = pos_mario.x + w;
    pos[5].y = pos_mario.y; /*droite_sup*/
    pos[6].x = pos_mario.x + w;
    pos[6].y = pos_mario.y + h / 2; /*droite*/
    pos[7].x = pos_mario.x + w;
    pos[7].y = pos_mario.y + h; /*droite_inf*/

    for (i = 0; (i < 8) && (collision == 0); i++)
    {
        col = GetPixel(surfM, pos[i].x, pos[i].y);
        
        if ((col.r ==co.r) && (col.g == co.g) && (col.b == co.b))
            collision = 1;
    }
    return (collision);
}
