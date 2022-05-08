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
    TTF_Init();
    temps t;
    SDL_Rect posjoueur;
    posjoueur.x=70;
    enigme2  maze;
    enigme enigmetxt;
    Ennemi monstre;
    minimap m;
    perso p,persoo ;
    background b;
    uint32_t t0, dt; //type c'est uint
    bool running=true;
    Input I;
    mouvement M;
    int b0=1;
    image fb0;
    int choix=2;
    int  valeur_score=1000;

    score s;


    SDL_Surface *screen;
    SDL_Event event;

    //affectation de l'ecran en la variable : screen
    screen = SDL_SetVideoMode(1300, 782, 32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set video: %s\n", SDL_GetError());
    }
    //init tous

     menu();
     
    initBack(&b);
    InitEnigme(&enigmetxt,"enigme1.txt");
    InitEnigme2(&maze, "enigme.txt");
    initEnnemi(&monstre);
    init_map (&m);
    initialiser_perso (&p,choix);
    initialiser_input (&I);
    initialiser_score(1000,&s);
    initialiser_temps(&t);
    
    char nom[30]="";

    fb0.img = IMG_Load("b0.png");


 printf("Unable to set video: %s\n", SDL_GetError());









   




















    while(running)
    {
        //persoooooooooo

        SDL_BlitSurface(fb0.img, NULL, screen, NULL); /// blite de 1ere background
        animation(&p,choix);
        afficher_perso (&p,screen);
        movePerso(&p,dt);
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
                posjoueur.x-=10;


                break;

            case SDLK_RIGHT :
                I.right=1;
                posjoueur.x+=10;

                break;
            case SDLK_UP :
                I.jump=1;
                printf("%d\t",posjoueur.x);
                if(posjoueur.x>=69 && posjoueur.x<=110)
                    running=false;

                if(posjoueur.x>=129 && posjoueur.x<=170)
                    printf("second door");
                if(posjoueur.x>=220 && posjoueur.x<=260)
                    printf("third door");
                if(posjoueur.x>=320 && posjoueur.x<=370)
                    printf("exit door");
                break;
            case SDLK_SPACE:
                I.hit=1;
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                I.right=0;
                p.direction=0;
                p.vitesse=0;
                break;
            case SDLK_LEFT :
                I.left=0;
                p.direction=0;
                p.vitesse=0;
                break;

            case SDLK_UP :
                I.jump=0;

                break;
            case SDLK_SPACE:
                I.hit=0;
                p.direction=0;
                break;

            }
            break;
        }



        if (I.left==1)
        {
            p.direction=2;
            p.acceleration+=0.05;
            p.vitesse=5;

        }
        else if (I.right==1 )
        {
            p.direction=1;
            p.acceleration+=0.05;
            p.vitesse=5;


        }

        if (I.jump==1)
        {
            printf("wa");
            saut(&p,570);
        }
        if(I.hit==1&&I.left==1)
        {
            p.direction=4;
        }
        if (I.hit==1&&I.right==1)
        {
            p.direction=3;
        }
        if(I.hit==1&&I.left==0)
        {
            p.direction=3;
        }


        SDL_Delay(4);//yekber lwakt dt
        dt=SDL_GetTicks() - t0;


        p.acceleration-=0.03;// k nsayb l bouton

        if (p.acceleration<=0)
        {
            p.acceleration=0;
        }
        if (p.acceleration>=0.7)
        {
            p.acceleration=0.7;
        }



        p.vitesse_V+=GRAVITY;//vitesse verticale naks 10 tjrs
        p.rect.y += p.vitesse_V;//yzidha -60
        if(p.rect.y >= 570)
        {
            p.rect.y= 570;//wsel ground
            p.vitesse_V = 10;//tzidha 10 perso habt khatr wsl
        }


    }
    running=true;
    p.rect.y=500;

    p.rect.x=0;
    persoo.rect=p.rect;

    //FIRST LEVEL //

    while(running)
    {

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


                break;

            case SDLK_RIGHT :
                I.right=1;
                break;
            case SDLK_UP :
                I.jump=1;

                break;
            case SDLK_SPACE:
                I.hit=1;
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                I.right=0;
                p.direction=0;
                p.vitesse=0;
                break;
            case SDLK_LEFT :
                I.left=0;
                p.direction=0;
                p.vitesse=0;
                break;

            case SDLK_UP :
                I.jump=0;

                break;
            case SDLK_SPACE:
                I.hit=0;
                p.direction=0;
                break;

            }
            break;
        }



        if (I.left==1)
        {
            p.direction=2;
            p.acceleration+=0.05;
            p.vitesse=5;

        }
        else if (I.right==1 )
        {
            p.direction=1;
            p.acceleration+=0.05;
            p.vitesse=5;


        }

        if (I.jump==1)
        {
            saut(&p,500);
        }
        if(I.hit==1&&I.left==1)
        {
            p.direction=4;
        }
        if (I.hit==1&&I.right==1)
        {
            p.direction=3;
        }
        if(I.hit==1&&I.left==0)
        {
            p.direction=3;
        }


        SDL_Delay(4);//yekber lwakt dt
        dt=SDL_GetTicks() - t0;


        p.acceleration-=0.03;// k nsayb l bouton

        if (p.acceleration<=0)
        {
            p.acceleration=0;
        }
        if (p.acceleration>=0.7)
        {
            p.acceleration=0.7;
        }



        p.vitesse_V+=GRAVITY;//vitesse verticale naks 10 tjrs
        p.rect.y += p.vitesse_V;//yzidha -60
        if(p.rect.y >= 500)
        {
            p.rect.y=500;//wsel ground
            p.vitesse_V = 10;//tzidha 10 perso habt khatr wsl
        }




        
        animation(&p,choix);
        //movePerso(&p,dt);
        aficherBack(screen, &b);/// appel fonction affichage back 1
         afficher_temps(&t,screen);
       afficher_score(&s,screen,valeur_score);
        afficher_perso (&p,screen);
        update_score(&valeur_score);
        MAJMinimap(p.rect,&m, b.camera1, 10);
        afficherminimap(m,screen);
        t0=SDL_GetTicks();//tsjl wakt a t0
        scrolling(&b,  screen, M);
        animerBackground( &b);
        SDL_Flip(screen);// mise a jour de l'ecran
        //partie back

        switch (event.type)
        {
        case SDL_QUIT:

            running=false;
            break;


        case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {






            case SDLK_ESCAPE:
                save(valeur_score,nom);
                running=false;
                break;
                if (persoo.rect.x < 5000 && persoo.rect.x>0)
                {
                case SDLK_RIGHT:
                    M.right = 1;
                    persoo.rect.x+=10;
                    p.rect.x+=10;
                    break;
                case SDLK_UP:
                    persoo.rect.y-=5;


                    break;
                case SDLK_DOWN:
                    persoo.rect.y+=5;

                    break;


                case SDLK_LEFT:
                    M.left = 1;
                    persoo.rect.x-=10;
                    p.rect.x-=10;

                    break;
                }

            case SDLK_d:
                M.d = 1;
                persoo.rect.x+=10;

                break;

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

                break;
            case SDLK_DOWN:
                persoo.rect.y+=5;

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



    }


       

    load (valeur_score, nom);
    SDL_Quit();
    return 0 ;
}

