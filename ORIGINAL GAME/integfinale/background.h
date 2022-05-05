#ifndef bg_H_INCLUDED
#define bg_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"


////////// structure de background

typedef struct
{
    SDL_Surface *image[3],*masque[3],*bird[3];//3ana 3 image t3 background o leur 3 masque et 3 image mt3 l bird 
    SDL_Rect positionbackground,positionbird;
    SDL_Rect positionback_partage;
    int level,partage,compteur;
    //chaque niveau andou l background l khassa byh haka aleh st7a9ina heja ismha level
    //compteur c'est pour l animation du oiseau
    //partage pour verifier si le joueur yhb yaaml multijoueuur wala solo
    SDL_Rect camera1;
    SDL_Rect camera2;
} background;

///// structure de deplacement

typedef struct
{
    int left, right,d,q;
} mouvement;




void initBack(background *b);
void aficherBack(SDL_Surface *screen, background *b);
void scrolling(background *b, SDL_Surface *screen, mouvement M);
SDL_Color GetPixel(SDL_Surface *psurface, int x, int y);
int  collisionparfaite(SDL_Surface *psurface,perso p);
void animerBackground( background * b);
void init_Mouvement(mouvement *M);
void collision(SDL_Surface *psurface,perso *p,perso *pp);

#endif

