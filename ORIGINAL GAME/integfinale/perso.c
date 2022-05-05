#include "perso.h"
#define GRAVITY 10// lzm haja tnaks f vitesse verticale bch ynajm ynagz


void initialiser_perso (perso *p)
{
    p->direction=0;
    int i;
    p->personnage[0]=IMG_Load("personnage/pic/stop.png");//0 stop
    p->personnage[1]=IMG_Load("personnage/pic/jump.png");//1 jump
    p->personnage[2]=IMG_Load("personnage/pic/walk.png");//2 right
    p->personnage[3]=IMG_Load("personnage/pic/wl.png");// 3 left
    p->pos_sprite[0].w=p->personnage[0]->w/9;
    p->pos_sprite[1].w=p->personnage[1]->w/6;
    p->pos_sprite[2].w=p->personnage[2]->w/5;
    p->pos_sprite[3].w=p->personnage[3]->w/5;
    p->rect.x=0;//perso
    p->rect.y=535;


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
    if(p->rect.y==450)//collision with ground=300 sinon maynajmch
        p->vitesse_V[1] = -60;// verticale (yatlaa fouk)
}
void initialiser_input (Input *I)
{
    I->left=0;
    I->right=0;
    I->jump=0;

}
void persooo()
{
 TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen;
    screen=SDL_SetVideoMode (1380,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("personnage\t1",NULL);//titre de la fenetre
    Input I;
    perso p;
    SDL_Event event;
    SDL_Surface *back;
    initialiser_perso (&p);
    uint32_t t0, dt; //type c'est uint
    bool running=true;
    back=IMG_Load("pic/w.jpg");
    p.direction=0;
    SDL_EnableKeyRepeat(100,100);
    while(running)
    {
        SDL_BlitSurface(back, NULL, screen, NULL);
        afficher_perso (p,screen);
        animation(&p,I);
        SDL_Delay(100);//tstana 70 tekhou rahatha
        t0=SDL_GetTicks();//tsjl wakt a t0
        SDL_Flip(screen);//trefraichi l page
        while(SDL_PollEvent(&event))//bch ychouf l event l dkhal
        {
            switch(event.type)
            {
            case SDL_QUIT:
                running=false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT :
                    I.left=1;
                    p.direction=3;
                    break;
                case SDLK_RIGHT :
                    I.right=1;
                    p.direction=2;
                    break;
                case SDLK_UP :
                    I.jump=1;
                    p.direction=1;
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    I.right=0;
                    p.vitesse[2]=0;
                    break;
                case SDLK_LEFT :
                    I.left=0;
                    p.vitesse[3]=0;
                    break;
                case SDLK_UP :
                    I.jump=0;
                    break;
                }
                break;
            }
        }
        if (I.right==1)
    {
        p.direction=2;
        p.acceleration+=0.05;
        p.vitesse[2]=5;
    }
    else if (I.left==1 )
    {
        p.direction=3;
        p.acceleration+=0.05;
        p.vitesse[3]=5;
    }
    else if (I.jump==1)
    {
        saut(&p);
    }
    else if(I.jump==0 && I.right==0 && I.left==0 )
        p.direction=0;
    SDL_Delay(4);//yekber lwakt dt
    dt=SDL_GetTicks() - t0;
   movePerso(&p,dt,I);
    p.acceleration-=0.02;// k nsayb l bouton
    if (p.acceleration<=0)
    {
        p.acceleration=0;
    }
    if (p.acceleration>=0.7)
    {
        p.acceleration=0.7;
    }
    p.vitesse_V[1]+=GRAVITY;//vitesse verticale naks 10 tjrs
    p.rect.y += p.vitesse_V[1];//yzidha -60
    if(p.rect.y >= 600)
    {
        p.rect.y= 600;//wsel ground

    }
    }

}


