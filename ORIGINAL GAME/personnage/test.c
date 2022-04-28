#include "test.h"


void initialiser_perso (perso *p)
{
    p->direction=0;
    int i;
    p->personnage[0]=IMG_Load("pic/stop.png");//0 stop
    p->personnage[1]=IMG_Load("pic/jump.png");//1 jump
    p->personnage[2]=IMG_Load("pic/walk.png");//2 right
    p->personnage[3]=IMG_Load("pic/wl.png");// 3 left
    p->pos_sprite[0].w=p->personnage[0]->w/9;
    p->pos_sprite[1].w=p->personnage[1]->w/6;
    p->pos_sprite[2].w=p->personnage[2]->w/5;
    p->pos_sprite[3].w=p->personnage[3]->w/5;
    p->rect.x=0;//perso
    p->rect.y=250;


    for(i=0; i<4; i++)
    {
        p->pos_sprite[i].x=0;
        p->pos_sprite[i].y=0;
        p->pos_sprite[i].h=p->personnage[i]->h;

        p->vitesse_V[i]=0;
            p->vitesse[i]=0.1;
    }


    
    p->acceleration=0;

}

void afficher_perso (perso p,SDL_Surface *screen)
{
    SDL_BlitSurface(p.personnage[p.direction],&p.pos_sprite[p.direction],screen,&p.rect);//rect benesba l pos
}

void animation (perso *p,Input i)
{
    if (i.jump==1 && p->pos_sprite[1].x >762)//hya ekher taswira l hya x=4500
    {
        p->pos_sprite[1].x =0;
    }
    else p->pos_sprite[1].x +=190;
    if (i.right==1 && p->pos_sprite[2].x >684)//hya ekher taswira l hya x=4500
    {
        p->pos_sprite[2].x =0;
    }
    else p->pos_sprite[2].x +=228;
    if (i.left==1 && p->pos_sprite[3].x >684)//hya ekher taswira l hya x=4500
    {
        p->pos_sprite[3].x =0;
    }
    else p->pos_sprite[3].x +=228;
    if(i.jump==0 && i.right==0 &&i.left==0 && p->pos_sprite[0].x <1750)
        p->pos_sprite[0].x +=250;
    else
        p->pos_sprite[0].x =0;
}
void movePerso(perso *p,Uint32 dt,Input i)
{
    //(diff de temps kadeh aandha bdet boucle hata ssar deplacement)
    double dx;// vitesse
    int j;
    
        dx= 0.05 * dt * dt * p->acceleration + dt*p->vitesse[p->direction];
    
    if (i.right==1) //k yabda f a droite donc 2
    {
        p->rect.x += dx;
        p->direction=2;
    }
    else  if (i.left==1)
    {
        p->rect.x -= dx ;   // gauche
                p->direction=3;
    }
}
void saut (perso *p)
{
    if(p->rect.y==250)//collision with ground=300 sinon maynajmch
        p->vitesse_V[1] = -60;// verticale (yatlaa fouk)
}
void initialiser_input (Input *I)
{
    I->left=0;
    I->right=0;
    I->jump=0;


}

