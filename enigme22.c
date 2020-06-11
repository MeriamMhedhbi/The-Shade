#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include "enigme2.h"

int resultatenigme2(char reponses[], char rep[], int nb)
{
    int j;
    char rep1;
    char ch[10];
    FILE *preponses = NULL;
    preponses = fopen(reponses, "r");

    rep1 = rep[0] - 32;

    if (preponses == NULL)
    {
        printf("Error fopen reponses\n");
    }
    else
    {

        for (j = 1; j <= 3; j++)
        {
            fscanf(preponses, "%s", ch);

            if (j == nb)
            {
                if ((nb != 1) && (ch[0] == rep1))
                    return 1;
                else if (strcmp(ch, rep) == 0)
                    return 1;
                else
                    return 0;
            }
        }
    }
    fclose(preponses);
}

int enigme2(int vie, char questions[], char reponses[])
{
    TTF_Font *police = NULL;
    SDL_Color couleurnoir = {255, 255, 255};
    SDL_Surface *texte = NULL,*text=NULL;
    SDL_Rect pos, pos2, pos3;
    SDL_Surface *image;
    SDL_Surface *screen;
    screen = SDL_SetVideoMode(1600, 1000, 32, SDL_HWSURFACE);
    pos.x = 10;
    pos.y = 10;
    pos2.x = 10;
    pos2.y = 300;
    pos3.x = 10;
    pos3.y = 400;
    int taille = 100, i, nb;
    FILE *pquestions = NULL;
    char qs[100];
    char rep[10]; 
    image = IMG_Load("menu pic.png");
    pquestions = fopen(questions, "r");

    if (pquestions == NULL)
    {
        printf("Error fopen questions\n");
    }
    else
    {

        do
        {

            nb = ((rand() % 2) + 1);
            rewind(pquestions);

            for (i = 1; i <= 3; i++)
            {

                fgets(qs, taille, pquestions);
                if (nb == i)
                {
                    police = TTF_OpenFont("a.otf", 30);
                    texte = TTF_RenderText_Blended(police, qs, couleurnoir);
                    printf("%s", qs);
                     SDL_BlitSurface(image, NULL, screen, &pos);
                    SDL_BlitSurface(texte, NULL, screen, &pos2);

                    SDL_Flip(screen);

                    police = TTF_OpenFont("a.otf", 30);
                    text = TTF_RenderText_Blended(police, "Votre reponse ?", couleurnoir);
                    printf("Votre reponse ? ");
                    SDL_BlitSurface(text, NULL, screen, &pos3);

                    SDL_Flip(screen);

                    scanf("%s", rep);
                    printf("\n");

                    if (strcmp(rep, "**") == 0)
                    {
                        police = TTF_OpenFont("a.otf", 30);
                        texte = TTF_RenderText_Blended(police, "Vous avez quitte", couleurnoir);
                        printf("Vous avez quitte \n");
                        SDL_BlitSurface(image, NULL, screen, &pos);
                        SDL_BlitSurface(texte, NULL, screen, &pos);

                        SDL_Flip(screen);

                        return 0;
                    }
                    else if (resultatenigme2(reponses, rep, nb) == 1)
                    {
                        police = TTF_OpenFont("a.otf", 30);
                        texte = TTF_RenderText_Blended(police, "Votre reponse est correcte", couleurnoir);
                        printf("Correct\n");
                        SDL_BlitSurface(image, NULL, screen, &pos);
                        SDL_BlitSurface(texte, NULL, screen, &pos3);
                        SDL_Flip(screen);

                        return 0;
                    }
                    else
                    {
                        police = TTF_OpenFont("a.otf", 30);
                        texte = TTF_RenderText_Blended(police, "Votre reponse est incorrecte", couleurnoir);
                        printf("Votre reponse est incorrecte\n");
                        SDL_BlitSurface(image, NULL, screen, &pos);
                        SDL_BlitSurface(texte, NULL, screen, &pos3);
                        SDL_Delay(50);
                        SDL_Flip(screen);

                        i = 4;
                        vie--;
                        printf("%d",vie);
                    }
                }
            }
        } while (vie > 0);
    }
    fclose(pquestions);
    police = TTF_OpenFont("a.otf", 30);
    texte = TTF_RenderText_Blended(police, "Vous avez perdu", couleurnoir);
    printf("Vie=0");
     
   
    SDL_BlitSurface(image, NULL, screen, &pos);
    SDL_BlitSurface(texte, NULL, screen, &pos);

    SDL_Flip(screen);

    return 0;
}

/*int main()
{

    int res=enigme2(3,"questions.txt","reponses.txt");
    return 0;
}*/
