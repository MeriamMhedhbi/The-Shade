Game: enigme3.o enigme22.o partage_ecran.o enigf1.o enigf4.o zoom.o vie.o temps.o colis.o scrolling.o closhard.o collision.o bg.o menu.o score.o scorefin.o hero.o save.o load.o amelioration_menu.o enemy_auto.o lvl1.o menu_jeu.o
	gcc enigme3.o enigme22.o partage_ecran.o enigf4.o enigf1.o zoom.o vie.o temps.o colis.o scrolling.o closhard.o collision.o bg.o menu.o score.o scorefin.o hero.o save.o load.o amelioration_menu.o enemy_auto.o lvl1.o menu_jeu.o -o Game -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL_gfx 
menu_jeu.o:menu_jeu.c
	gcc -c menu_jeu.c 
enigme3.o:enigme3.c
	gcc -c enigme3.c
enigme22.o:enigme22.c
	gcc -c enigme22.c
enigf1.o:enigf1.c
	gcc -c enigf1.c
enigf4.o:enigf4.c
	gcc -c enigf4.c
zoom.o:zoom.c
	gcc -c zoom.c
temps.o:temps.c
	gcc -c temps.c
vie.o:vie.c
	gcc -c vie.c
colis.o:colis.c
	gcc -c colis.c
scrolling.o:scrolling.c
	gcc -c scrolling.c
closhard.o:closhard.c 
	gcc -c closhard.c
bg.o:bg.c
	gcc -c bg.c
collision.o:collision.c
	gcc -c collision.c
menu.o:menu.c
	gcc -c menu.c
score.o:score.c
	gcc -c score.c
scorefin.o:scorefin.c
	gcc -c scorefin.c
hero.o:hero.c
	gcc -c hero.c
save.o:save.c
	gcc -c save.c
load.o:load.c
	gcc -c load.c
amelioration_menu.o:amelioration_menu.c
	gcc -c amelioration_menu.c
enemy_auto.o:enemy_auto.c
	gcc -c enemy_auto.c
partage_ecran.o:partage_ecran.c
	gcc -c partage_ecran.c
lvl1.o:lvl1.c
	gcc -c lvl1.c
