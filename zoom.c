/**
* @file zoom.c
* @brief fichier.c de la fonction rotozoom
* @author Druids Chkiwa NourELhak 1A3
* @version 1.0
* @date june 2020
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
 
 

#define TEMPS       30 // Le temps qu'il y a entre chaque augmentation de l'angle.

 
/**
* @brief faire le rotozoom 
* @param screen SDL_Surface
* @return nothing
*/
void rotozoom(SDL_Surface *screen)

{    

    SDL_Surface *rotation = NULL , *image= NULL;/*image a retozoomer */

    SDL_Rect rect;

    SDL_Event event;

    double angle = 0;

    double zoom = 1;

    int sens = 1;
    rect.x=0;
    rect.y=0;
 

    int continuer = 1;

    int tempsPrecedent = 0, tempsActuel = 0;


    image = IMG_Load("menu pic.png");/*upload the image a retozoomer here*/

 

    while(continuer)

    {


        SDL_PollEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;

        }

 

        tempsActuel = SDL_GetTicks();

        if (tempsActuel - tempsPrecedent > TEMPS)

        {

            angle += 2; //On augmente l'angle pour que l'image tourne sur elle-même.

 

            tempsPrecedent = tempsActuel;

        }

        else

        {

            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));

        }

 

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

 

        rotation = rotozoomSurface(image, angle, zoom, 0); //On transforme la surface image.

        
        
        //On repositionne l'image en fonction de sa taille.

       rect.x =  event.button.x - rotation->w / 2;

        rect.y =  event.button.y - rotation->h / 2;

        //  rect.x =   rotation->w / 2;

        //rect.y =   rotation->h / 2;

        SDL_BlitSurface(rotation , NULL, screen, &rect); //On affiche la rotation de la surface image.

        SDL_FreeSurface(rotation); //On efface la surface rotation car on va la redéfinir dans la prochaine boucle. Si on ne le fait pas, cela crée une fuite de mémoire. 

 

        if(zoom >= 2){sens = 0;}

        else if(zoom <= 0.5){sens = 1;}

 

        if(sens == 0){zoom -= 0.02;}

        else{zoom += 0.02;}

 

        SDL_Flip(screen);

    }

   

}
