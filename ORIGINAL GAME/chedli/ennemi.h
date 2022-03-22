#ifndef ENNEMIE_H_INCLUDED
#define ENNEMIE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>					



struct ennemi{
	int orientation;
	int esprit;
	
	SDL_Surface *image;
	
	SDL_Rect position;
	SDL_Rect positionRelative;
	
	int tempsActuel;
	
	SDL_Rect clipsRight[20];
	SDL_Rect clipsLeft[20];
	
	int speed;
	int frame;
	int status;
};

void afficher_enemie (enemie *f,SDL_Surface *screen,SDL_Rect pos);
void animerEnnemi( enemie * e);
void deplacer( enemie * e);
int collisionBB( SDL_Rect posp, SDL_Rect pose);



#endif

 



typedef struct 
	{

	SDL_Surface *image_enemie;
	SDL_Rect rect;

	SDL_Rect rects[5][14];
	int frame;
	int direction;	
  	int range;
	int dead;
	}enemie;


void LAMTI(enemie *E,int range);
void LAMTI2(SDL_Rect* clip[5][14]);
void LAMTI1(enemie*f);

void update_ennemi(enemie *E,SDL_Surface *screen,SDL_Rect r,int p);



#endif // 2NDENTITE_H_INCLUDED
