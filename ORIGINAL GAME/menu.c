
#include "header.h"

///////////////////////////////////////////////////////////////
void initquit(image *q1,image *q21,image *q22,image *q23,image *q31,image *q32,image *q33)
{
    q1->img=IMG_Load("boutons/quit/q1.png");
if ( q1->img== NULL) {
			return ;
		}
	 q1->pos.x =210;
	 q1->pos.y = 500;
    q21->img=IMG_Load("boutons/quit/q21.png");
if ( q21->img== NULL) {
			return ;
		}
	 q21->pos.x =210;
	 q21->pos.y = 500;
    q22->img=IMG_Load("boutons/quit/q22.png");
if ( q22->img== NULL) {
			return ;
		}
	 q22->pos.x =210;
	 q22->pos.y = 500;
    q23->img=IMG_Load("boutons/quit/q23.png");
if ( q23->img== NULL) {
			return ;
		}
	 q23->pos.x =210;
	 q23->pos.y = 500;
    q31->img=IMG_Load("boutons/quit/q31.png");
if ( q31->img== NULL) {
			return ;
		}
	 q31->pos.x =210;
	 q31->pos.y = 500;
    q32->img=IMG_Load("boutons/quit/q32.png");
if ( q32->img== NULL) {
			return ;
		}
	 q32->pos.x =210;
	 q32->pos.y = 500;
    q33->img=IMG_Load("boutons/quit/q33.png");
if ( q33->img== NULL) {
			return ;
		}
	 q33->pos.x =210;
	 q33->pos.y = 500;
}
///////////////////////////////////////////////////////////////


void initoption(image *o1,image *o21,image *o22,image *o23,image *o31,image *o32,image *o33)
{
    o1->img=IMG_Load("boutons/option/o1.png");
if (o1->img== NULL) {
			return ;
		}
	o1->pos.x =210;
	o1->pos.y = 400;
    o21->img=IMG_Load("boutons/option/o21.png");
if ( o21->img== NULL) {
			return ;
		}
	 o21->pos.x =210;
	 o21->pos.y = 400;
    o22->img=IMG_Load("boutons/option/o22.png");
if (o22->img== NULL) {
			return ;
		}
	o22->pos.x =210;
	o22->pos.y = 400;
    o23->img=IMG_Load("boutons/option/o23.png");
if (o23->img== NULL) {
			return ;
		}
	o23->pos.x =210;
	o23->pos.y = 400;
    o31->img=IMG_Load("boutons/option/o31.png");
if (o31->img== NULL) {
			return ;
		}
	o31->pos.x =210;
	o31->pos.y = 400;
    o32->img=IMG_Load("boutons/option/o32.png");
if (o32->img== NULL) {
			return ;
		}
	o32->pos.x =210;
	o32->pos.y = 400;
    o33->img=IMG_Load("boutons/option/o33.png");
if (o33->img== NULL) {
			return ;
		}
	o33->pos.x =210;
	o33->pos.y = 400;
}


///////////////////////////////////////////////////////////////

void initplay(image *p1,image *p21,image *p22,image *p23,image *p31,image *p32,image *p33)
{


    p1->img=IMG_Load("boutons/play/p1.png");
if (p1->img== NULL) {
			return ;
		}
	p1->pos.x = 210;
	p1->pos.y = 320;
    p21->img=IMG_Load("boutons/play/p21.png");
if (p21->img== NULL) {
			return ;
		}
	p21->pos.x = 210;
	p21->pos.y = 320;
    p22->img=IMG_Load("boutons/play/p22.png");
if (p22->img== NULL) {
			return ;
		}
	p22->pos.x = 210;
	p22->pos.y = 320;
    p23->img=IMG_Load("boutons/play/p23.png");
if (p23->img== NULL) {
			return ;
		}
	p23->pos.x = 210;
	p23->pos.y = 320;
    p31->img=IMG_Load("boutons/play/p31.png");
if (p31->img== NULL) {
			return ;
		}
	p31->pos.x = 210;
	p31->pos.y = 320;
    p32->img=IMG_Load("boutons/play/p32.png");
if (p32->img== NULL) {
			return ;
		}
	p32->pos.x = 210;
	p32->pos.y = 320;
    p33->img=IMG_Load("boutons/play/p33.png");
if (p33->img== NULL) {
			return ;
		}
	p33->pos.x = 210;
	p33->pos.y = 320;




}
void initBackground(image *Backg)
{
Backg->img= IMG_Load("background.png");
	if (Backg->img == NULL) {
		printf("Unable to load : %s\n", SDL_GetError());
		return;
		}
	Backg->pos.x=0;
	Backg->pos.y=0;
	Backg->pos.w=SCREEN_W; 
	Backg->pos.h=SCREEN_H;
}
void fre(image A )
{
	SDL_FreeSurface(A.img);   
}
void afficher(image p,SDL_Surface *screen)
{
	SDL_BlitSurface(p.img,NULL,screen,&p.pos);
}
