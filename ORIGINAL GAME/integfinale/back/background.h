#ifndef BACKGROUND_H_INCLUDE
#define BACKGROUND_H_INCLUDE
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "pres.h"

#define SCREEN_W 1360
#define SCREEN_H 765

typedef struct
{
	SDL_Surface *imgback;
	SDL_Rect posback;
	SDL_Rect posback2;
	SDL_Rect camera;
	SDL_Rect camera2;
	Mix_Music *son;
	SDL_Surface *image_flower;  
	SDL_Rect pos_image_flower;
	SDL_Rect single_flower;	
	int flower_num;


}background;
void afficher_back(background b, SDL_Surface *ecran);
void initialisation_back(background *b);
void initBack (background *b);
void initBackMasque (background *b);
void initBack2 (background *b);
void afficheBack (background b,SDL_Surface *ecran);
void afficheBack2 (background b,SDL_Surface *ecran);
void scrolling (background *b,int direction);
void animerBackground(background *b);
void displayFlower(background b,SDL_Surface *ecran);

SDL_Color getpixel(SDL_Surface *psurface,int x,int y);
int collisionparfaite(SDL_Surface *psurface,Personne perso);
void collision(SDL_Surface *psurface,Personne *perso);

#endif  
