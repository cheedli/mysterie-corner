#include "header.h"

void main()
{
//      ***************************INITIALISATION***************************
	SDL_Surface *screen = NULL;
	SDL_Event event;
	enigme es[6] , timer[10],back;
	int  a=0,b=2,c=4;
	int cont = 1;
	int o,t=0,i=0;
	  char cc[20];
		texte tt;
    	time_t start,end;
    start=clock();
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
 	{
		printf("Unable to initialisation SDL : %s\n",SDL_GetError());
	}
	SDL_WM_SetCaption("ENIGME",NULL);
	screen = SDL_SetVideoMode(1300,780,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL)
	{
		printf("error : %s\n",SDL_GetError());
	}
	init_enigme(es,&back,timer );
	
	initexte(&tt);

 

	
//      ***************************BOUCLE***************************
	
	while (cont)
	{	 

  sprintf(cc, ": %d", t);



      afficherEnigme(back, screen);

  	afficherEnigme(timer[t], screen);
  	afficherEnigme(es[a], screen);
    	afficherEnigme(es[b], screen);
      	afficherEnigme(es[c], screen);
      	       displayText(tt,screen,cc);
      SDL_PollEvent(&event);
      
      end=clock();
t=(end-start)/CLOCKS_PER_SEC;

if(o!=t)
    printf("%d\n",t);
    if(t==9)
    {
        cont=0;
    }
    o=t;
    	
		if ((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE))
				cont = 0;	
		SDL_Flip(screen);
		a=0;
			b=2;
			c=4;

		
		switch(event.type)
        {
        
	case SDL_KEYDOWN:
					SDL_Delay(120);	

	switch(event.key.keysym.sym)
	{
	
	
	             case SDLK_a:
	             if(a!=0)
			a=0;
		else 
			{
			a=1;
			
			
			
			}
	              break;
	              case SDLK_q:
			if(a!=0)
			a=0;
		else 
			{
			a=1;
			
			
			}
	              break;
	               case SDLK_b:
	               if(b!=2)
			b=2;
		else 

			{

			b=3;

			
			}
	              break;
	               case SDLK_c:
	               if(c!=4)
			c=4;
		else 

	               
{
			
			c=5;
			
			}
	              break;
	              		
	              
	            
	
	}	              break;
	case SDL_MOUSEMOTION: 
            	
		
			
            if (event.motion.x>170&& event.motion.y>350 && event.motion.x<380&& event.motion.y<600)
     
            a=1;
            
            if (event.motion.x>520&& event.motion.y>350 && event.motion.x<710&& event.motion.y<600)
     
            b=3;
            
            if (event.motion.x>880&& event.motion.y>350 && event.motion.x<1090&& event.motion.y<600)
     
            c=5;
            
	break;
	
            	
	}
	

	}
	SDL_Quit();
}
