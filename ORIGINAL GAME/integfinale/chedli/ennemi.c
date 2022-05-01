
/**
* @file ennemi.c
* @brief Testing Program.
* @author Chedly
* @version 0.1
* @date Apr 22 , 2022
*
* Testing program for colision *
*/


#include "ennemi.h"

/**
* @brief To initialize ENNEMI .
* @param e is the ennemi
* @return Nothing
*/


void initEnnemi(Ennemi *e)
{
    int i;

    //g is el ghoul
    /*
        e->en.g[0] =IMG_Load("graphic/menu/.png");//standing
        e->en.g[1] =IMG_Load("graphic/menu/.png");//dead

        e->en.posg[0].x=0;
        e->en.posg[0].y=0;
        e->en.posg[0].h=e->en.g[0]->h;
        e->en.posg[0].w=e->en.g[0]->w/3;

        e->en.posg[1].x=0;
        e->en.posg[1].y=0;
        e->en.posg[1].h=e->en.g[1]->h;
        e->en.posg[1].w=e->en.g[1]->w/3;
    */





    //a is azouzet estoot


    e->en.a[0]=IMG_Load("ennemi/a/as.png");    // going right and left
    e->en.a[1] =IMG_Load("ennemi/a/ashitt.png");//attack
    e->en.a[2] =IMG_Load("ennemi/a/asdead.png");//dead


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

    //l is boulaaba

    e->en.l[0] =IMG_Load("ennemi/bl/bl.png");//runing to the player

    e->en.posl[0].h=e->en.l[0]->h;
    e->en.posl[0].w=e->en.l[0]->w/8;

    e->en.l[1]=IMG_Load("ennemi/bl/hit.png");//attacking

    e->en.posl[1].h=e->en.l[1]->h;
    e->en.posl[1].w=e->en.l[1]->w/4;



    //c is bouchkara

    e->en.c[0] =IMG_Load("ennemi/bc/walk.png");//coming to the player

    e->en.posc[0].h=e->en.c[0]->h;
    e->en.posc[0].w=e->en.c[0]->w/8;

    e->en.c[1] =IMG_Load("ennemi/bc/a.png");//attacking

    e->en.posc[1].h=e->en.c[1]->h/2;
    e->en.posc[1].w=e->en.c[1]->w/17;

    e->en.c[2] =IMG_Load("ennemi/bc/dead.png");//dead

    e->en.posc[2].h=e->en.c[2]->h;
    e->en.posc[2].w=e->en.c[2]->w/8;

    for(i=0; i<3; i++)

    {
        e->pos[0].x=50;
        e->pos[0].y=0;

        e->pos[1].x=500;
        e->pos[1].y=320;
        e->pos[1].h=e->en.a[0]->h;
        e->pos[1].w=e->en.a[0]->w/10;


        e->pos[2].x=500;
        e->pos[2].y=320;
        e->pos[2].h=e->en.l[0]->h;
        e->pos[2].w=e->en.l[0]->w/8;

        e->pos[3].x=500;
        e->pos[3].y=320;
        e->pos[3].h=e->en.c[0]->h;
        e->pos[3].w=e->en.c[0]->w/8;
    }
}

/**
* @brief To show ENNEMI .
* @param e is the ennemi
* @param screen is the screen
* @return Nothing
*/



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
        SDL_BlitSurface(e.en.c[e.etat],&e.en.posc[e.etat],screen,&e.pos[e.level]);
        break;

    }

}

/**
* @brief To animate ENNEMI .
* @param e is the ennemi
* @param screen is the screen
* @return Nothing
*/

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
            SDL_Delay(230);

            break;
        case 1:
            if(e->en.posa[e->etat].x <800)
                e->en.posa[e->etat].x +=  e->en.posa[e->etat].w;
            else
            {
                e->en.posa[e->etat].x =0;

            }
            SDL_Delay(120);

            break;
        case 2:
            if(e->en.posa[e->etat].x <1000)
            {
                e->en.posa[e->etat].x +=  e->en.posa[e->etat].w;
            }

            SDL_Delay(400);

            break;

        }
        break;

    case 2:
        switch(e->etat)
        {
        case 0:
            if(e->en.posl[e->etat].x <1400)
                e->en.posl[e->etat].x +=  e->en.posl[e->etat].w;
            else
            {
                e->en.posl[e->etat].x =0;
                e->pos[e->level].x =500;
            }
            SDL_Delay(230);

            break;
        case 1:
            if(e->en.posl[e->etat].x <600)
                e->en.posl[e->etat].x +=  e->en.posl[e->etat].w;
            else
            {
                e->en.posl[e->etat].x =0;

            }
            SDL_Delay(50);

            break;


        }
        break;
    case 3:
        switch(e->etat)
        {
        case 0:
            if(e->en.posc[e->etat].x <1400)
                e->en.posc[e->etat].x +=  e->en.posc[e->etat].w;
            else
            {
                e->en.posc[e->etat].x =0;
                e->pos[e->level].x =500;
            }
            SDL_Delay(230);
            break ;

        case 1:
            if(e->en.posc[e->etat].x <4800)

                e->en.posc[e->etat].x +=  e->en.posc[e->etat].w;
            else
            {

                e->en.posc[e->etat].x =0;
                e->en.posc[e->etat].y +=  e->en.posc[e->etat].h;

            }

            SDL_Delay(300);

            break;


        }

    }
}
/**
* @brief To deplace ENNEMI .
* @param e is the ennemi
* @return nothing
*/
void deplacerIA(Ennemi *e)
{
    switch(e->level)
    {
    case 1:
        switch(e->etat)
        {
        case 0:

            if(e->en.posa[e->etat].x >=1000)
            {
                e->pos[e->level].x -= 15;
            }
            else if(e->pos[e->level].x <1000)

                e->pos[e->level].x+=15;
            break ;
        case 1:

            if((e->pos[e->level].x <=1000)&&(e->pos[e->level].x >=400))
            {
                e->pos[e->level].x -= 15;
            }
            break ;

        }
        break;

    case 2:
        switch(e->etat)
        {
        case 0:

            if(e->en.posl[e->etat].x <=800)
            {
                e->pos[e->level].x -= 15;
            }
            else

                e->pos[e->level].x+=15;
            break ;

        case 1:

            if((e->pos[e->level].x <=1000)&&(e->pos[e->level].x >=400))
            {
                e->pos[e->level].x -= 15;
            }
            break ;
        }
        break;

    case 3:
        switch(e->etat)
        {
        case 0:

            if(e->en.posc[e->etat].x <800)
            {
                e->pos[e->level].x -= 0;
            }
            else

                e->pos[e->level].x += 25;
        case 1:

            if((e->pos[e->level].x <=1000)&&(e->pos[e->level].x >=400))
            {
                e->pos[e->level].x -= 15;
            }
            break ;
        }
        break;
    }
}

/**
* @brief To show ENNEMI .
* @param a is the ennemi
* @param b is the player
* @return if there is a colision or not
*/

int collisionBox(SDL_Rect a, SDL_Rect b)
{
    if(a.x+a.w<b.x || a.x>b.x+b.w ||a .y+a.h<b.y || a.y>b.y+b.h)
        return 0;
    else
        return 1;
}

