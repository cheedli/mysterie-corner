#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <string.h>
#include "menu.h"

typedef struct 
{
char mazesmall[50],mazebig[50];
 SDL_Surface *maze[6],*timer[10],*back;
 SDL_Rect 	posmaze[6],postimer,posback;
 int reponsejuste,reponse,r[3];
}enigme2;



void InitEnigme2(enigme2 * e, char *nomfichier);
void afficherEnigme2(enigme2 e, SDL_Surface * screen);
void animer2 (enigme2 *e);



void initexte(text *t);
void displayTexte2(text t,SDL_Surface *screen,char cc[30]);
