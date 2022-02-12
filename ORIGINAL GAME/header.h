#ifndef Text_H
#define Text_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_H 700
#define SCREEN_W 898
typedef struct{
	SDL_Rect pos;
	SDL_Surface *img;
}image;
typedef struct {
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
} text;

void initBackground(image *Backg);
void afficher(image A,SDL_Surface *screen);
void libererButtons(image A,image B, image C, image D, image E);
void initquit(image *q1,image *q21,image *q22,image *q23,image *q31,image *q32,image *q33);
void initoption(image *o1,image *o21,image *o22,image *o23,image *o31,image *o32,image *o33);
void initplay(image *p1,image *p21,image *p22,image *p23,image *p31,image *p32,image *p33);

void creatbackground(image *Backg);
void afficher(image A,SDL_Surface *screen);
void loadimage(image *play[8],image *option[7],image *quit[7] );
void initText(text *A); 
void freeText(text A); 
void displayText(text t,SDL_Surface *screen) ;

/*void initText(text *t);
void freeText(text A);
void displayText(text t,SDL_Surface *screen);*/
#endif
