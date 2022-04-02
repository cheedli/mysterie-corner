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

void initexte(texte *A)
{
    A->position.x=0;
    A->position.y=0; 
// couleur noir
    A->textColor.r=255;
    A->textColor.g=255;
    A->textColor.b=255;

    A->font = TTF_OpenFont( "font.ttf", 50 );
}


void displayText(texte t,SDL_Surface *screen,char cc[20])
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, cc, t.textColor );
    SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}


