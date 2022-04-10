#include "ennemi.h"


void initEnnemi(Ennemi *e)

{
    int i;
    /*
    //g is el ghoul

    g[0].img =IMG_Load("graphic/menu/.png");//standing

    g[0].pos2.h=g[0].img->h;
    g[0].pos2.w=g[0].img->w/3;

    g[1].img =IMG_Load("graphic/menu/.png");//dead

    g[1].pos2.h=g[1].img->h;
    g[1].pos2.w=g[1].img->w/3;

    //a is azouzet estoot
    */
   e->etat=0;
   e->en.a[0]=IMG_Load("as.png");    // going right and left
   e->en.a[1] =IMG_Load("ashitt.png");//attack
   e->en.a[2] =IMG_Load("ashitt.png");//dead


    e->en.posa[0].x=0;
    e->en.posa[0].y=0;
    e->en.posa[0].h=e->en.a[0]->h;
    e->en.posa[0].w=e->en.a[0]->w/10;
    
    e->en.posa[1].x=0;
    e->en.posa[1].y=0;
    e->en.posa[1].h=e->en.a[1]->h;
    e->en.posa[1].w=e->en.a[1]->w/5;
    
    e->en.posa[2].x=0;
    e->en.posa[2].y=0;
    e->en.posa[2].h=e->en.a[2]->h;
    e->en.posa[2].w=e->en.a[2]->w/5;
    

									
    
/*
    a[2].img =IMG_Load("graphic/menu/.png");//dead

    a[2].pos2.h=a[2].img->h;
    a[2].pos2.w=a[2].img->w/3;


    //l is boulaaba

    l[0].img =IMG_Load("graphic/menu/.png");//runing to the player

    l[0].pos2.h=l[0].img->h;
    l[0].pos2.w=l[0].img->w/3;

    l[1].img =IMG_Load("graphic/menu/.png");//attacking

    l[1].pos2.h=l[1].img->h;
    l[1].pos2.w=l[1].img->w/3;

    //c is bouchkara

    c[0].img =IMG_Load("graphic/menu/.png");//coming to the player

    c[0].pos2.h=c[0].img->h;
    c[0].pos2.w=c[0].img->w/3;

    c[1].img =IMG_Load("graphic/menu/.png");//attacking

    c[1].pos2.h=c[1].img->h;
    c[1].pos2.w=c[1].img->w/3;

    c[2].img =IMG_Load("graphic/menu/.png");//dead

    c[2].pos2.h=c[2].img->h;
    c[2].pos2.w=c[2].img->w/3;
    */
    for(i=0; i<3; i++)

    {
        e->pos[0].x=50;
        e->pos[0].y=0;

        e->pos[1].x=500;
        e->pos[1].y=320;

        e->pos[2].x=0;
        e->pos[2].y=0;

        e->pos[3].x=0;
        e->pos[3].y=0;
    }

}

void afficherEnnemi(Ennemi e, SDL_Surface * screen)

{
    switch (e.level)
    {
    case 0:
        SDL_BlitSurface(e.en.g[e.etat],&e.en.posg[e.etat],screen,&e.pos[e.level]);
        break;
    case 1:
        SDL_BlitSurface(e.en.a[e.etat],&e.en.posa[e.etat],screen,&e.pos[e.level]);
        break;
    case 2:
        SDL_BlitSurface(e.en.l[e.etat],&e.en.posl[e.etat],screen,&e.pos[e.level]);
        break;
    case 3:
        SDL_BlitSurface(e.en.b[e.etat],&e.en.posb[e.etat],screen,&e.pos[e.level]);
        break;
    }
}

void animerEnnemi( Ennemi * e)

{
switch(e->level)
{
case 1:
switch(e->etat)
{
case 0:
    if(e->en.posa[e->etat].x <1800)
        e->en.posa[e->etat].x +=  e->en.posa[e->etat].w;
    else
    {
        e->en.posa[e->etat].x =0;
        e->pos[e->level].x =500;
    }
    SDL_Delay(300);
break;
case 1:
    if(e->en.posa[e->etat].x <800)
        e->en.posa[e->etat].x +=  e->en.posa[e->etat].w;
    else
    {
        e->en.posa[e->etat].x =0;
        e->pos[e->level].x =500;
    }
    SDL_Delay(300);

}
break;
}
}

void deplacer(Ennemi *e)
{
switch(e->level)
{
case 1:
    if(e->en.posa[e->etat].x >=1000)
    {
        e->pos[e->level].x -= 15;
    }
    else if(e->pos[e->level].x <1000)

        e->pos[e->level].x+=15;
        break ; 
        }

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

