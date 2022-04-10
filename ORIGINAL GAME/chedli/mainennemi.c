#include "ennemi.h"

void main()
{
//      ***************************INITIALISATION***************************
	SDL_Surface *screen = NULL;
	SDL_Event event;
	Ennemi e;
	image back;
	SDL_Rect posmousse;
	int cont = 1;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
 	{
		printf("Unable to initialisation SDL : %s\n",SDL_GetError());
	}
	SDL_WM_SetCaption("ENNEMI",NULL);
	screen = SDL_SetVideoMode(1380,700,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL)
	{
		printf("error : %s\n",SDL_GetError());
	}
	
	back.img = IMG_Load ("file.jpg");
	back.pos.x = 0;
	back.pos.y = 0;
	
	initEnnemi(&e);
//      ***************************BOUCLE***************************
	e.level=1;
		e.etat=0;
	while (cont)
	{SDL_PollEvent(&event);
	SDL_BlitSurface(back.img,NULL,screen,&back.pos);	
	afficherEnnemi(e,screen);	
	animerEnnemi(&e);
	deplacer(&e);
	switch(e.etat)
	{
	case 0:
	if (event.type == SDL_MOUSEMOTION)
	{
	posmousse.x=event.motion.x;
	posmousse.y=event.motion.y;
		if(collisionBox(posmousse, e.pos[e.level])==1)
		e.etat=1;
		break;}}
		SDL_Delay(150);
		SDL_PollEvent(&event);	
		if ((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE))
				cont = 0;
	
					
		SDL_Flip(screen);
	}
	SDL_Quit();
}
