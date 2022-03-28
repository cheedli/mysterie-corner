#ifndef ENNEMIE_H_INCLUDED
#define ENNEMIE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>					



struct ennemi
	{
	SDL_Surface *img;
	SDL_Rect pos,pos2;
	int etat;
	
	};

void afficher_enemie (enemie *f,SDL_Surface *screen,SDL_Rect pos);
void animerEnnemi( enemie * e);
void deplacer( enemie * e);
int collisionBB( SDL_Rect posp, SDL_Rect pose);
void deplacerAI( enemie * e);


#endif
