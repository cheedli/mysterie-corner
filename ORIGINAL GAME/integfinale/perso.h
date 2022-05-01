#ifndef test_H_INCLUDED
#define test_H_INCLUDED

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
double vitesse[4],   acceleration;
SDL_Surface *personnage[4];
SDL_Rect rect;
SDL_Rect pos_sprite[4];

float vitesse_V[4];
int direction ; 
/*
les directions:
0:stable droite
1:droite
2:gauche
3: jump
*/

}perso;

typedef struct Input
{
 int left,right,jump;

} Input;
void initialiser_walk (perso *p);
void initialiser_wl (perso *p);
void initialiser_jump (perso *p);
void initialiser_perso (perso *p);
void afficher_perso (perso p,SDL_Surface *screen);

void animation (perso *p,Input i);
void movePerso(perso *p,Uint32 dt,Input i);

// acceleration
void persooo() ;


void initialiser_input (Input *I);

void saut(perso *p);


 #endif

