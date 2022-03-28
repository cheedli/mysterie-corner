 #include "ennemi.h"


void initEnnemi(Ennemi g[],Ennemi a[],Ennemi l[],Ennemi c[] )
{
int i;

//g is el ghoul

g[0]->image =IMG_Load("graphic/menu/.png");//standing

g[0]->pos2.h=g[0].img->h;
g[0]->pos2.w=g[0].img->w/3;

g[1]->image =IMG_Load("graphic/menu/.png");//dead

g[1]->pos2.h=g[1].img->h;
g[1]->pos2.w=g[1].img->w/3;

//a is azouzet estoot

a[0]->image =IMG_Load("graphic/menu/.png");// going right and left

a[0]->pos2.h=a[0].img->h;
a[0]->pos2.w=a[0].img->w/3;

a[1]->image =IMG_Load("graphic/menu/.png");//attack

a[1]->pos2.h=a[1].img->h;
a[1]->pos2.w=a[1].img->w/3;

a[2]->image =IMG_Load("graphic/menu/.png");//dead

a[2]->pos2.h=a[2].img->h;
a[2]->pos2.w=a[2].img->w/3;


//l is boulaaba

l[0]->image =IMG_Load("graphic/menu/.png");//runing to the player

l[0]->pos2.h=l[0].img->h;
l[0]->pos2.w=l[0].img->w/3;

l[1]->image =IMG_Load("graphic/menu/.png");//attacking

l[1]->pos2.h=l[1].img->h;
l[1]->pos2.w=l[1].img->w/3;

//c is bouchkara

c[0]->image =IMG_Load("graphic/menu/.png");//coming to the player

c[0]->pos2.h=c[0].img->h;
c[0]->pos2.w=c[0].img->w/3;

c[1]->image =IMG_Load("graphic/menu/.png");//attacking

c[1]->pos2.h=c[1].img->h;
c[1]->pos2.w=c[1].img->w/3;

c[2]->image =IMG_Load("graphic/menu/.png");//dead

c[2]->pos2.h=c[2].img->h;
c[2]->pos2.w=c[2].img->w/3;

for(i=0;i<3;i++)

	{
		g[i]->pos.x=0;
		g[i]->pos.y=0;

		a[i]->pos.x=0;
		a[i]->pos.y=0;

		c[i]->pos.x=0;
		c[i]->pos.y=0;

		l[i]->pos.x=0;
		l[i]->pos.y=0;	
	}

}

void afficherEnnemi(Ennemi e, SDL_Surface * screen,SDL_Rect pos)
{		
SDL_Blitsurface(e.img,&e.pos2,screen,pos);
}
void animerEnnemi( Ennemi * e)
{
	
			if(e->pos2.x == 1200)
				e->pos2.x = 0;
			else
				e->pos2.x = e->pos2.x + e->pos2.w;
			
	
}			

int collisionBox(SDL_Rect a, SDL_Rect b)
{
	int leftSideA = a.x;
	int rightSideA = a.x + a.w;
	int topA = a.y;
	int bottomA = a.y + a.h;

	int leftSideB = b.x;
	int rightSideB = b.x + b.w;
	int topB = b.y;
	int bottomB = b.y + b.h;

	if(bottomA <= topB)
	{
		return 0;
	}

	if(topA >= bottomB)
	{
		return 0;
	}

	if(rightSideA <= leftSideB)
	{
		return 0;
	}

	if(leftSideA >= rightSideB)
	{
		return 0;
	}

	return 1;
}
