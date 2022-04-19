
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "minimap.h"




int main()
{
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen ,*perso;
screen=SDL_SetVideoMode (1600,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("minimap",NULL);
SDL_Rect camera,posperso;
SDL_Event event;
minimap m;
temps t;
SDL_Surface *back;
//initialisation background & perso
perso=IMG_Load("perso1.png");
back=IMG_Load("n1.png");
int done=1;
init_map(&m);
camera.x=0;
camera.y=0;
camera.w=1600;
camera.h=800;
posperso.x=0;
posperso.y=520;
SDL_EnableKeyRepeat(100,10);
initialiser_temps(&t);
int valeur_score=0;
score s;
initialiser_score(valeur_score,&s);
while(done)
{
//affichage background
SDL_BlitSurface(back,NULL,screen,NULL);
//events
while(SDL_PollEvent(&event))
{

   switch(event.type)
   {
	case SDL_QUIT:
	   done=0;
	   break;
	case SDL_KEYDOWN:
	   switch (event.key.keysym.sym)
	   {
                case SDLK_ESCAPE:
			save(valeur_score);
		        done = 0;
	                break;
                case SDLK_m:
			update_score(&valeur_score);
			break;
                case SDLK_LEFT:
                        posperso.x-=10;
                        break;
                case SDLK_RIGHT:
                        posperso.x+=10;     
                        break;
                case SDLK_UP:
                        posperso.y-=10;
                        break;  
                case SDLK_DOWN:
                        posperso.y+=10;
                        break;  

            }
            break;
            
        }
    }        
MAJMinimap(posperso ,&m, camera, 10);
//affichage perso
SDL_BlitSurface(perso,NULL,screen,&posperso);
afficherminimap(m,screen);
afficher_temps(&t,screen);
afficher_score(&s,screen,valeur_score);
SDL_Flip(screen);

}

    //return 0;
}


