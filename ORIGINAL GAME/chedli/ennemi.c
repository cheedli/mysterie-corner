#include "ennemi.h"


void initEnnemi(Ennemi *e[] )
{
int i;
e[0]->image =IMG_Load("graphic/menu/.png");
e[1]->image =IMG_Load("graphic/menu/.png");
e[2]->image =IMG_Load("graphic/menu/.png");
e[3]->image =IMG_Load("graphic/menu/.png");

for(i=0;i<3;i++)
{
e[i]->pos.x=0;
e[i]->pos.y=0;
e[i]->pos.h=e[i]->img->h;
e[i]->posw.w=e[i]->img->w;
}

}

void afficherEnnemi(Ennemi e, SDL_Surface * screen,SDL_Rect pos)
{
SDL_Blitsurface(e.img,&e.pos2,screen,pos);
}

void animerEnnemi( Ennemi * e)

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
