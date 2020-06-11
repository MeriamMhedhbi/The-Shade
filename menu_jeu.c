#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_rotozoom.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>
#include "hero.h"
#include "load.h"
#include "amelioration_menu.h"
#include "z.h" 
#include "partage_ecran.h"


int main(int argc, char *argv[])
{

	SDL_Surface *screen = NULL, *menu_s = NULL, *menu_pic = NULL, *m = NULL, *song = NULL, *game = NULL, *fog = NULL, *rain, *mute = NULL, *full = NULL, *back = NULL, *text2 = NULL, *fond1 = NULL, *fond2 = NULL, *fond3 = NULL, *fond4 = NULL, *play = NULL, *settings = NULL, *quit = NULL, *text = NULL, *credits = NULL, *play2 = NULL, *credits2 = NULL, *settings2 = NULL, *quit2 = NULL;
	SDL_Rect pos_play, pos_text2, pos_m, pos_ms,pos_text1, pos_fond1, pos_fond2, pos_fond3, pos_fond4, pos_menu_pic, pos_song, pos_mute, pos_full, pos_settings, pos_quit, pos_fond, pos_text, pos_credits, pos_back, pos_game;
	TTF_Font *police = NULL;
	SDL_Color white = {255, 255, 255};
	Mix_Music *musique;
	SDL_Event event, event2;
	Mix_Chunk *bref = NULL;
	char ch1[20], ch2[20], ch3[70];

	int done = 1, v = MIX_MAX_VOLUME / 2, next = 0, screen_state = 1, etat = -1, temp = 1,perso=5,ou=7,z=1;
	int score1=0, nbr_vie1=0, time1=0, pos_perso_x=0, pos1=0,pos_cam=0,mini=610,cc=1700;

	s_load ll;

	pos_menu_pic.x = 0; 
	pos_menu_pic.y = 0;

	pos_m.x = 573;
	pos_m.y = 0;

	pos_game.x = 0;
	pos_game.y = 0;

	pos_back.x = 0;
	pos_back.y = 0;

	pos_text.x = 0;
	pos_text.y = 0;

	pos_text1.x = 650;
	pos_text1.y = 350;

	pos_fond1.x = 725;
	pos_fond1.y = 380;

	pos_fond2.x = 708;
	pos_fond2.y = 483;

	pos_fond3.x = 824;
	pos_fond3.y = 338;

	pos_fond4.x = 1191;
	pos_fond4.y = 248;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	screen = SDL_SetVideoMode(1600, 1000, 32, SDL_HWSURFACE);

	fond1 = IMG_Load("doc1.png");
	fond2 = IMG_Load("doc2.png");
	fond3 = IMG_Load("doc3.png");
	fond4 = IMG_Load("doc4.png");

	fog = IMG_Load("fog.png");
	//rain = IMG_Load("rain.png");
	m = IMG_Load("menu.png");

	ll = init_menu1();
	FILE* f;

	menu_pic = IMG_Load("menu pic.png");
	play = IMG_Load("p.png");
	settings = IMG_Load("s.png");
	quit = IMG_Load("q.png");
	credits = IMG_Load("c.png");

	play2 = IMG_Load("p2.png");
	credits2 = IMG_Load("c2.png");
	quit2 = IMG_Load("q2.png");
	settings2 = IMG_Load("s2.png");

	SDL_WM_SetCaption("game", NULL);

	pos_play.x = 90;
	pos_play.y = 320;

	pos_settings.x = 90;
	pos_settings.y = 460;

	pos_credits.x = 90;
	pos_credits.y = 740;

	pos_quit.x = 90;
	pos_quit.y = 600;

	pos_ms.x = 600;
	pos_ms.y = 300;

	strcpy(ch1, "the shade");
	pos_text.x = 200;
	pos_text.y = 25;

	menu(screen, play, menu_pic, quit, settings, credits, pos_play, pos_menu_pic, pos_quit, pos_settings, pos_credits);
	SDL_BlitSurface(fog, NULL, screen, &pos_menu_pic);

	text_ttf(ch1, police, text, screen, pos_text, white);
	song_fct(musique);

	bref = Mix_LoadWAV("bref.wav");

	SDL_Flip(screen);

	while (done)
	{
		animation1(screen, fog, m, fond1, pos_fond1, pos_m);
		animation1(screen, fog, m, fond2, pos_fond2, pos_m);
		animation1(screen, fog, m, fond3, pos_fond3, pos_m);
		animation1(screen, fog, m, fond4, pos_fond4, pos_m);

		SDL_Flip(screen);

		while (SDL_PollEvent(&event))
		{
			int i = 1;
			switch (event.type)
			{

			case SDL_QUIT:
				done = 0;
				break;

			case SDL_MOUSEMOTION:
			{
				if (event.motion.x >= pos_play.x && event.motion.x <= (pos_play.x + 480) && event.motion.y >= pos_play.y && event.motion.y <= (pos_play.y + 98))
				{
					play2 = IMG_Load("p2.png");
					SDL_BlitSurface(play2, NULL, screen, &pos_play);
					SDL_BlitSurface(credits, NULL, screen, &pos_credits);
					SDL_BlitSurface(settings, NULL, screen, &pos_settings);
					SDL_BlitSurface(quit, NULL, screen, &pos_quit);

					SDL_Flip(screen);
				}
				else if (event.motion.x >= pos_settings.x && event.motion.x <= (pos_settings.x + 480) && event.motion.y >= pos_settings.y && event.motion.y <= (pos_settings.y + 98))
				{
					settings2 = IMG_Load("s2.png");
					SDL_BlitSurface(settings2, NULL, screen, &pos_settings);
					SDL_BlitSurface(play, NULL, screen, &pos_play);
					SDL_BlitSurface(credits, NULL, screen, &pos_credits);
					SDL_BlitSurface(quit, NULL, screen, &pos_quit);
					SDL_Flip(screen);
				}
				else if (event.motion.x >= pos_quit.x && event.motion.x <= (pos_quit.x + 480) && event.motion.y >= pos_quit.y && event.motion.y <= (pos_quit.y + 98))
				{
					quit2 = IMG_Load("q2.png");
					SDL_BlitSurface(quit2, NULL, screen, &pos_quit);
					SDL_BlitSurface(play, NULL, screen, &pos_play);
					SDL_BlitSurface(settings, NULL, screen, &pos_settings);
					SDL_BlitSurface(credits, NULL, screen, &pos_credits);
					SDL_Flip(screen);
				}
				else if (event.motion.x >= pos_credits.x && event.motion.x <= (pos_credits.x + 480) && event.motion.y >= pos_credits.y && event.motion.y <= (pos_credits.y + 98))
				{
					credits2 = IMG_Load("c2.png"); 
					SDL_BlitSurface(credits2, NULL, screen, &pos_credits);
					SDL_BlitSurface(play, NULL, screen, &pos_play);
					SDL_BlitSurface(settings, NULL, screen, &pos_settings);
					SDL_BlitSurface(quit, NULL, screen, &pos_quit);
					SDL_Flip(screen);
				}

				break;  
			}
 
			case SDL_MOUSEBUTTONDOWN:
			{

				if (event.motion.x >= pos_play.x && event.motion.x <= (pos_play.x + 480) && event.motion.y >= pos_play.y && event.motion.y <= (pos_play.y + 98))
				{

					if (event.button.button == SDL_BUTTON_LEFT)
					{
						Mix_PlayChannel(-1, bref, 0);
						screen_state = 1;
						Mix_PauseMusic();
						temp = afficher_sous_menu1(screen, ll, temp);

						if (temp == 0)
						{
							temp = 1;

							perso = personnage(screen);
							ou= outil(screen);

                            if(perso==0 || perso==1)

							{
                            
							while (screen_state)

							{
								
								screen_state = playing(screen,ou,perso,cc,mini,pos_cam,score1, 3, time1, 50, pos1);  
							}
                            perso=5;
							ou=7;
							}
						}
						else if (temp==2)
						{
							temp = 1;
							 f = fopen("save.txt", "r");
							 if(f!=NULL) 
							 {
								     fscanf(f, "%d %d %d %d %d %d %d %d %d %d ",&ou,&perso,&cc,&mini,&pos_cam,&score1,&nbr_vie1,&time1,&pos_perso_x,&pos1);

                             }
                     fclose(f);

							while (screen_state)

							{  
							
								screen_state = playing(screen,ou,perso,cc,mini,pos_cam, score1, nbr_vie1, time1, pos_perso_x, pos1); 
							}


						}
						else if (temp==3)

						{   temp=1;
								while (screen_state)

							{
								screen_state= partage(screen);
							}

						}

						/*game load*/ /////
					}
					menu(screen, play, menu_pic, quit, settings, credits, pos_play, pos_menu_pic, pos_quit, pos_settings, pos_credits);

					text_ttf(ch1, police, text, screen, pos_text, white);
				}
				else if (event.motion.x >= pos_settings.x && event.motion.x <= (pos_settings.x + 480) && event.motion.y >= pos_settings.y && event.motion.y <= (pos_settings.y + 98))
				{

					if (event.button.button == SDL_BUTTON_LEFT)
					{
						Mix_PlayChannel(-1, bref, 0);
						screen_state = 1;

						while (screen_state)

						{
							menu_s = IMG_Load("settings menu.png");
							SDL_BlitSurface(menu_s, NULL, screen, &pos_ms);

							back = IMG_Load("b.png");
							SDL_BlitSurface(back, NULL, screen, &pos_back);

							pos_full.x = 1100;
							pos_full.y = 450;

							pos_mute.x = 650;
							pos_mute.y = 450;

							pos_song.x = 650;
							pos_song.y = 650;

							full = IMG_Load("full screen.png");
							SDL_BlitSurface(full, NULL, screen, &pos_full);

							mute = IMG_Load("mute.png");
							SDL_BlitSurface(mute, NULL, screen, &pos_mute);

							song = IMG_Load("sound.png");
							SDL_BlitSurface(song, NULL, screen, &pos_song);

							SDL_Flip(screen);
							while (SDL_PollEvent(&event2))
							{switch (event2.type)
							{
							case SDL_MOUSEBUTTONDOWN:
								if (event2.motion.x >= pos_back.x && event2.motion.x <= (pos_back.x + 90) && event2.motion.y >= pos_back.y && event2.motion.y <= (pos_back.y + 90))
								{
									if (event2.button.button == SDL_BUTTON_LEFT)

									{

										screen_state = 0;
										/*return to menu */
									}
								}

								else if (event2.motion.x >= pos_full.x && event2.motion.x <= (pos_full.x + 204) && event2.motion.y >= pos_full.y && event2.motion.y <= (pos_full.y + 115))
								{
									if (event2.button.button == SDL_BUTTON_LEFT)

									{
                                         rotozoom(screen);
										/*fullscreen*/
									}
								}

								if (event2.motion.x >= pos_mute.x && event2.motion.x <= (pos_mute.x + 180) && event2.motion.y >= pos_mute.y && event2.motion.y <= (pos_mute.y + 119))
								{
									if (event2.button.button == SDL_BUTTON_LEFT)

									{
										Mix_PauseMusic();

										/*mute*/
									}

									break;
								}
								if (event2.motion.x >= pos_song.x && event2.motion.x <= (pos_song.x + 180) && event2.motion.y >= pos_song.y && event2.motion.y <= (pos_song.y + 119))
								{
									if (event2.button.button == SDL_BUTTON_LEFT)

									{
										Mix_ResumeMusic();

										/*mute*/
									}

									break;
								}
							}

							}

							SDL_Flip(screen);
						}
						menu(screen, play, menu_pic, quit, settings, credits, pos_play, pos_menu_pic, pos_quit, pos_settings, pos_credits);

						text_ttf(ch1, police, text, screen, pos_text, white);
					}
				}

				else if (event.motion.x >= pos_quit.x && event.motion.x <= (pos_quit.x + 480) && event.motion.y >= pos_quit.y && event.motion.y <= (pos_quit.y + 98))
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						Mix_PlayChannel(-1, bref, 0);
						done = 0;
					}
				}
				else if (event.motion.x >= pos_credits.x && event.motion.x <= (pos_credits.x + 480) && event.motion.y >= pos_credits.y && event.motion.y <= (pos_credits.y + 98))
				{

					if (event.button.button == SDL_BUTTON_LEFT)
					{
						Mix_PlayChannel(-1, bref, 0);

						screen_state = 1;

							pos_text2.x = 620;
							pos_text2.y = 450;

						while (screen_state)

						{

							game = IMG_Load("load_bg.png");
							SDL_BlitSurface(game, NULL, screen,&pos_ms);
							

							back = IMG_Load("b.png");
							SDL_BlitSurface(back, NULL, screen, &pos_back);
							

							strcpy(ch2, "credits");
							text_ttf(ch2, police, text, screen, pos_text1, white);


							/*strcpy(ch3, "goes to druids' group");
							text_ttf(ch3, police, text, screen, pos_text2, white);*/

							

							while (SDL_PollEvent(&event2))
							{
							switch (event2.type)
							{
							case SDL_MOUSEBUTTONDOWN:
								if (event2.motion.x >= pos_back.x && event2.motion.x <= (pos_back.x + 90) && event2.motion.y >= pos_back.y && event2.motion.y <= (pos_back.y + 90))
								{
									if (event2.button.button == SDL_BUTTON_LEFT)

									{

										screen_state = 0;
									}
								}

								break;
							}
							}
						}

						SDL_Flip(screen);
					}
					menu(screen, play, menu_pic, quit, settings, credits, pos_play, pos_menu_pic, pos_quit, pos_settings, pos_credits);

					text_ttf(ch1, police, text, screen, pos_text, white);
				}
				break;
			}

			case SDL_KEYDOWN:
			{
				if (event.key.keysym.sym == SDLK_UP)
				{

					etat--;
					if (etat >= 0)
					{
						keyboard(etat, screen, play, quit, settings, credits, quit2, settings2, play2, credits2, pos_play, pos_quit, pos_settings, pos_credits);
					}
					else if (etat < 0)
					{
						etat = 3;
						keyboard(etat, screen, play, quit, settings, credits, quit2, settings2, play2, credits2, pos_play, pos_quit, pos_settings, pos_credits);
					}
				}
				else if ((event.key.keysym.sym == SDLK_DOWN))
				{

					etat++;
					if (etat < 4)
					{
						keyboard(etat, screen, play, quit, settings, credits, quit2, settings2, play2, credits2, pos_play, pos_quit, pos_settings, pos_credits);
					}
					else if (etat >= 4)
					{
						etat = 0;
						keyboard(etat, screen, play, quit, settings, credits, quit2, settings2, play2, credits2, pos_play, pos_quit, pos_settings, pos_credits);
					}
				}
				else if (event.key.keysym.sym == SDLK_j)
				{
					{

						Mix_PlayChannel(-1, bref, 0);
						screen_state = 1;
						Mix_PauseMusic();
						temp = afficher_sous_menu1(screen, ll, temp);

						if (temp == 0)
						{
							temp = 1;

							perso = personnage(screen);

                            if(perso==0 || perso==1)

							{
                            
							while (screen_state)

							{
								
								screen_state = playing(screen,ou,perso,cc,mini,pos_cam,score1, 3, time1, pos_perso_x, pos1);  
							}
                            perso=5;
							}
						}
						else if (temp==2)
						{
							temp = 1;
							 f = fopen("save.txt", "r");
							 if(f!=NULL) 
							 {
								     fscanf(f, "%d %d %d %d %d %d %d %d %d ",&perso,&cc,&mini,&pos_cam,&score1,&nbr_vie1,&time1,&pos_perso_x,&pos1);

                             }
                     fclose(f);

							while (screen_state)

							{  
							
								screen_state = playing(screen,ou,perso,cc,mini,pos_cam, score1, nbr_vie1, time1, pos_perso_x, pos1); 
							}


						}

						/*game load*/ /////
					}
					menu(screen, play, menu_pic, quit, settings, credits, pos_play, pos_menu_pic, pos_quit, pos_settings, pos_credits);

					text_ttf(ch1, police, text, screen, pos_text, white);
				}

				break;
			}
			}
			SDL_Flip(screen);
		}
	}
	liberation(police, screen, menu_pic, song, game, mute, full, back, text2, fond1, fond2, fond3, fond4, text, play, quit, settings, credits, quit2, settings2, play2, credits2);
	return 0;
}
