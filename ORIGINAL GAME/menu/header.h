#ifndef header_H
#define header_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_H 780
#define SCREEN_W 1300
typedef struct
{
	SDL_Rect pos;
	SDL_Surface *img;
}image;
typedef struct 
{
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
} text;
void inp(image *m);
void inti_in_option(image l[],image ll[],image *backo);
void init(image q[],image p[],image o[],image back[],image so[],image m[],image sc[],image *name);
void afficher(image A,SDL_Surface *screen);
void liberer(image A );

void initText(text *A); 
void freeText(text A); 
void displayText(text t,SDL_Surface *screen) ;
void initback(image back[]);

#endif
