#include "header.h"
#include "text.h"
void InitEnigme(enigme * e, char *nomfichier)
{
    int x;
    int i=0 ;
    srand(time(0));
    x=(rand() % (3)) +1;


    FILE *F;
    int nb=x+2;
    F=fopen(nomfichier, "r");
    if(F!=NULL)
    {
        while(nb!=0)
        {
            fscanf(F,"%s %s %d\n",e->mazesmall,e->mazebig,&(e->reponsejuste));

            if(nb>3)
            {

                nb--;
            }
            else
            {
                printf("%s %s %d\n",e->mazesmall,e->mazebig,e->reponsejuste);
                e->maze[i]=IMG_Load( e->mazesmall) ;
                e->maze[i+1]=IMG_Load( e->mazebig) ;
                i+=2;
                nb--;
            }
        }
    }
    fclose(F);

    e->timer[0] =IMG_Load("timer/0.gif");
    e->timer[1] =IMG_Load("timer/1.gif");
    e->timer[2] =IMG_Load("timer/2.gif");
    e->timer[3] =IMG_Load("timer/3.gif");
    e->timer[4] =IMG_Load("timer/4.gif");
    e->timer[5] =IMG_Load("timer/5.gif");
    e->timer[6] =IMG_Load("timer/6.gif");
    e->timer[7] =IMG_Load("timer/7.gif");
    e->timer[8] =IMG_Load("timer/8.gif");
    e->timer[9] =IMG_Load("timer/9.gif");

    e->postimer.x = 1200;
    e->postimer.y= 0;


    for(i=0; i<10; i++)
    {
        if (e->timer[i]==NULL)
        {
            printf ("erreurtimer");
            return ;
        }


    }
    e->back =IMG_Load("m.png");
    if (e->back==NULL)
    {
        printf ("erreurback");
        return ;
    }
    e->posback.x = 0 ;
    e->posback.y = 0;




    for(i=0; i<6; i++)
    {

        if (e->maze[i]==NULL)
        {
                printf("error2 : %s\n",SDL_GetError());
            printf ("erreurmaze");
            return ;
        }



    }
    				e->posmaze[0].x = 170 ;
    				e->posmaze[0].y = 350;


                    e->posmaze[2].x = 520 ;
                    e->posmaze[2].y = 350;

                    e->posmaze[4].x = 910 ;
                    e->posmaze[4].y = 350;

                    e->posmaze[1].x = 150 ;
                    e->posmaze[1].y = 300;

                    e->posmaze[3].x = 500;
                    e->posmaze[3].y = 300;

                    e->posmaze[5].x = 880 ;
                    e->posmaze[5].y = 300;

     }

     void afficherEnigme(enigme e, SDL_Surface * screen)
{
    SDL_BlitSurface (e.back,NULL,screen,&e.posback);
    SDL_BlitSurface (e.maze[0],NULL,screen,&e.posmaze[0]);
    SDL_BlitSurface (e.maze[2],NULL,screen,&e.posmaze[2]);
    SDL_BlitSurface (e.maze[4],NULL,screen,&e.posmaze[4]);

}

void animer (enigme *e)
{
    TTF_Init();
//      **************************INITIALISATION**************************
    SDL_Surface *screen ;
    SDL_Event event;

    int  a=0,b=2,c=4;
    int cont = 1;
    int o,t=0,i=0;
    char cc[20];
    text tt;
    time_t start,end;
    start=clock();
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Unable to initialisation SDL : %s\n",SDL_GetError());
    }
    SDL_WM_SetCaption("ENIGME",NULL);
    screen = SDL_SetVideoMode(1300,780,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL)
    {
        printf("error2 : %s\n",SDL_GetError());
    }
    InitEnigme(e,"enigme.txt" );

    initexte(&tt);

// *************son bref******************

    int v=100;
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_Chunk *true,*false;
    true=Mix_LoadWAV("true.wav");
    false=Mix_LoadWAV("false.wav");
    Mix_VolumeChunk(true,v);
    Mix_VolumeChunk(false,v);
    if ((true == NULL)||(false == NULL))
    {
        printf("XXXXXXXXXX: %s\n", Mix_GetError());
    }




//      **************************BOUCLE**************************

    while (cont)
    {

        sprintf(cc, ":0%d", t);
        
       afficherEnigme(*e, screen);
            SDL_BlitSurface (e->timer[t],NULL,screen,&e->postimer);
        displayText(tt,screen,cc);
        SDL_PollEvent(&event);

        end=clock();
        t=(end-start)/CLOCKS_PER_SEC;

        if(o!=t)
            printf("%d\n",t);
        if(t==10)
        {
            cont=0;
        }
        o=t;

        if ((event.type == SDL_QUIT)||(event.key.keysym.sym == SDLK_ESCAPE))
            cont = 0;
        SDL_Flip(screen);
        a=0;
        b=2;
        c=4;


        switch(event.type)
        {

        case SDL_KEYDOWN:
            SDL_Delay(120);

            switch(event.key.keysym.sym)
            {


            case SDLK_a:
                if(a!=0)
                    a=0;
                else
                {
                    a=1;



                }
                break;
            case SDLK_q:
                if(a!=0)
                    a=0;
                else
                {
                    a=1;


                }
                break;
            case SDLK_b:
                if(b!=2)
                    b=2;
                else

                {

                    b=3;


                }
                break;
            case SDLK_c:
                if(c!=4)
                    c=4;
                else


                {

                    c=5;

                }
                break;




            }
            break;
        case SDL_MOUSEMOTION:



            if (event.motion.x>170&& event.motion.y>350 && event.motion.x<380&& event.motion.y<600)

                a=1;

            if (event.motion.x>520&& event.motion.y>350 && event.motion.x<710&& event.motion.y<600)

                b=3;

            if (event.motion.x>880&& event.motion.y>350 && event.motion.x<1090&& event.motion.y<600)

                c=5;

            break;


        }


    }

}

void initexte(text *A)
{
    A->position.x=1240;
    A->position.y=15;
// couleur noir
    A->textColor.r=255;
    A->textColor.g=255;
    A->textColor.b=255;

    A->font = TTF_OpenFont( "police.ttf", 20 );
}


void displayText(text t,SDL_Surface *screen,char cc[30])
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, cc, t.textColor );
    SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}

