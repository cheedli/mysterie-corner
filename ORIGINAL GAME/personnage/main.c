#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Fonctions.h"



#define GRAVITY 10// lzm haja tnaks f vitesse verticale bch ynajm ynagz


int main()
{
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen;
screen=SDL_SetVideoMode (1000,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre



Input I;
perso p;

SDL_Event event;
SDL_Surface *back;


initialiser_perso (&p);
initialiser_input (&I);

uint32_t t0 , dt;//type c'est uint
bool running=true;
back=IMG_Load("graphic/w.jpg");




while(running)
{
t0=SDL_GetTicks();//tsjl wakt a t0

while(SDL_PollEvent(&event))//bch ychouf l event l dkhal
	{

		switch(event.type)
		{
		case SDL_QUIT:

			running=false;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{

			case SDLK_LEFT :
				I.left=1;


      			break;

      			case SDLK_RIGHT :
				I.right=1;
			break;
			case SDLK_UP :
				I.jump=1;

			break;





			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;
				p.direction=0;
				p.vitesse=0;
			break;
			case SDLK_LEFT :
				I.left=0;
				p.direction=3;
				p.vitesse=0;
      		break;

			case SDLK_UP :
				I.jump=0;

			break;

			}
		break;
		}
	}


 if (I.right==1)
{
	p.direction=2;
	p.acceleration+=0.05;
	p.vitesse=5;

}
else if (I.left==1 )
{
	p.direction=1;
	p.acceleration+=0.05;
	p.vitesse=5;


}
if (I.jump==1)
{

	saut(&p);
}

SDL_Delay(4);//yekber lwakt dt
dt=SDL_GetTicks() - t0;
movePerso(&p,dt);

	p.acceleration-=0.02;// k nsayb l bouton

if (p.acceleration<=0)
{
	p.acceleration=0;
}
if (p.acceleration>=0.7)
{
	p.acceleration=0.7;
}



p.vitesse_V+=GRAVITY;//vitesse verticale naks 10 tjrs
 p.rect.y += p.vitesse_V;//yzidha -60
 if(p.rect.y >= 300)
 	 {
 		 p.rect.y= 300;//wsel ground
 		 p.vitesse_V = 0;//tzidha 10 perso habt khatr wsl
}




	animation(&p);
	SDL_BlitSurface(back, NULL, screen, NULL);
	afficher_perso (&p,screen);




	SDL_Flip(screen);//trefraichi l page
	SDL_Delay(70);//tstana 70 tekhou rahatha
}
TTF_Quit();




}



