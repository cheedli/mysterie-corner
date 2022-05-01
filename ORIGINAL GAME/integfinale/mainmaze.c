#include "maze.h"

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
 // ************son bref*****************

    int v=100;
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_Chunk *music[2];
    music[1]=Mix_LoadWAV("true.wav");
    music [0]=Mix_LoadWAV("false.wav");
    Mix_VolumeChunk(music[1],v);
    Mix_VolumeChunk( music [0],v);
    if ((music[1] == NULL)||( music [0] == NULL))
    {
        printf("XXXXXXXXXX: %s\n", Mix_GetError());
    }



while(done)
{
Mix_PlayChannel(-1, music[e.reponsejuste], 0);

    SDL_BlitSurface(resultat[e.reponsejuste],NULL,screen,&pos);
    SDL_PollEvent(&event);

        if ((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE))
            done = 0;
        SDL_Flip(screen);
    
    
    }


	SDL_Quit();}

