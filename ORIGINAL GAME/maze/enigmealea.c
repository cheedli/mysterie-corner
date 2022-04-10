#include "header.h"

void main()
{
 SDL_Surface *screen ;
    SDL_Event event;
        screen = SDL_SetVideoMode(1380,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_Surface *resultat[2]; 
        SDL_Rect pos; 
        int done=1;
resultat[1]=IMG_Load("w.png");
resultat[0]=IMG_Load("l.png");

pos.x=0;
pos.y=0;
enigme e;
animer (&e);
while(done)
{
    SDL_BlitSurface(resultat[e.reponsejuste],NULL,screen,&pos);
    SDL_PollEvent(&event);

        if ((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE))
            done = 0;
        SDL_Flip(screen);
    
    
    }

	SDL_Quit();
}

