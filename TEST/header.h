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


//les fonctions qui correspond au image
 
void initialiser_image(image *m);
void initialiser_background(image *background);
void afficher(image A,SDL_Surface *screen);
void liberer(image A );

//les fonctions qui correspond au text 

void initText(text *A); 
void freeText(text A); 
void displayText(text t,SDL_Surface *screen) ;
void initback(image back[]);

#endif
