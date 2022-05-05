#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"


int main()
{
    SDL_Surface *screen,*image,*perso;
    SDL_Rect posperso;
    mouvement M;
    background b;
    int continuer = 1,pasavancement,direction;
    Mix_Music *music;
    personne per,persoo;


////////////////////////////////////// musique continue/////////////////////////

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    music = Mix_LoadMUS("music.mp3") ;
    Mix_PlayMusic(music,-1);

//////////////////////////////

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);//// initialisation de SDL
    SDL_WM_SetIcon(IMG_Load("w"), NULL);/// image de l'icon
    screen = SDL_SetVideoMode(1380, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);//// creation de fenetre
    SDL_WM_SetCaption("Castle-Break", NULL); /// nom de fenetre


    init_Mouvement(&M); // appel fonction initialisation des deplacement
    initBack(&b);// appel fonction initialisation de background 1 et 2

    per.img = IMG_Load ("p.png");

    per.pos_perso.x= 1;
    per.pos_perso.y =500;

    persoo.pos_perso.x= 1;
    persoo.pos_perso.y =500;

    b.level=0;
//b.partage=1;

///////////////////////////////////////////////// evenement////////////////////////////////////////
    SDL_Event event;
    SDL_EnableKeyRepeat(1, 0);//curseur continue
    while (continuer)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                continuer = 0;
                break;

            }
            
                switch (event.type)
                {
                case SDL_KEYDOWN:

                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
if (persoo.pos_perso.x < 5000 && persoo.pos_perso.x>0)
            {
                    case SDLK_RIGHT:
                        M.right = 1;
                        persoo.pos_perso.x+=10;
                        break;
                    case SDLK_UP:
                        persoo.pos_perso.y-=5;
                        per.pos_perso.y-=5;

                        break;
                    case SDLK_DOWN:
                        persoo.pos_perso.y+=5;
                        per.pos_perso.y+=5;
                        break;


                    case SDLK_LEFT:
                        M.left = 1;
                        persoo.pos_perso.x-=10;

                        break;}

                    case SDLK_d:
                        M.d = 1;
                        break;
                        persoo.pos_perso.x+=10;

                    case SDLK_a:
                        M.q = 1;
                        persoo.pos_perso.x-=10;
                        break;
                    }
                    break;


                case SDL_KEYUP:

                    switch (event.key.keysym.sym)
                    {
                    
                    case SDLK_UP:
                        per.pos_perso.y-=5;
                        posperso.y-=5;
                        break;
                    case SDLK_DOWN:
                        persoo.pos_perso.y+=5;
                        per.pos_perso.y+=5;
                        break;

                    case SDLK_RIGHT:
                        M.right = 0;
                        persoo.pos_perso.x+=10;
                        break;

                    case SDLK_LEFT:
                        M.left = 0;
                        persoo.pos_perso.x-=10;
                        break;

                    case SDLK_d:
                        M.d = 0;
                        posperso.x+=10;
                        break;

                    case SDLK_a:
                        M.q = 0;
                        persoo.pos_perso.x-=10;
                        break;
                    }
                    break;
                }
            }
      
persoo.pos_perso.x=b.camera1.x+90;
persoo.pos_perso.y=per.pos_perso.y+90;
 SDL_BlitSurface(per.img,NULL,screen,&per.pos_perso);
        aficherBack(screen, &b);/// appel fonction affichage back 1
        
        if(collisionparfaite(b.masque[b.level],persoo)==10)
        {
           
            scrolling(&b,  screen, M);
        }
        animerBackground( &b);
        SDL_BlitSurface(per.img,NULL,screen,&per.pos_perso);
        SDL_Flip(screen);// mise a jour de l'ecran
    }

    Mix_FreeMusic(music);
    SDL_Quit();
    return 0;
}

