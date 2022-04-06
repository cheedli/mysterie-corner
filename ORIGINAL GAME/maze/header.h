#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <string.h>

typedef struct 
{
 SDL_Surface * img;
 SDL_Rect 	pos,pos2;
}enigme;

typedef struct 
{ 
SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
}text;

void init_enigme( enigme es[] ,enigme *back,enigme timer[] );
void afficherEnigme(enigme e, SDL_Surface * screen);
void animer (enigme *e);
void generateennigmeS();

//texte 

void initexte(text *t);
void displayText(text t,SDL_Surface *screen,char cc[30]);


