#ifndef ENNEMIE_H_INCLUDED2
#define ENNEMIE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>					


typedef struct 
{
		SDL_Rect posg[2],posa[3],posl[2],posb[4];
			SDL_Surface *g[2],*a[3],*l[2],*b[4];
}ennemi;
typedef struct 
{

	ennemi en;
	SDL_Rect pos[4];
	int etat,level;
	
}Ennemi;
	
	typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img;
}image;
	
void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
int collisionBox(SDL_Rect a, SDL_Rect b);
//void deplacerAI( enemie * e);


#endif
