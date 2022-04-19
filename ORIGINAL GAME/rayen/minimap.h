#ifndef minimap_H
#define minimap_H
#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
//structures:
typedef struct 
{SDL_Surface *map;
SDL_Surface  *minijoueur;
SDL_Rect positionmap;
SDL_Rect positionminijoueur;
}minimap;

typedef struct 
{
SDL_Surface *texte1;
SDL_Surface *number1;
char number[20];
char texte[20];
SDL_Rect position_texte;
SDL_Rect position_number;  
TTF_Font *police;

}score ;
typedef struct temps
{
 SDL_Surface *texte;//image qui contient le temps
 SDL_Rect position;// position du clock
 TTF_Font *police ;
 char entree[100]; // chaine de caractere . forme "mm:ss"
 int secondesEcoulees; // variable entier qui contient le nbre de secondes ecoulés
 SDL_Color couleurn;// couleur de texte a afficher
 time_t t1,t2; //t1 temps initiale ,,, t2 temps actuel
 int min, sec;// minutes et secondes
}temps;

//fonctions:
//fonction map
void init_map (minimap *m);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficherminimap (minimap m, SDL_Surface * screen);
//fonction score
void initialiser_score (int valeur_score, score *s );
void update_score (int *valeur_score);
void afficher_score(score *s,SDL_Surface *screen,int valeur_score);
void free_score(score s);
//fonction save
void save (int valeur_score);
void load (int valeur_score);
//fonction temps
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t,SDL_Surface *ecran);
#endif
