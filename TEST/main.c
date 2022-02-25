#include"header.h"
int main(int argc, char** argv)

{

TTF_Init();
SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO );
text t ;//declarer ça seulement s'il y a text
image background,picture;
SDL_Surface *screen;
SDL_Event event;

int done=1 ;

//affectation de l'ecran en la variable : screen

screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
if ( !screen )
   	{

        printf("Unable to set video: %s\n", SDL_GetError());
        return 1;

   	}
//INITIALISATION D'IMAGE ET DE TEXT

initialiser_background(&background);
initialiser_image(&picture); 
initText(&t);//declarer ça seulement s'il y a text

//introduction musique


    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);

//background music

    Mix_Music *music;   	
    music= Mix_LoadMUS("OPENMUSIC.mp3");
    Mix_VolumeMusic(100);
    Mix_PlayMusic(music,-1);//jouer la music du background

	if (music==NULL)
   	 {
       		 printf("xxxxxx:%s",Mix_GetError());
   	 }

//son bref

    	Mix_Chunk *swing ;		
  	swing= Mix_LoadWAV("swing.wav");
	Mix_VolumeChunk(swing,100);
	if (swing==NULL)
   	 {
       		 printf("xxxxxx:%s",Mix_GetError());
   	 }
 while (done)
    {
	//affichage 

	afficher(background,screen);
	afficher(picture,screen);

	//refrichessement d'ecran

	SDL_Flip(screen);

	SDL_PollEvent(&event);

        switch(event.type)
        {


		case SDL_QUIT:

			return(0);
                 break;
        }


    }

TTF_Quit();
SDL_Quit();//cette fonction va liberer tous
return 0 ;
}




