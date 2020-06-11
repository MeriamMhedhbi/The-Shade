#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

void keyboard(int etat, SDL_Surface *screen, SDL_Surface *play, SDL_Surface *quit, SDL_Surface *setting, SDL_Surface *credits, SDL_Surface *quit1, SDL_Surface *setting1, SDL_Surface *play1, SDL_Surface *credits1, SDL_Rect positionplay, SDL_Rect positionquit, SDL_Rect positionsetting, SDL_Rect positioncredits);
void menu(SDL_Surface *screen, SDL_Surface *play,SDL_Surface *menu_pic, SDL_Surface *quit, SDL_Surface *settings, SDL_Surface *credits, SDL_Rect pos_play,SDL_Rect pos_menu_pic, SDL_Rect pos_quit, SDL_Rect pos_settings, SDL_Rect pos_credits);

void text_ttf(char chaine[20], TTF_Font *police, SDL_Surface *text, SDL_Surface *screen, SDL_Rect pos_text, SDL_Color white);
void song_fct(Mix_Music *musique); 
void liberation ( TTF_Font *police ,SDL_Surface *screen,SDL_Surface*menu_pic ,SDL_Surface *song ,SDL_Surface *game ,SDL_Surface *mute ,SDL_Surface *full , SDL_Surface *back , SDL_Surface *text2 ,SDL_Surface *fond1 , SDL_Surface *fond2, SDL_Surface *fond3, SDL_Surface *fond4 ,SDL_Surface *text, SDL_Surface *play, SDL_Surface *quit, SDL_Surface *setting, SDL_Surface *credits, SDL_Surface *quit1, SDL_Surface *setting1, SDL_Surface *play1, SDL_Surface *credits1);
void animation1 (SDL_Surface *screen,SDL_Surface *fog,SDL_Surface *m ,SDL_Surface *fond,SDL_Rect pos_fond,SDL_Rect pos_m);
#endif