#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#define SCREEN_H 700
#define SCREEN_W 898


typedef struct { 
SDL_Rect position; 
TTF_Font *font; 
SDL_Surface * surfaceTexte; 
SDL_Color textColor; 
char texte [50]; 
} Text;
typedef struct{
	SDL_Rect pos;
	SDL_Surface *img;
}image;
void creatbackground(image *Backg);
void afficher(image A,SDL_Surface *screen);

void loadimage(image *play[8],image *option[7],image *quit[7] );
void initText(Text *A); 
void freeText(Text A); 
void displayText(Text t,SDL_Surface *screen) ;
void fre(image A );


#endif // MENU_H_INCLUDED
