#include "header.h"
///////////////////////////////////////////////////////////////

void inp(image *m)
{
int i ;
m->img=IMG_Load("boutons/inoption/music.png");

if (m->img== NULL) {
			printf("hhhhh");
			return ;
		}
	m->pos.x = 160;
	m->pos.y = 400;




}
void inti_in_option(image l[],image ll[],image *backo)
{
int i;
backo->img=IMG_Load("boutons/inoption/option.png");

if (backo->img== NULL) {
			printf("hhhhh");
			return ;
		}
	backo->pos.x = 50;
	backo->pos.y = 220;

l[0].img=IMG_Load("boutons/inoption/0.png");
l[1].img=IMG_Load("boutons/inoption/25.png");
l[2].img=IMG_Load("boutons/inoption/50.png");
l[3].img=IMG_Load("boutons/inoption/75.png");
l[4].img=IMG_Load("boutons/inoption/100.png");

ll[0].img=IMG_Load("boutons/inoption/0.png");
ll[1].img=IMG_Load("boutons/inoption/25.png");
ll[2].img=IMG_Load("boutons/inoption/50.png");
ll[3].img=IMG_Load("boutons/inoption/75.png");
ll[4].img=IMG_Load("boutons/inoption/100.png");


for(i=0;i<5;i++)
	{

	if ( l[i].img== NULL) 
		{
			return ;
		}
	 l[i].pos.x =30;
	 l[i].pos.y = 320;

	if ( ll[i].img== NULL) 
		{
			return ;
		}
	 ll[i].pos.x =30;
	 ll[i].pos.y = 400;
	}
}


void init(image q[],image p[],image o[],image back[],image so[],image m[],image sc[],image *name ,image yes[],image no[] , image *yesornooption)
{

int i;




    name->img=IMG_Load("name.png");
if (name->img== NULL) {
			printf("hhhhh");
			return ;
		}
	name->pos.x = 50;
	name->pos.y = 50;

    q[0].img=IMG_Load("boutons/quit/q1.png");
    q[1].img=IMG_Load("boutons/quit/q2.png");
    q[2].img=IMG_Load("boutons/quit/q3.png");
    
    o[0].img=IMG_Load("boutons/option/o1.png");
    o[1].img=IMG_Load("boutons/option/o2.png");
    o[2].img=IMG_Load("boutons/option/o3.png");
   
    p[0].img=IMG_Load("boutons/play/p1.png");
    p[1].img=IMG_Load("boutons/play/p2.png");
    p[2].img=IMG_Load("boutons/play/p3.png");
    
    back[0].img= IMG_Load("boutons/background/0.png");
    back[1].img= IMG_Load("boutons/background/1.png");
    back[2].img= IMG_Load("boutons/background/2.png");
    back[3].img= IMG_Load("boutons/background/3.png");
    back[4].img= IMG_Load("boutons/background/4.png");
    back[5].img= IMG_Load("boutons/background/5.png");
    back[6].img= IMG_Load("boutons/background/6.png");
    back[7].img= IMG_Load("boutons/background/7.png");
    back[8].img= IMG_Load("boutons/background/8.png");
    back[9].img= IMG_Load("boutons/background/9.png");
    back[10].img= IMG_Load("boutons/background/10.png");
    back[11].img= IMG_Load("boutons/background/11.png");
    back[12].img= IMG_Load("boutons/background/12.png");
    back[13].img= IMG_Load("boutons/background/13.png");
    back[14].img= IMG_Load("boutons/background/14.png");
    back[15].img= IMG_Load("boutons/background/15.png");
   
    sc[0].img=IMG_Load("boutons/score/sc0.png");
    sc[1].img=IMG_Load("boutons/score/sc1.png");

    so[0].img=IMG_Load("boutons/solo/so0.png");
    so[1].img=IMG_Load("boutons/solo/so1.png");

    m[0].img=IMG_Load("boutons/multiplayer/m0.png");
    m[1].img=IMG_Load("boutons/multiplayer/m1.png");

   
    yes[0].img=IMG_Load("boutons/yes/y0.png");
    yes[1].img=IMG_Load("boutons/yes/y1.png");

    no[0].img=IMG_Load("boutons/no/n0.png");
       no[1].img=IMG_Load("boutons/no/n1.png");

yesornooption->img=IMG_Load("boutons/yesornooption.png");
yesornooption->pos.x =100;
yesornooption->pos.y = 144;


for(i=0;i<2;i++)
{
if ( sc[i].img== NULL) {
			return ;
		}
	 sc[i].pos.x =210;
	 sc[i].pos.y = 205;


if ( so[i].img== NULL) {
			return ;
		}
	 so[i].pos.x =210;
	 so[i].pos.y = 440;


if ( m[i].img== NULL) {
			return ;
		}
	 m[i].pos.x =210;
	 m[i].pos.y = 440;


if (yes[i].img== NULL) {
			return ;
		}
        yes[i].pos.x = 30;
	yes[i].pos.y = 388;

if (no[i].img== NULL) {
			return ;
		}
        no[i].pos.x = 240;
	no[i].pos.y = 388;



}
for(i=0;i<3;i++)
{
if ( q[i].img== NULL) {
			return ;
		}
	 q[i].pos.x =210;
	 q[i].pos.y = 450;
if (o[i].img== NULL) {
			return ;
		}
	o[i].pos.x =210;
	o[i].pos.y = 330;
if (p[i].img== NULL) {
			return ;
		}
	p[i].pos.x = 210;
	p[i].pos.y = 100;



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

///////////////////////////////////////////////////////////////
void initText(text *A)
{
    A->position.x=0;
    A->position.y=0; 
// couleur noir
    A->textColor.r=0;
    A->textColor.g=0;
    A->textColor.b=0;

    A->font = TTF_OpenFont( "font.ttf", 10 );
}


void displayText(text t,SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "THE TELLERS", t.textColor );
    SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}
void freeText(text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}
