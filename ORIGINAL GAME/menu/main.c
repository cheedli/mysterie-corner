#include"header.h"
int main(int argc, char** argv)
{
    TTF_Init();
    SDL_Init ( SDL_INIT_VIDEO );

    //declaration des variables
    
    int done=1,odone=0,o=0,p=0,q=0,i=0,oo=0,s=4,ss,c=0, sso=0,ssc=0,mmu=0,y=0,n=0,new=0,qdone=0,pdone=0,sdone=0,load=0,ndone=0,newdone=0;
    image back[16],pl[3],op[3],qu[3],l[5],ll[5],so[2],sc[2],mu[2],name,yes[2],no[2],yesornooption,m,backo,score,newgame[2],loadgame[2];
    text t;
    SDL_Surface *screen;
    SDL_Event event;
    //affectation de l'ecran en la variable : screen
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set video: %s\n", SDL_GetError());
        return 1;
    }

    //initialisation des buttons : play,option,quit et du background

    inti_in_option(l, ll,&backo);
    init( qu, pl,op,back,so,mu,sc,&name, yes,no, &yesornooption,newgame,loadgame,&score);
    inp( &m);
    initText(&t);

    //introduction musique

    int vm=100, vsfx=100;
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_Music *music;   	//background music
    Mix_Chunk *swing ;		//son bref
    music= Mix_LoadMUS("OPENMUSIC.mp3");
    Mix_VolumeMusic(vm);
    Mix_PlayMusic(music,-1);
    swing= Mix_LoadWAV("swing.wav");
    Mix_VolumeChunk(swing,vsfx);
    if (swing==NULL)
    {
        printf("xxxxxx:%s",Mix_GetError());
    }

    //nom du fenetre : MYSTERY CORNER

    SDL_WM_SetCaption("MYSTERY CORNER", NULL);

    while (done)
    {

        //affichage des bouttons et du background

        afficher(back[i],screen);
        oo++;
        if ((o!=2)&&(odone!=1)&&(q!=2)&&(qdone!=1)&&(p!=2)&&(pdone!=1)&&(ssc!=2)&&(sdone!=1)&&(newdone!=1))
        {

            oo++;
            afficher(pl[p],screen);
            afficher(op[o],screen);
            afficher(qu[q],screen);
            afficher(name,screen);
            afficher (sc[ssc],screen);
            displayText(t,screen);

        }
        Mix_VolumeChunk(swing,((vsfx/4)*s));
        if(new==2 || newdone==1)
        {
        afficher(mu[0],screen);
            afficher(so[0],screen);
        
        
        }
        

        if ((o==2)||(odone==1))
        {
            oo++;
            afficher(backo,screen);
            afficher(m,screen);
            afficher(l[s],screen);
            Mix_VolumeMusic((vm/4)*s);
            Mix_VolumeChunk(swing,(vsfx/4)*s);

        }
        if((q==2)||(qdone==1))
        {            oo++;
            afficher(yesornooption,screen);
            afficher(yes[y],screen);
            afficher(no[n],screen);
        }

        if((p==2)||(pdone==1) && newdone==0 )
        {
            oo++;
            afficher(newgame[new],screen);
            afficher(loadgame[load],screen);

        }
        if((ssc==2)||(sdone==1))
        {
                    oo++;
            afficher(score,screen);
        }



        SDL_Flip(screen);

        if (i==15)
            i=0;
        if(oo==12)
        {
            i++;
            oo=0;
        }

        SDL_PollEvent(&event);
        switch(event.type)
        {


// utilisiation du souris

        case SDL_MOUSEMOTION:

            p=0;
            q=0;
            o=0;
            ssc=0;
            new=0;
            load=0;
            y=0;
            n=0;
            


            if (event.motion.x>275 && event.motion.y>250 && event.motion.x<520 && event.motion.y<350 )
            {
                p=1;
                c++;
            }
            else if (event.motion.x>275 && event.motion.y>370 && event.motion.x<520 && event.motion.y<478 )
            {
                ssc=1;
                c++;
            }

            else if ((event.motion.x>275 && event.motion.y>470 && event.motion.x<520 && event.motion.y<560 )&&(qdone==0))
            {
                o=1;
                c++;
            }



            else if (event.motion.x>275 && event.motion.y>600 && event.motion.x<520 && event.motion.y<700 )
            {
                q=1;
                c++;
            }
            else

            {
                c=0;

            }
            if(c==1)
                Mix_PlayChannel(-1, swing, 0);


            if (event.motion.x>160 && event.motion.y>305  && event.motion.x<630 && event.motion.y<430 )
            {
                new=1;
                c++;
            }
            if (event.motion.x>180 && event.motion.y>555  && event.motion.x<630 && event.motion.y<630 )
            {
                load=1;
                c++;
            }
            if (event.motion.x>170 && event.motion.y>490 && event.motion.x<346 && event.motion.y<594 )
            {
                y=1;
                c++;
            }
            else if (event.motion.x>446 && event.motion.y>490 && event.motion.x<630 && event.motion.y<594 )
            {
                n=1;
                c++;
            }
            break;

        // utilisiation du botton gauche de la  souris

        case SDL_MOUSEBUTTONDOWN:
            printf("%d\n",event.motion.x);
            if (event.button.button==SDL_BUTTON_LEFT)
            {
            if((new==1)&&(pdone==1))
            {
            newdone=1;
            new=2;
            load=2;
            }
                
                if ((y==1) && (qdone==1))
                    done=0;
                if ((p==1)&& odone==0 && qdone==0 && sdone==0)
                {
                    p=2;
                    pdone=1;

                }
                else if ((o==1)&& pdone==0 && qdone==0 && sdone==0)
                {
                    o=2;
                    odone=1;
                }

                else if ((q==1)&& pdone==0 && odone==0 && sdone==0)
                {
                    q=2;
                    qdone=1;

                }
                else if ((ssc==1)&& pdone==0 && qdone==0 && odone==0)
                {
                    ssc=2;
                    sdone=1;

                }
                if((n==1)&& pdone==0 && odone==0 && sdone==0)
                {
                    q=0;
                    qdone=0;
                }
            }
            break;

        //utilisation du clavier

        case SDL_KEYDOWN:
            Mix_PlayChannel(-1, swing, 0);
            switch(event.key.keysym.sym)
            {

                p=0;
                q=0;
                o=0;
                ssc=0;

            case SDLK_RIGHT:

                if ((odone==1)&&(s!=4))
                {

                    s++;
                    SDL_Delay(100);
                }


                break;
            case SDLK_s:
                ssc=1;
                break;


            case SDLK_LEFT:

                if ((odone==1)&&(s!=0))
                {

                    s--;
                    SDL_Delay(100);
                }


                break;
            case SDLK_UP:

                if (p==1 )
                {

                    q=1;
                    p=0;
                    o=0;
                }
                else if(o==1 )
                {
                    p=1;
                    o=0;
                    q=0;
                }
                else if (q==1 )
                {
                    o=1;
                    q=0;
                    p=0;
                }
                if(p==0 && o==0 && q==0)
                {
                    p=1;
                }




                break ;
            case SDLK_DOWN:

                if (p==1 )
                {
                    p=0;
                    o=1;
                    q=0;

                }
                else if(o==1 )
                {
                    p=0;
                    o=0;
                    q=1;
                    SDL_Quit();

                }
                else if (q==1 )
                {
                    o=0;
                    q=0;
                    p=1;

                }
                if (p==0 && o==0 && q==0 )
                {
                    q=1;
                }



                break;
            case SDLK_p:
                ssc=0;
                o=0;
                q=0;
                p=1;
                break;
            case SDLK_q:
                ssc=0;
                o=0;
                q=1;
                p=0;
                done=0;
                break;

            case SDLK_o:
                ssc=0;
                p=0;
                o=1;
                q=0;
                break;
            case SDLK_ESCAPE:
                if (odone==1)
                    odone=0;
                if (qdone==1)
                    qdone=0;

                if (pdone==1)
                    pdone=0;
                if (sdone==1)
                    sdone=0;
                    if (newdone==1)
                    newdone=0;
                    

                break ;

            case SDLK_m:
                if(s=!0)
                {
                    Mix_VolumeMusic(0);
                    ss=s;
                    s=0;
                }
                else if(s==0)
                {
                    Mix_VolumeMusic(ss*(vm/4));
                    s=ss;
                }
                break;
            case SDLK_KP_ENTER :
                if (p==1)
                {
                    p=2;

                }
                else if (o==1)
                {
                    o=2;
                    odone=1;
                }

                else if (q==1)
                {
                    q=2;
                }
                break;
            }
            break;


        case SDL_QUIT:
            SDL_Quit();
            return(0);

            break;
        }
    }
    printf("e");
    TTF_Quit();
    SDL_Quit();
    return 0 ;
}

