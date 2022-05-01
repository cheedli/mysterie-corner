#include<stdio.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "collisionparfaite.h"
#include "background.h"

int main(void)
{	
	int continuer=1;
	SDL_Surface *screen=NULL;
	background ba,bm;
	Personne perso;
	SDL_Event event;
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	screen=SDL_SetVideoMode(1380,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}
//if(Mix_OpenAudio(1100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 55) == -1) //Initialisation de l'API Mixer
   //{
     // printf("%s", Mix_GetError());
   //}
		
	initialisation_back(&ba);//initback
	initBackMasque(&bm);//pour la collision parfaite
	

	initialiserperso(&perso);
	

	while (continuer)
	{		
		deplacer_perso(&perso,event);
		afficheBack(bm,screen);
                             afficheBack2 (ba, screen);
 		collision(screen,&perso);
		SDL_PollEvent(&event);
     	switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
			case SDLK_RIGHT:
			 
			if ( collisionparfaite(screen,perso)==10){
				scrolling(&ba,0);	//scrollingright;	
				scrolling(&bm,0);
			}
					
                        break;
                        case SDLK_LEFT:
                    
                       if ( collisionparfaite(screen,perso)==10){
				scrolling(&ba,1);//scrolllingleft;
				scrolling(&bm,1);
			}			
		 
                        break;
			 case SDLK_UP:
			 
		  		if ( collisionparfaite(screen,perso)==10){
					scrolling(&ba,2);	//scrollinup;	
					scrolling(&bm,2);
				}			 
                        break;
 			 case SDLK_d:
 			 
 		  		if ( collisionparfaite(screen,perso)==10){
					scrolling(&ba,3);	//scrollingdown;	
					scrolling(&bm,3);
				}			 
                        break;	
      		 }
      		 	
            break;
       

 	} 		animerBackground(&ba);	
			afficheBack2(ba,screen);
	
			afficher_perso(screen,perso);	
			SDL_Flip(screen);
			SDL_Delay(100);
	}

	
	SDL_Quit();

	return 1;
}
