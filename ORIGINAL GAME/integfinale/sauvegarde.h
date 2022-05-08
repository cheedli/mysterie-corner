#ifndef SAUVEGARDE_H_INCLUDED
#define SAVEGARDE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>


int load_data(FILE* fichier,SDL_Rect* pos_perso,SDL_Rect* camera,int* score,int* vie);
int save_data(FILE* fichier,SDL_Rect* pos_perso,SDL_Rect* camera,int* score,int* vie);
#endif // SAUVEGARDE_H_INCLUDED

