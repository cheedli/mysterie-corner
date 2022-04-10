#include"test.h"
/*int main()
{
Input I;
uint32_t t0 , dt;
 SDL_Init ( SDL_INIT_VIDEO );
TTF_Init();
int cont =1;
	//declaration des variables
	perso p,w,j,wl;
    SDL_Surface *screen;
    SDL_Event event;
	//affectation de l'ecran en la variable : screen
	screen = SDL_SetVideoMode(1300, 800, 32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
	 if ( !screen )
   	{
        printf("Unable to set video: %s\n", SDL_GetError());
        return 1;
   	}

SDL_Surface *back=NULL;
    SDL_Rect pos;

	initialiser_perso (&p);
	initialiser_walk (&w);
	initialiser_jump (&j);
back= IMG_Load("pic/w.jpg");
    pos.x=0;
    pos.y=0;



	SDL_BlitSurface(back, NULL, screen, NULL);
while(cont)
{t0=SDL_GetTicks();



      SDL_PollEvent(&event);
if ((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE))
				{cont = 0;}
				    



		
	SDL_Flip(screen);

        switch(event.type)
        {
        case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	{

 case SDLK_RIGHT:
	I.right=1;

break;
case SDLK_LEFT:
I.left=1;
break;
case SDLK_UP :
I.jump=1;

break;
}
}


if(I.right==1)
{
p.direction=2;
w.acceleration+=0.5;
w.vitesse=5;}
 
else if(I.left==1)
{p.direction=3;
wl.acceleration-=0.5;
wl.vitesse=5;}
/*
if(I.jump==1)
{saut(&j);}

SDL_Delay(4);
dt=SDL_GetTicks() - t0;
   
if(p.direction==2)
{movePerso(&w,dt);



w.acceleration-=0.2;
if (w.acceleration<=0)
{
	w.acceleration=0;
}
if (w.acceleration>=0.7)
{
	w.acceleration=0.7;
}

} else if(p.direction==3)
{
movePerso(&wl,dt);
wl.acceleration+=0.2;
if (wl.acceleration<=0)
{
	wl.acceleration=0;
}
if (wl.acceleration>=0.7)
{
	wl.acceleration=0.7;
}

}





  if(I.right==1)
{
	animation(&w);
	SDL_BlitSurface(back, NULL, screen, NULL);
	afficher_perso (w,screen);
} else if (I.left==1)
{
animation(&wl);
	SDL_BlitSurface(back, NULL, screen, NULL);
	afficher_perso (wl,screen);
}


	SDL_Flip(screen);//trefraichi l page
	SDL_Delay(70);//tstana 70 tekhou rahatha

//ajout de libere 
}SDL_Quit();
return 0 ;
}*/

#define GRAVITY 10// lzm haja tnaks f vitesse verticale bch ynajm ynagz


int main()
{
TTF_Init();
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen;
screen=SDL_SetVideoMode (1500,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre



Input I;
perso p,w,wl,j;

SDL_Event event;
SDL_Surface *back;

initialiser_wl(&wl);
initialiser_walk (&w);
initialiser_perso (&p);
initialiser_jump (&j);
initialiser_input (&I);

uint32_t t0 , dt;//type c'est uint
bool running=true;
back=IMG_Load("pic/w.jpg");




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
				p.direction=0;
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

	saut(&j);
}

SDL_Delay(4);//yekber lwakt dt
dt=SDL_GetTicks() - t0;


if(I.right==1)

{movePerso(&w,dt,I);}
else if (I.left==1)
{movePerso(&wl,dt,I);}



	p.acceleration-=0.02;// k nsayb l bouton

if (p.acceleration<=0)
{
	p.acceleration=0;
}
if (p.acceleration>=0.7)
{
	p.acceleration=0.7;
}



j.vitesse_V+=GRAVITY;//vitesse verticale naks 10 tjrs
 j.rect.y += j.vitesse_V;//yzidha -60
 if(j.rect.y >= 100)
 	 {
 		 j.rect.y= 100;//wsel ground
 		 j.vitesse_V = 0;//tzidha 10 perso habt khatr wsl
}



if(I.right==1)
{	
	animation(&w,I);
	SDL_BlitSurface(back, NULL, screen, NULL);
	afficher_perso (w,screen);
	wl.rect.x=w.rect.x;
	j.rect.x=w.rect.x;
}
else if (I.left==1)
{

	animation(&wl,I);
	SDL_BlitSurface(back, NULL, screen, NULL);
	afficher_perso (wl,screen);
	w.rect.x=wl.rect.x;
	j.rect.x=wl.rect.x;
}
else if(I.jump==1)
{	//j.rect.x=p.rect.x;
	animation(&j,I);
	SDL_BlitSurface(back, NULL, screen, NULL);
	afficher_perso (j,screen);
	w.rect.x=j.rect.x;
	wl.rect.x=j.rect.x;
}



	SDL_Flip(screen);//trefraichi l page
	SDL_Delay(70);//tstana 70 tekhou rahatha
}
TTF_Quit();




}




