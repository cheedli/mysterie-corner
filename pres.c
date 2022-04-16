#include "pres.h"

void initialiserperso(Personne *perso)
{	
	perso->image_p=IMG_Load("boy.png");
	perso->pos_perso.x=0;
	perso->pos_perso.y=350;
	//perso->pos_perso.w=50;
	//perso->pos_perso.h=50;
}

void afficher_perso(SDL_Surface *screen,Personne perso)
{	
	SDL_BlitSurface(perso.image_p,NULL,screen,&perso.pos_perso);
}

void deplacer_perso(Personne *perso,SDL_Event event)
{	

         switch(event.type)
            {
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym)
                        {
                        
                        case SDLK_UP:
                            perso->pos_perso.y=perso->pos_perso.y-5;
                            break;
                        case SDLK_d:
                            perso->pos_perso.y=perso->pos_perso.y+5;
                            break;
                        case SDLK_RIGHT:
                            perso->pos_perso.x=perso->pos_perso.x+5;
                            break;
                        case SDLK_LEFT:
                            perso->pos_perso.x=perso->pos_perso.x-5;
                            break;
                        }
                 break;
             }
}


void free_perso(Personne perso)
{
	SDL_FreeSurface(perso.image_p);
}















