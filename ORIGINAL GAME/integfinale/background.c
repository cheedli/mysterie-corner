#include "background.h"




void initBackMasque (background *b)
{
//background
    b->imgback=IMG_Load("masquen2.png");
    b->posback.x=0;
    b->posback.y=0;

//camera
    b->camera.x=0;
    b->camera.y=0;
    b->camera.w=1380;
    b->camera.h=800;
    b->son=Mix_LoadMUS("musique.mp3");
}

void initBack2 (background *b)
{
//background2
    b->imgback=IMG_Load("n2.png");
    b->posback2.x=0;
    b->posback2.y=0;
//camera2
    b->camera2.x=0;
    b->camera2.y=0;
    b->camera2.w=1380;
    b->camera2.h=800;
//musique
    b->son=Mix_LoadMUS("musique.mp3"); //Chargement de la musique
    b->image_flower=IMG_Load("flower.png");
    b->pos_image_flower.x=100;
    b->pos_image_flower.y=300;

    b->single_flower.w=56;
    b->single_flower.h=107;
    b->single_flower.x=0;
    b->single_flower.y=0;

    b->flower_num=0;

}


void initialisation_back(background *b)
{
    //initBackMasque(b);
    initBack2(b);
}



void afficheBack (background b, SDL_Surface *ecran)
{
    /* On blitte par-dessus l'écran */
    Mix_PlayMusic(b.son, -1);
    SDL_BlitSurface(b.imgback,&b.camera,ecran,&b.posback);
}

void afficheBack2 (background b, SDL_Surface *ecran)
{
    /* On blitte par-dessus l'écran */
    Mix_PlayMusic(b.son, -1); //Jouer infiniment la musique
    SDL_BlitSurface(b.imgback,&b.camera2,ecran,&b.posback2);
    displayFlower(b,ecran);

}
/*void afficher_back(background b, SDL_Surface *ecran)
{
	afficheBack(b,ecran);
	afficheBack2(b,ecran);

}*/

void scrolling (background *b,int direction)
{
    const int speed=20;
    if (direction ==0) //right
    {
        b->camera.x+= speed;

        b->camera2.x+= speed;

    }
    else if (direction ==1) //left
    {
        b->camera.x-=speed;

        b->camera2.x-=speed;
    }


    else if (direction ==2) //up
    {
        b->camera.y-= speed;

        b->camera2.y-= speed;
    }
    else if (direction ==3) //down
    {
        b->camera.y+= speed;

        b->camera2.y+= speed;
    }

}


void displayFlower(background b,SDL_Surface *ecran)
{

    SDL_BlitSurface(b.image_flower,&(b.single_flower), ecran, &b.pos_image_flower);
}
void animerBackground(background *b)
{

    if (b->flower_num >=0 && b->flower_num <8)
    {
        b->single_flower.x=b->flower_num * b->single_flower.w;
        b->flower_num++;
    }

    if ( b->flower_num == 8)
    {
        b->single_flower.x=b->flower_num * b->single_flower.w;
        b->flower_num=0;
    }


}
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
int  collisionparfaite(SDL_Surface *psurface,perso p)
{
    int tabx[7],taby[7],i;
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
        color=getpixel(psurface,tabx[i],taby[i]);
        if((color.r==0) && (color.b==0) && (color.g==0))
        {
            return i;

        }
    }
    return 10;

}

void collision(SDL_Surface *psurface,perso *p)
{
    int i;
    i=collisionparfaite(psurface,*p);

    switch (i)
    {
    case 0 :
        p->rect.y=p->rect.y+10;
        break;
    case 1 :
        p->rect.y=p->rect.y+10;
        break;
    case 2 :
        p->rect.y=p->rect.y+10;
        break;
    case 3 :
        p->rect.x=p->rect.x+10;
        break;
    case 4 :
        p->rect.y=p->rect.y-10;
        break;
    case 5 :
        p->rect.y=p->rect.y-10;
        break;
    case 6 :
        p->rect.y=p->rect.y-10;
        break;
    case 7 :
        p->rect.x=p->rect.x-10;
        break;


    }
}

