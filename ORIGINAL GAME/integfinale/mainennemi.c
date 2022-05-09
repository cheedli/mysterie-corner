/**
* @file mainennemi.c
* @brief Testing Program.
* @author CHEDHLY
* @version 0.1
* @date Apr 22 , 2022
*
* Testing program for EVERYTHING *
*/
#include "ennemi.h"

void main()
{
//      ***************************INITIALISATION***************************
    SDL_Surface *screen = NULL;
    SDL_Event event;
    Ennemi e;
    image back,colision;
    SDL_Rect posmousse;
    int cont = 1,i=0,ched=0,ed=0;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Unable to initialisation SDL : %s\n",SDL_GetError());
    }
    SDL_WM_SetCaption("ENNEMI",NULL);
    screen = SDL_SetVideoMode(1380,700,32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
    if (screen == NULL)
    {
        printf("error : %s\n",SDL_GetError());
    }


    colision.img = IMG_Load ("w");
    colision.pos.x = 0;
    colision.pos.y = 350;
    colision.pos.h=colision.pos.h;
    colision.pos.w=colision.pos.w;

    back.img = IMG_Load ("file.jpg");
    back.pos.x = 0;
    back.pos.y = 0;
    initEnnemi(&e);
//      ***************************BOUCLE***************************
    e.level=1;
    e.etat=0;
    while (cont)
    {
        SDL_PollEvent(&event);
        SDL_BlitSurface(back.img,NULL,screen,&back.pos);
        SDL_BlitSurface(colision.img,NULL,screen,&colision.pos);
        if (( ed==1)&&(collisionBox( e.pos[e.level],colision.pos)!=1))
        {

            e.etat=0;
            ed=0;
        }
        if(ched==0)
        {
            



            animerEnnemi(&e);
            afficherEnnemi(e,screen);

            deplacer(&e);
            deplacerIA(&e);


            if (collisionBox( e.pos[e.level],colision.pos))
            {

                e.etat=2;
                ed=1;
            }
            if(e.etat!=2)
                updateEnnemi ( &e,colision.pos );

        }
        SDL_Flip(screen);

        if (event.type == SDL_QUIT)
            cont = 0;

        colision.pos.x += 10;


        if (event.type ==(event.key.keysym.sym == SDLK_ESCAPE))
            ched=1;

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button==SDL_BUTTON_LEFT)
            {

                ched=1;
                e.etat=3;
            }
        }





    }
    SDL_Quit();
}

