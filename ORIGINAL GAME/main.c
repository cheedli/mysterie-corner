#include"header.h"
int main(int argc, char** argv)
{

 SDL_Init ( SDL_INIT_VIDEO );

	//declaration des variables

    int done=1,opdone=1,o=0,p=0,q=0,i=0,oo=0;
    image back[16],pl[3],op[3],qu[3],name;
    text t;
    SDL_Surface *screen;
    SDL_Event event;
	//affectation de l'ecran en la variable : screen
	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
	 if ( !screen )
   	{
        printf("Unable to set video: %s\n", SDL_GetError());
        return 1;
   	}

	//initialisation des buttons : play,option,quit et du background

     initquit( qu, pl,op,back,name);
     initText(&t);

	//introduction musique

    int vm=100, vsfx=100;
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_Music *music;   	//background music
    Mix_Chunk *sound ;		//son bref
    music= Mix_LoadMUS("OPENMUSIC.mp3");
    Mix_VolumeMusic(vm);
    Mix_PlayMusic(music,-1);
    sound= Mix_LoadWAV("button.wav");
	
	if (sound==NULL)
   	 {
       		 printf("xxxxxx:%s",Mix_GetError());
   	 }

	//nom du fenetre : MYSTERY CORNER 

    SDL_WM_SetCaption("MYSTERY CORNER", NULL);

    while (done)
    {

	//affichage des bouttons et du background
	
	afficher(back[i],screen);
	oo++;
	afficher(pl[p],screen);
  afficher(op[o],screen);
  afficher(qu[q],screen);
	displayText(t,screen);
	SDL_Flip(screen);
	
	if(oo==12)
	{	
	i++;
	oo=0;
	}

	if (i==15)
	i=0;


        SDL_PollEvent(&event);
        switch(event.type)
        {

	//utilisation du clavier

        case SDL_KEYDOWN:	
						
switch(event.key.keysym.sym)
            {
		p=0;
		q=0;
		o=0;
	
            case SDLK_UP:
               
                if (p==1 )
                {
                        
                    q=1;
                    p=0;
                    o=0;
                }
                else if(o==1 )
                {
                    p=1;
                    o=0;
                    q=0;
                }
                else if (q==1 )
                {
                    o=1;
                    q=0;
                    p=0;
                }
 		if(p==0 && o==0 && q==0)
		{
                    p=1;
		} 
SDL_Delay(100);
		break ;
            case SDLK_DOWN:
                
                if (p==1 )
                {
                    p=0;
                    o=1;
                    q=0;

                }
                else if(o==1 )
                {
                    p=0;
                    o=0;
                    q=1;

                }
                else if (q==1 )
                {
                    o=0;
                    q=0;
                    p=1;

                }
		if (p==0 && o==0 && q==0 )
                {
                    q=1;
                }
SDL_Delay(100);
                break;
            case SDLK_p:
                o=0;
                q=0;
                p=1;
                break;
            case SDLK_q:
                o=0;
                q=1;
                p=0;
								done=0;
                break;
							case SDLK_m:
    					Mix_VolumeMusic(vm);
break;
            case SDLK_o:
                p=0;
                o=1;
                q=0;
                break;
		case SDLK_ESCAPE:

		q=2;
		done=0;
      
		break ;
		case SDLK_KP_ENTER :
 if (p==1)
                {
                    p=2;

                }
                else if (o==1)
                {
                    o=2;

                }

                else if (q==1)
                {
                    q=2;
		    done=0;
                }
break;
            }
            break;

	// utilisiation du souris

        case SDL_MOUSEMOTION: 
            	
		p=0;
		q=0;
		o=0;

            if (event.motion.x>255 && event.motion.y>410 && event.motion.x<405 && event.motion.y<480 )
            {
                p=1;
            }

            else if (event.motion.x>255 && event.motion.y>490 && event.motion.x<405 && event.motion.y<560 )
            {
                o=1;
            }

            else if (event.motion.x>255 && event.motion.y>578 && event.motion.x<405 && event.motion.y<650 )
            {
                q=1;
            }
            break;

	// utilisiation du botton gauche de la  souris

        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button==SDL_BUTTON_LEFT)
            {
                if (p==1)
                {
                    p=2;

                }
                else if (o==1)
                {
                    o=2;

                }

                else if (q==1)
                {
                    q=2;
										SDL_Quit();
		    						done=0;
                }
            }
            break;
case SDL_QUIT:
					return(0);


                                        break;
        }

    }


return 0 ;
}

