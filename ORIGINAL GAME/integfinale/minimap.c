
#include "minimap.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

//initialisation du minimap et le minijoueur et leurs positions
void init_map (minimap *m)
{
    m -> map = IMG_Load("minimap/n2.png");
    m-> minijoueur = IMG_Load("minimap/persomini.png");
    m->positionmap.x =300;
    m->positionmap.y =20;
    m->positionminijoueur.x =330;
    m->positionminijoueur.y =20;
}

//mise a jour de la position du minijoueur

void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
    SDL_Rect posJoueurABS;
    posJoueurABS.x = 0;
    posJoueurABS.y = 0;
    posJoueurABS.x = posJoueur.x + camera.x;
    posJoueurABS.y = posJoueur.y + camera.y;
    m->positionminijoueur.x=(posJoueurABS.x * redimensionnement/100)+330;
    m->positionminijoueur.y=(posJoueurABS.y * redimensionnement/100)-5;
}
//affichage du minimap et minijoueur

void afficherminimap (minimap m, SDL_Surface * screen)
{
    SDL_BlitSurface(m.map,NULL,screen,&m.positionmap);
    SDL_BlitSurface(m.minijoueur,NULL,screen,&m.positionminijoueur);
}

				//***PARTIE TEMPS***//
				
//initialisation du temps(surface du text,position,police,entre qui contient le contenu du text,et secondes)

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

//affichage du temps

void afficher_temps(temps *t,SDL_Surface *ecran)
{
    SDL_Color couleurn= {0, 0, 0};//noir
    time(&(t->t2));// temps actuel
    t->secondesEcoulees = t->t2 - t->t1;
    t->min=((t->secondesEcoulees/60)%60);
    t->sec= ((t->secondesEcoulees)%60);
    sprintf(t->entree,"%02d : %02d",t->min,t->sec);
    t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurn);
    SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); /* Blit du texte */
}
					//**PARTIE SCORE ***//
					
//save le score et le nom  dans le fichier sauvegarde.txt

void save (int valeur_score,char nom[])
{
    FILE* saveF = NULL;
    saveF = fopen("sauvegarde.txt","a+");

    if(saveF != NULL)
    {
        fprintf(saveF,"%s\t%d\n",nom,valeur_score);
    }

    fclose(saveF);
}
//le fonction qui load le meuilleur score

void load (int valeur_score,char nom[])
{
    int m=-1;
    char mm[30]="";
    FILE* saveF = NULL;
    saveF = fopen("sauvegarde.txt","r");

    if(saveF != NULL)
    {

        while(fscanf(saveF,"%s\t%d",nom,&valeur_score)!=EOF)
        {
            if(m<valeur_score)
            {
                m=valeur_score;
                strcpy(mm,nom);

            }

        }
    }
    printf("%s\t%d\n",nom,m);

    fclose(saveF);
}

//INITIALISATION DU SCORE

void initialiser_score (int valeur_score, score *s )
{
	s->police=NULL;
    s->police = TTF_OpenFont("avocado.ttf", 30);
    SDL_Color couleur= {0,0,0};
   
    char texte[20];
    strcpy(texte,"Score :");
    char number[20];
    sprintf(number, "%d ", valeur_score);
    s->texte1= TTF_RenderText_Blended(s->police,texte,couleur);
    s->number1= TTF_RenderText_Blended(s->police,number,couleur);
     s->position_number.x=1220;
    s->position_number.y=25;

    s->position_texte.x=1100;
    s->position_texte.y=25;


} 

// AFFICHAGE
void afficher_score(score *s,SDL_Surface *screen,int valeur_score)
{
    SDL_Color couleur= {0,0,0};
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
    if(*(valeur_score)>0)
        *(valeur_score)-=0.2;
}
