#include "header.h"

void initialiser_background(image *background)

	{
	background->img=IMG_Load("boutons/inoption/music.png");

	if (background->img== NULL)
		 {
			printf("hhhhh");
			return ;
		}
	background->pos.x = 0;
	background->pos.y = 0;

	}

void initialiser_image(image *m)

	{
	m->img=IMG_Load("boutons/inoption/music.png");

	if (m->img== NULL)
		 {
			printf("hhhhh");
			return ;
		}
	m->pos.x = 160;
	m->pos.y = 400;
	}



void afficher(image A,SDL_Surface *screen)
{
	SDL_BlitSurface(A.img,NULL,screen,&A.pos);
}

void liberer_image(image A )
{
	SDL_FreeSurface(A.img);   
}


//PARTIE TEXT 

void initText(text *A)
{
    A->position.x=0;
    A->position.y=0; 
// couleur noir
    A->textColor.r=0;
    A->textColor.g=0;
    A->textColor.b=0;

    A->font = TTF_OpenFont( "font.ttf", 10 );//"font.ttf" est le nom du font du text s'il ya un text change le nom du font
}


void displayText(text t,SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "THE TELLERS", t.textColor );//"THE TELLERS"est le text qu'on veut afficher s'il ya d'autre text changer le text
    SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}
void freeText(text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}

