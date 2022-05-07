#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct perso
{

double vitesse,   acceleration;
SDL_Surface *personnage;
SDL_Rect rect;
SDL_Rect pos_sprite;

float vitesse_V;
int direction ; 
/*
les directions:
0:stable droite
1:stable gauche
2:droite
3:gauche

*/

}perso;

typedef struct Input
{
 int left,right,jump;

} Input;

void initialiser_perso (perso *p);
void afficher_perso (perso *p,SDL_Surface *screen);

void animation (perso *p);
void movePerso(perso *p,Uint32 dt);



void initialiser_input (Input *I);

void saut(perso *p);


 #endif
