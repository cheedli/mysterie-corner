#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "perso.h"
int n;
void initBack(background *b)
{
//initialisation mta3 les image ly bch nest7a9ohom ly houma 3 background o leur masque(l masque bch nest7a9ouh lil colision baadika)

    b->image[0] = IMG_Load("back/n2.png");
    b->image[1] = IMG_Load("back/g.png");
    b->image[2] = IMG_Load("back/2.png");

    b->masque[0]=IMG_Load("back/masquen2.png");
    b->masque[1]=SDL_LoadBMP("back/1masque.bmp");
    b->masque[2]=SDL_LoadBMP("back/2masque.bmp");


//initialisation t3 l bird pour la fonction d'animation

    b->bird[0] = IMG_Load("back/anim/0.gif");
    b->bird[1] = IMG_Load("back/anim/1.gif");
    b->bird[2] = IMG_Load("back/anim/2.gif");
    //initialisation mt3 l bird mnin bch ybda yet7ark
    b->positionbird.x=0;
    b->positionbird.y=0;

//// initialisation position background1

    b->positionbackground.x = 0;
    b->positionbackground.y = 0;
    b->positionbackground.w = 0;
    b->positionbackground.h = 0;


//// initialisation position camera 1

    b->camera1.x = 0;
    b->camera1.y = 0;
    b->camera1.w = 1380;
    b->camera1.h = 1000;

//fama background 1 o  background 2 . 1 pour solo et 2 pour le partage d'ecran ily nty bch tet7akm bih fyl main si b.partage =1 alors fama partage d'ecran sin par defaut feha ecran barka



//// initialisation position background 2

    b->positionback_partage.x = 650;
    b->positionback_partage.y = 0;
    b->positionback_partage.h = 0;
    b->positionback_partage.w = 0;


//// initialisation position camera 2
    b->camera2.x = 0;
    b->camera2.y = 0;
    b->camera2.w = 800;
    b->camera2.h = 1000;

    b->compteur=-1;
    b->level=0;

}

void aficherBack(SDL_Surface *screen,background *b)
{

    SDL_BlitSurface(b->masque[b->level], &b->camera1, screen, &b->positionbackground); /// blite de 1ere background
    SDL_BlitSurface(b->image[b->level], &b->camera1, screen, &b->positionbackground); /// blite de 1ere background



    if(b->partage==1)
    {
        SDL_BlitSurface(b->masque[b->level], &b->camera2, screen, &b->positionback_partage); /// blite de 1ere background
        SDL_BlitSurface(b->image[b->level], &b->camera2, screen, &b->positionback_partage);/// blite de 2eme background avec partage
    }
}



//l fonction scrolling normalmonnt matekhdm ila matkounch fama collision en cas ou y a collision bch te9ef yaani maynjm yt3ada ila mayji fou9 l obstacles o yt3adeh
void scrolling(background *b, SDL_Surface *screen, mouvement M)
{
//il va afficher tasswira ta3 l assfoura(najmou nhotou ay tasswira theb aleha c'est un exemple)
    SDL_BlitSurface(b->bird[b->compteur],NULL,screen,&b->positionbird);

//tawa selon l movement ily bch yaamlou bch yssir scrolling ya ymchi ymin ya yssar(tnjm t9oli chbyh famch up o down hekom teb3in l personnage de plus maysirch scrolling l fou9 o louta yaani
if(b->level==1)
n=6600;
else 
    if (M.right == 1 )
    {
        if (b->camera1.x < 6600)
        {
            b->camera1.x += 30;
        }
    }
    if (M.left == 1)
    {
        if (b->camera1.x > 0)
        {
            b->camera1.x -= 30;
        }
    }
    //btbi3a manansawouch si joueur khtar l option t3 multipayer lezm yssir scrolling bin les 2 ecran o kol whda tescrolli wahdha so 2eme joueur bch yt7ark bl d et qo l 1er joueur bch yt7ark bl les fleches

    if(b->partage==1)
    {

        if (M.d == 1)
        {
            if (b->camera2.x < 8700)
            {
                b->camera2.x += 20;
            }
        }

        if (M.q == 1)
        {
            if (b->camera2.x > 0)
            {
                b->camera2.x -= 20;
            }
        }
    }
    
}


///// initialisation des deplacement
void init_Mouvement(mouvement *M)
{
    M->left = 0;
    M->right = 0;
    M->q = 0;
    M->d = 0;

}
//animation t3 l 3assfour 3assfour fyh 3 tssawer kol mara bch nwariw whda mnhom 9aadin nharkou b entier ismou b->compteur o tsawer m 0 lil 2 ill suffit b->compteur=2 bch trja l awel tasswira de plus bch ybda y9adm bsyeesa bsyessa
void animerBackground( background * b)
{

    if(b->compteur==2)
        b->compteur=0;
    else
        b->compteur++;
    b->positionbird.x+=1;


}
//l fonction hedhy mawjouda fyl atelier t3 l colision  huwa l concept t3 colision huwa il suffit l9a rectangle ak7el bch tssyr l colision o rectangle l ak7el heka yaanirahou obstacle o maynjmch yt3ada ila maybdl l position mte3ou  en conclusion l fonction getpixel  bch traj3lk l position ly feha joueur est que fyl position heky bdhet l pixel ka7la wala le

SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{
    SDL_Color color;
    Uint32 col=0;
    char* pPosition=(char* ) pSurface->pixels;
    pPosition+= (pSurface->pitch * y);
    pPosition+= (pSurface->format->BytesPerPixel *x);
    memcpy(&col,pPosition,pSurface->format->BytesPerPixel);
    SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);

    return (color);
}
//kif mafama fyl atelier on va tester tous les cas ly tnjm trahom fyl tabx o taby o il suffit wahda mnhom masset fy obstacles bch yrj3l anaheya l position ly jet feha obstacles sin ya pas du colision

int  collisionparfaite(SDL_Surface *psurface,perso p)
{
    int tabx[8],taby[8],i;
    SDL_Color color1,color;

    color1.r = 0;
    color1.g = 0;
    color1.b = 0;

    tabx[0]=p.rect.x;
    tabx[1]=(p.rect.x)+((p.rect.w)/2);
    tabx[2]=(p.rect.x+p.rect.w);
    tabx[3]=p.rect.x;
    tabx[4]=p.rect.x;
    tabx[5]=(p.rect.x)+((p.rect.w)/2);
    tabx[6]=(p.rect.x+p.rect.w);
    tabx[7]=(p.rect.x+p.rect.w);

    taby[0]=p.rect.y;
    taby[1]=p.rect.y;
    taby[2]=p.rect.y;
    taby[3]=(p.rect.y)+((p.rect.h)/2);
    taby[4]=(p.rect.y+p.rect.h);
    taby[5]=(p.rect.y+p.rect.h);
    taby[6]=(p.rect.y+p.rect.h);
    taby[7]=(p.rect.y)+((p.rect.h)/2);

    for(i=0; i<8; i++)
    {
        //color=getpixel(psurface,tabx[i],taby[i]);
        if(color.r==color1.r && color.b==color1.b && color.g==color1.g)
        {


            return i;
        }

    }
    return 10;

}



