#include "minimap.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

void init_map (minimap *m)
{ m -> map = IMG_Load("n2.png");
  m-> minijoueur = IMG_Load("persomini.png");
  m->positionmap.x =330;
  m->positionmap.y =20;
  m->positionminijoueur.x =330;
  m->positionminijoueur.y =20;
}

void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect posJoueurABS;
  posJoueurABS.x = 0;
  posJoueurABS.y = 0;
  posJoueurABS.x = posJoueur.x + camera.x;
  posJoueurABS.y = posJoueur.y + camera.y;
  m->positionminijoueur.x=(posJoueurABS.x * redimensionnement/100)+330;
  m->positionminijoueur.y=(posJoueurABS.y * redimensionnement/100)+20;
}

void afficherminimap (minimap m, SDL_Surface * screen)
{
  SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
  SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
}
void initialiser_temps(temps *t)
{
 t->texte = NULL; //surface qui sert à l'affichage du temps
 t->position.x=30;
 t->position.y=30;
 t->police = NULL;
 t->police = TTF_OpenFont("angelina.TTF", 50);
 strcpy( t->entree,"");
 (t->secondesEcoulees)=0;
 time(&(t->t1)); 
}


void afficher_temps(temps *t,SDL_Surface *ecran)
{	
SDL_Color couleurn= {0, 0, 0};//noir

    	time(&(t->t2));// temps actuel
	t->secondesEcoulees = t->t2 - t->t1;
        t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);
	sprintf(t->entree,"%02d:%02d",t->min,t->sec);
        t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurn);
      

SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); /* Blit du texte */
	
}

void free_temps(temps *t,SDL_Surface *ecran)
{SDL_FreeSurface(t->texte);
 TTF_CloseFont(t->police);
}
void save (int valeur_score)
 { 
    FILE* saveF = NULL;
    saveF = fopen("sauvegarde.txt","a+"); 

        if(saveF != NULL)
{   

 //ecrire le nom du joueur(ne9sa)
 fprintf(saveF,"%d\n",valeur_score); 
              
		

        }

    fclose(saveF); 
}

void load (int valeur_score )
{ 

    FILE* saveF = NULL;
    saveF = fopen("sauvegarde.txt","r"); 

    if(saveF != NULL) 
	{ 
	
	    fscanf(saveF,"%d",&valeur_score);
	    
        }

    fclose(saveF); 
}
void initialiser_score (int valeur_score, score *s )
{
SDL_Surface *texte1=NULL;  
SDL_Surface *number1=NULL; 
TTF_Font *police=NULL;

s->police = TTF_OpenFont("avocado.ttf", 30);

SDL_Color couleur={0,0,0}; 


s->position_number.x=740;
s->position_number.y=25;

s->position_texte.x=600;
s->position_texte.y=25;
char texte[20];
strcpy(texte,"Score :"); 
char number[20];  
sprintf(number, "%d ", valeur_score);
s->texte1= TTF_RenderText_Blended(s->police,texte,couleur);
s->number1= TTF_RenderText_Blended(s->police,number,couleur);
TTF_CloseFont(police);

}

// AFFICHAGE
void afficher_score(score *s,SDL_Surface *screen,int valeur_score)
{
SDL_Color couleur={0,0,0};
char texte[20];
strcpy(texte,"Score :"); 
char number[20]; //tableau de chaine de c ou on va stocker la valeur du score 
sprintf(number, "%d ", valeur_score); 
s->texte1= TTF_RenderText_Blended(s->police,texte,couleur);
s->number1= TTF_RenderText_Blended(s->police,number,couleur);
SDL_BlitSurface(s->texte1, NULL, screen,&s->position_texte);
SDL_BlitSurface(s->number1, NULL, screen,&s->position_number);
}

//UPDATE

void update_score  (int *valeur_score)
{
  
(*valeur_score)+=10;	

}
void free_score( score s)
{
SDL_FreeSurface(s.texte1);
SDL_FreeSurface(s.number1);

}
  
