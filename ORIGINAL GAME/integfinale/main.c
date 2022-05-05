#include"menu.h"
#include "enigme.h"
#include "maze.h"
#include "minimap.h"
#include "perso.h"
#include "background.h"
#include "ennemi.h"
#define GRAVITY 10// lzm haja tnaks f vitesse verticale bch ynajm ynagz
int main(int argc, char** argv)
{
    enigme2  maze;
    enigme enigmetxt;
    Ennemi monstre;
    minimap map;
    perso p,persoo ;
    background b;
    uint32_t t0, dt; //type c'est uint
    bool running=true;
    Input I;
    mouvement M;
    int b0=1;
    image fb0;

    SDL_Surface *screen;
    SDL_Event event;

    //affectation de l'ecran en la variable : screen
    screen = SDL_SetVideoMode(1300, 782, 32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set video: %s\n", SDL_GetError());
    }

    InitEnigme(&enigmetxt,"enigme1.txt");
    InitEnigme2(&maze, "enigme.txt");
    initEnnemi(&monstre);
    init_map (&map);
    initialiser_perso (&p);
    fb0.img = IMG_Load("b0.png");












    menu();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    while(running)
    {
    //persoooooooooo
        SDL_BlitSurface(fb0.img, NULL, screen, NULL); /// blite de 1ere background
    afficher_perso (p,screen);
    animation(&p,I);
    SDL_Delay(100);//tstana 70 tekhou rahatha
    t0=SDL_GetTicks();//tsjl wakt a t0
    SDL_Flip(screen);//trefraichi l page
    SDL_PollEvent(&event);//bch ychouf l event l dkhal


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
           
            }
            break;
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
    
    else if(I.right==0 && I.left==0 )
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
    if(p.rect.y >= 535)
    {
        p.rect.y= 535;//wsel ground

    }
}

/*
        switch (event.type)
        {
        case SDL_QUIT:

            running=false;
            break;


        case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                running=false;
                break;
                if (persoo.rect.x < 5000 && persoo.rect.x>0)
                {
                case SDLK_RIGHT:
                    M.right = 1;
                    persoo.rect.x+=10;
                    break;
                case SDLK_UP:
                    persoo.rect.y-=5;
                    p.rect.y-=5;

                    break;
                case SDLK_DOWN:
                    persoo.rect.y+=5;
                    p.rect.y+=5;
                    break;


                case SDLK_LEFT:
                    M.left = 1;
                    persoo.rect.x-=10;

                    break;
                }

            case SDLK_d:
                M.d = 1;
                break;
                persoo.rect.x+=10;

            case SDLK_a:
                M.q = 1;
                persoo.rect.x-=10;
                break;
            }
            break;


        case SDL_KEYUP:

            switch (event.key.keysym.sym)
            {

            case SDLK_UP:
                persoo.rect.y-=5;
                p.rect.y-=5;
                break;
            case SDLK_DOWN:
                persoo.rect.y+=5;
                p.rect.y+=5;
                break;

            case SDLK_RIGHT:
                M.right = 0;
                persoo.rect.x+=10;
                break;

            case SDLK_LEFT:
                M.left = 0;
                persoo.rect.x-=10;
                break;

            case SDLK_d:
                M.d = 0;
                p.rect.x+=10;
                break;

            case SDLK_a:
                M.q = 0;
                persoo.rect.x-=10;
                break;
            }
            break;
        }


    persoo.rect.x=b.camera1.x+90;
    persoo.rect.y=p.rect.y+90;

    aficherBack(screen, &b);/// appel fonction affichage back 1

    if(collisionparfaite(b.masque[b.level],persoo)==10)
    {

        scrolling(&b,  screen, M);
    }
    animerBackground( &b);
    SDL_Flip(screen);// mise a jour de l'ecran
*/


SDL_Quit();
return 0 ;
}

