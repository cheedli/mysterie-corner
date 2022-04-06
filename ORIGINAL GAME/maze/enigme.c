#include "header.h"
void init_enigme( enigme es[] ,enigme *back,enigme timer[] )
{

int i ;
timer[0].img =IMG_Load("timer/0.gif");
timer[1].img =IMG_Load("timer/1.gif");
timer[2].img =IMG_Load("timer/2.gif");
timer[3].img =IMG_Load("timer/3.gif");
timer[4].img =IMG_Load("timer/4.gif");
timer[5].img =IMG_Load("timer/5.gif");
timer[6].img =IMG_Load("timer/6.gif");
timer[7].img =IMG_Load("timer/7.gif");
timer[8].img =IMG_Load("timer/8.gif");
timer[9].img =IMG_Load("timer/9.gif");




for(i=0;i<10;i++)
{
if (timer[i].img==NULL)
	{	
		printf ("erreur");
		return ;
	}
timer[i].pos.x = 1200;
timer[i].pos.y = 0;

}
back->img =IMG_Load("m.png");
if (back->img==NULL)
	{	
		printf ("erreur");
		return ;
	}
back ->pos.x = 0 ;
back ->pos.y = 0;

es[0].img =IMG_Load("ms/m1.png");
es[2].img =IMG_Load("ms/m2.png");
es[4].img =IMG_Load("ms/m3.png");

es[1].img =IMG_Load("mb/m1.png");
es[3].img =IMG_Load("mb/m2.png");
es[5].img =IMG_Load("mb/m3.png");


for(i=0;i<6;i++)
{

if ((es[i].img==NULL))
	{
		printf ("erreur");
		return ;
	}
	
	

}
es[0].pos.x = 170 ;
es[0].pos.y = 350;


es[2].pos.x = 520 ;
es[2].pos.y = 350;

es[4].pos.x = 910 ;
es[4].pos.y = 350;

es[1].pos.x = 150 ;
es[1].pos.y = 300;

es[3].pos.x = 500;
es[3].pos.y = 300;

es[5].pos.x = 880 ;
es[5].pos.y = 300;

}

void afficherEnigme(enigme e, SDL_Surface * screen)

{
SDL_BlitSurface (e.img,NULL,screen,&e.pos);
}
void animer (enigme *e)
{
TTF_Init();
//      ***************************INITIALISATION***************************
	SDL_Surface *screen ;
	SDL_Event event;
	enigme es[6] , timer[10],back;
	int  a=0,b=2,c=4;
	int cont = 1;
	int o,t=0,i=0;
	  char cc[20];
		text tt;
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

  sprintf(cc, ":0%d", t);



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
    if(t==10)
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

}

void initexte(text *A)
{
    A->position.x=1240;
    A->position.y=15; 
// couleur noir
    A->textColor.r=255;
    A->textColor.g=255;
    A->textColor.b=255;

    A->font = TTF_OpenFont( "police.ttf", 20 );
}


void displayText(text t,SDL_Surface *screen,char cc[30])
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, cc, t.textColor );
    SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}
