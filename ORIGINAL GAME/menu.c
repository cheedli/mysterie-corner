
#include "header.h"

///////////////////////////////////////////////////////////////
void initquit(image q[],image p[],image o[],image back[],image name)
{
int i;
    name.img=IMG_Load("ob.jpg");
if (name.img== NULL) {
			printf("hhhhh");
			return ;
		}
	name.pos.x = 310;
	name.pos.y = 320;

    q[0].img=IMG_Load("boutons/quit/q1.png");
    q[1].img=IMG_Load("boutons/quit/q2.png");
    q[2].img=IMG_Load("boutons/quit/q3.png");
    
    o[0].img=IMG_Load("boutons/option/o1.png");
    o[1].img=IMG_Load("boutons/option/o2.png");
    o[2].img=IMG_Load("boutons/option/o3.png");
   
    p[0].img=IMG_Load("boutons/play/p1.png");
    p[1].img=IMG_Load("boutons/play/p2.png");
    p[2].img=IMG_Load("boutons/play/p3.png");
    
    back[0].img= IMG_Load("boutons/background/0.gif");
    back[1].img= IMG_Load("boutons/background/1.gif");
    back[2].img= IMG_Load("boutons/background/2.gif");
    back[3].img= IMG_Load("boutons/background/3.gif");
    back[4].img= IMG_Load("boutons/background/4.gif");
    back[5].img= IMG_Load("boutons/background/5.gif");
    back[6].img= IMG_Load("boutons/background/6.gif");
    back[7].img= IMG_Load("boutons/background/7.gif");
    back[8].img= IMG_Load("boutons/background/8.gif");
    back[9].img= IMG_Load("boutons/background/9.gif");
    back[10].img= IMG_Load("boutons/background/10.gif");
    back[11].img= IMG_Load("boutons/background/11.gif");
    back[12].img= IMG_Load("boutons/background/12.gif");
    back[13].img= IMG_Load("boutons/background/13.gif");
    back[14].img= IMG_Load("boutons/background/14.gif");
    back[15].img= IMG_Load("boutons/background/15.gif");

for(i=0;i<3;i++)
{
if ( q[i].img== NULL) {
			return ;
		}
	 q[i].pos.x =210;
	 q[i].pos.y = 500;
if (o[i].img== NULL) {
			return ;
		}
	o[i].pos.x =210;
	o[i].pos.y = 400;
if (p[i].img== NULL) {
			return ;
		}
	p[i].pos.x = 210;
	p[i].pos.y = 320;
}

for(i=0;i<16;i++)
{
if (back[i].img == NULL) 
	{
	printf("Unable to load : %s\n", SDL_GetError());
	return;
	}
	back[i].pos.x=0;
	back[i].pos.y=0; 
	back[i].pos.w=SCREEN_W; 
	back[i].pos.h=SCREEN_H;
}

    
}
///////////////////////////////////////////////////////////////

void liberer(image A )
{
	SDL_FreeSurface(A.img);   
}
void afficher(image A,SDL_Surface *screen)
{
	SDL_BlitSurface(A.img,NULL,screen,&A.pos);
}
void initText(text *A)
{
    A->position.x=550;
    A->position.y=200; 
// couleur noir
    A->textColor.r=0;
    A->textColor.g=0;
    A->textColor.b=0;

    A->font = TTF_OpenFont( "graphic/menu/style.otf", 70 );
}


void freeText(text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}


void displayText(text t,SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "© THE TELLERS", t.textColor );
    SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}

