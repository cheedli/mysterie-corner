#include"test.h"
#define GRAVITY 10// lzm haja tnaks f vitesse verticale bch ynajm ynagz
int main()
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
        if(p.rect.y >= 250)
        {
            p.rect.y= 250;//wsel ground

        }
    }
    TTF_Quit();
}

