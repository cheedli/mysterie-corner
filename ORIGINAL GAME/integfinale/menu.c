#include "menu.h"
#include "perso.h"
#include "enigme.h"
#include "minimap.h"
///////////////////////////////////////////////////////////////

void inp(image m[],image e[],image f[],image lettre[])
{
    int i ;
    f[0].img=IMG_Load("menu/boutons/controlers/f0.png");
    f[1].img=IMG_Load("menu/boutons/controlers/f1.png");
    f[0].pos.x = 190;
    f[0].pos.y = 500;
    lettre[0].pos.x = 490;
    lettre[0].pos.y = 500;
    lettre[0].img=IMG_Load("menu/boutons/controlers/l0.png");
    lettre[1].img=IMG_Load("menu/boutons/controlers/l1.png");
    f[1].pos.x = 150;
    f[1].pos.y = 462;
    lettre[1].pos.x = 450;
    lettre[1].pos.y = 462;

    m[0].img=IMG_Load("menu/boutons/inoption/music.png");
    m[1].img=IMG_Load("menu/boutons/inoption/music2.png");
    e[0].img=IMG_Load("menu/boutons/inoption/e1.png");
    e[1].img=IMG_Load("menu/boutons/inoption/e2.png");

    for(i=0; i<2; i++)
    {

        m[i].pos.x = 140;
        m[i].pos.y = 270;
        e[i].pos.x = 140;
        e[i].pos.y = 370;
    }
}
void inti_in_option(image l[],image ll[],image *backo)
{
    int i;
    backo->img=IMG_Load("menu/boutons/inoption/option.png");

    if (backo->img== NULL)
    {
        printf("hhhhh");
        return ;
    }
    backo->pos.x = 0;
    backo->pos.y = 120;

    l[0].img=IMG_Load("menu/boutons/inoption/0.png");
    l[1].img=IMG_Load("menu/boutons/inoption/25.png");
    l[2].img=IMG_Load("menu/boutons/inoption/50.png");
    l[3].img=IMG_Load("menu/boutons/inoption/75.png");
    l[4].img=IMG_Load("menu/boutons/inoption/100.png");

    ll[0].img=IMG_Load("menu/boutons/inoption/0.png");
    ll[1].img=IMG_Load("menu/boutons/inoption/25.png");
    ll[2].img=IMG_Load("menu/boutons/inoption/50.png");
    ll[3].img=IMG_Load("menu/boutons/inoption/75.png");
    ll[4].img=IMG_Load("menu/boutons/inoption/100.png");


    for(i=0; i<5; i++)
    {

        if ( l[i].img== NULL)
        {
            return ;
        }
        l[i].pos.x =300;
        l[i].pos.y = 95;

        if ( ll[i].img== NULL)
        {
            return ;
        }
        ll[i].pos.x =300;
        ll[i].pos.y = 200;
    }
}


void init(image q[],image p[],image o[],image back[],image so[],image m[],image sc[],image *name,image yes[],image no[], image *yesornooption,image newgame[],image loadgame[],image *score )
{

    int i;




    name->img=IMG_Load("menu/name.png");
    if (name->img== NULL)
    {
        printf("hhhhh");
        return ;
    }
    name->pos.x = 50;
    name->pos.y = 50;

    score->img=IMG_Load("menu/boutons/score/score.png");
    if (score->img== NULL)
    {
        printf("hhhhh");
        return ;
    }
    score->pos.x = 50;
    score->pos.y = 150;

    newgame[0].img=IMG_Load("menu/boutons/newgame/newgame0.png");
    newgame[1].img=IMG_Load("menu/boutons/newgame/newgame1.png");

    loadgame[0].img=IMG_Load("menu/boutons/loadgame/loadgame0.png");
    loadgame[1].img=IMG_Load("menu/boutons/loadgame/loadgame1.png");







    q[0].img=IMG_Load("menu/boutons/quit/q1.png");
    q[1].img=IMG_Load("menu/boutons/quit/q2.png");
    q[2].img=IMG_Load("menu/boutons/quit/q3.png");

    o[0].img=IMG_Load("menu/boutons/option/o1.png");
    o[1].img=IMG_Load("menu/boutons/option/o2.png");
    o[2].img=IMG_Load("menu/boutons/option/o3.png");

    p[0].img=IMG_Load("menu/boutons/play/p1.png");
    p[1].img=IMG_Load("menu/boutons/play/p2.png");
    p[2].img=IMG_Load("menu/boutons/play/p3.png");

    back[0].img= IMG_Load("menu/boutons/background/0.png");
    back[1].img= IMG_Load("menu/boutons/background/1.png");
    back[2].img= IMG_Load("menu/boutons/background/2.png");
    back[3].img= IMG_Load("menu/boutons/background/3.png");
    back[4].img= IMG_Load("menu/boutons/background/4.png");
    back[5].img= IMG_Load("menu/boutons/background/5.png");
    back[6].img= IMG_Load("menu/boutons/background/6.png");
    back[7].img= IMG_Load("menu/boutons/background/7.png");
    back[8].img= IMG_Load("menu/boutons/background/8.png");
    back[9].img= IMG_Load("menu/boutons/background/9.png");
    back[10].img= IMG_Load("menu/boutons/background/10.png");
    back[11].img= IMG_Load("menu/boutons/background/11.png");
    back[12].img= IMG_Load("menu/boutons/background/12.png");
    back[13].img= IMG_Load("menu/boutons/background/13.png");
    back[14].img= IMG_Load("menu/boutons/background/14.png");
    back[15].img= IMG_Load("menu/boutons/background/15.png");

    sc[0].img=IMG_Load("menu/boutons/score/sc0.png");
    sc[1].img=IMG_Load("menu/boutons/score/sc1.png");

    so[0].img=IMG_Load("menu/boutons/solo/so0.png");
    so[1].img=IMG_Load("menu/boutons/solo/so1.png");

    m[0].img=IMG_Load("menu/boutons/multiplayer/m0.png");
    m[1].img=IMG_Load("menu/boutons/multiplayer/m1.png");


    yes[0].img=IMG_Load("menu/boutons/yes/y0.png");
    yes[1].img=IMG_Load("menu/boutons/yes/y1.png");

    no[0].img=IMG_Load("menu/boutons/no/n0.png");
    no[1].img=IMG_Load("menu/boutons/no/n1.png");

    yesornooption->img=IMG_Load("menu/boutons/yesornooption.png");
    yesornooption->pos.x =100;
    yesornooption->pos.y = 240;


    for(i=0; i<3; i++)
    {
        if ( q[i].img== NULL)
        {
            return ;
        }
        q[i].pos.x =210;
        q[i].pos.y = 450;
        if (o[i].img== NULL)
        {
            return ;
        }
        o[i].pos.x =210;
        o[i].pos.y = 330;
        if (p[i].img== NULL)
        {
            return ;
        }
        p[i].pos.x = 210;
        p[i].pos.y = 100;
    }
    for(i=0; i<16; i++)
    {
        if (back[i].img == NULL)
        {
            printf("Unable to load : %s\n", SDL_GetError());
            return;
        }
        back[i].pos.x=0;
        back[i].pos.y=0;
    }
    for(i=0; i<2; i++)
    {
        if ( sc[i].img== NULL)
        {
            return ;
        }
        sc[i].pos.x =210;
        sc[i].pos.y = 205;
        if ( so[i].img== NULL)
        {
            return ;
        }
        so[i].pos.x =220;
        so[i].pos.y = 190;
        if ( m[i].img== NULL)
        {
            return ;
        }
        m[i].pos.x =210;
        m[i].pos.y = 340;
        if (yes[i].img== NULL)
        {
            return ;
        }
        yes[i].pos.x = 10;
        yes[i].pos.y = 290;

        if (no[i].img== NULL)
        {
            return ;
        }
        no[i].pos.x = 290;
        no[i].pos.y = 290;
        if ( newgame[i].img== NULL)
        {
            return ;
            printf("ee");
        }
        newgame[i].pos.x =160;
        newgame[i].pos.y = 305;

        if ( loadgame[i].img== NULL)
        {
            printf("ee");
            return ;
        }
        loadgame[i].pos.x =160;
        loadgame[i].pos.y = 505;
    }
}
///////////////////////////////////////////////////////////////
void liberer(image A )
{
    SDL_FreeSurface(A.img);
}

void afficher(image A,SDL_Surface *screen)
{
    SDL_BlitSurface(A.img,NULL,screen,&A.pos);
}
///////////////////////////////////////////////////////////////
void initText(text *A)
{
    A->position.x=0;
    A->position.y=0;
// couleur noir
    A->textColor.r=0;
    A->textColor.g=0;
    A->textColor.b=0;
    A->font = TTF_OpenFont( "menu/font.ttf", 10 );
}
void displayText(text t,SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "THE TELLERS", t.textColor );
    SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}
void freeText(text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}

















void menu()
{

    SDL_Init ( SDL_INIT_VIDEO );

    //declaration des variables
    perso per;
    Input I;
        initialiser_input (&I);
    	TTF_Font *police = NULL;
    	police = TTF_OpenFont("minimap/avocado.ttf", 30);
    int  verif=1,done=1,solo=0,multi=0,odone=0,o=0,p=0,q=0,i=0,oo=0,s=4,ef=4,ss,c=0,d=1, sso=0,ssc=0,mmu=0,y=0,n=0,new=0,qdone=0,pdone=0,sdone=0,load=0,ndone=0,newdone=0,mus=0,effect=0,fleche=1,let=0,solodone=0;
    image back[16],pl[3],op[3],qu[3],l[5],ll[5],so[2],sc[2],mu[2],name,yes[2],no[2],yesornooption,m[2],e[2],backo,score,newgame[2],loadgame[2],lettre[2],f[2];
    text t;
    SDL_Surface *screen;
    SDL_Event event;
    int choix=2;
    initialiser_perso (&per,choix);
                per.rect.y-=70;
    //affectation de l'ecran en la variable : screen
    screen = SDL_SetVideoMode(1300, 782, 32,SDL_HWSURFACE|SDL_SWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set video: %s\n", SDL_GetError());
    }
    //initialisation des buttons : play,option,quit et du background
    inti_in_option(l, ll,&backo);
    init( qu, pl,op,back,so,mu,sc,&name, yes,no, &yesornooption,newgame,loadgame,&score);
    inp( m,e,f,lettre);
    initText(&t);
    char chedli[30]="";
    //introduction musique
    int vm=100, vsfx=100;
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_Music *music;   	//background music
    Mix_Chunk *swing ;		//son bref
    music= Mix_LoadMUS("menu/OPENMUSIC.mp3");
    Mix_VolumeMusic(vm);
    Mix_PlayMusic(music,-1);
    swing= Mix_LoadWAV("menu/swing.wav");
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

        Mix_VolumeMusic((vm/4)*s);
        Mix_VolumeChunk(swing,(vsfx/4)*ef);
        if ((o!=2)&&(odone!=1)&&(q!=2)&&(qdone!=1)&&(p!=2)&&(pdone!=1)&&(ssc!=2)&&(sdone!=1)&&(newdone!=1)&&((pdone!=1)&&(newdone==0))&& solo!=2&&solodone==0)
        {
            afficher(pl[p],screen);
            afficher(op[o],screen);
            afficher(qu[q],screen);
            afficher(name,screen);
            afficher(sc[ssc],screen);
            displayText(t,screen);
            d=1;
        }
        if((solo==2)||solodone==1)
        {
            oo++;
            
if(d)
{


            afficher_perso (&per,screen);
d=clavier (chedli,screen,police);

}
else 
{
sdone=0;
solo=0;
}
        }
        if((new==2 || newdone==1)&&(pdone!=0)&&(ssc!=2)&&(sdone!=1)&&solodone==0)
        {
            oo++;
            afficher(mu[multi],screen);
            afficher(so[solo],screen);
        }
        if ((o==2)||(odone==1))
        {
            oo++;
            afficher(backo,screen);
            afficher(m[mus],screen);
            afficher(e[effect],screen);
            afficher(f[fleche],screen);
            afficher(lettre[let],screen);
            afficher(l[s],screen);
            afficher(ll[ef],screen);

        }
        if((q==2)||(qdone==1))
        {
            oo++;
            afficher(yesornooption,screen);
            afficher(yes[y],screen);
            afficher(no[n],screen);
        }
        if((p==2)||(pdone==1) && newdone==0  && new!=2&& load!=2)
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
        if(oo>7)
        {
            i++;
            oo=0;

        animation(&per,choix);
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

            if(new!=2)
            {
                new=0;
                load=0;
            }

            multi=0;
            solo=0;


            y=0;
            n=0;
            if (event.motion.x>150&& event.motion.y>452 && event.motion.x<610 && event.motion.y<600 )
            {

                fleche=1;
                let=0;
                c++;
            }


            if (event.motion.x>450&& event.motion.y>452 && event.motion.x<910 && event.motion.y<600 )
            {
                fleche=0;
                let=1;
                c++;
            }
            if(newdone==1)
            {
            if (event.motion.x>270&& event.motion.y>320 && event.motion.x<550 && event.motion.y<420)
            {
                solo=1;
                c++;
            }}
            if (event.motion.x>220&& event.motion.y>500 && event.motion.x<420 && event.motion.y<660 )
            {
                multi=1;
                c++;
            }
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
            if((c==1)&&(ef!=0))
                Mix_PlayChannel(-1, swing, 0);

            if((p==2)||(pdone==1) && newdone==0 )
            {
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

            if (event.button.button==SDL_BUTTON_LEFT)
            {
                if((p==2)||(pdone==1) && newdone==0 )
                {
                    if((new==1)&&(pdone==1))
                    {
                        newdone=1;
                        new=2;
                        load=2;
                        p=0;
                    }
                }
                
                if(solo==1)
                {
                    solo=2;
                    solodone=1;

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
            if(ef!=0)
                Mix_PlayChannel(-1, swing, 0);

            switch(event.key.keysym.sym)
            {
            case SDLK_RIGHT:
                if ((odone==1)&&(s!=4)&&(mus==1))
                {
                    s++;
                    SDL_Delay(100);
                }
                if ((odone==1)&&(ef!=4)&&(effect==1))
                {
                    ef++;
                    SDL_Delay(100);
                }
                break;
            case SDLK_s:
                ssc=1;
                break;
            case SDLK_LEFT:

                if ((odone==1)&&(s!=0)&&(mus==1))
                {

                    s--;
                    SDL_Delay(100);
                }
                if ((odone==1)&&(ef!=0)&&(effect==1))
                {

                    ef--;
                    SDL_Delay(100);
                }


                break;
            case SDLK_UP:

                if(mus==0)
                {
                    mus=1;
                    effect=0;
                }
                else
                {
                    effect=1;
                    mus=0;
                }

                if (p==1 )
                {
                    q=1;
                    p=0;
                    o=0;
                    ssc=0;
                }
                else if(ssc==1 )
                {
                    p=1;
                    o=0;
                    q=0;
                    ssc=0;
                }

                else if(o==1 )
                {
                    p=0;
                    o=0;
                    q=0;
                    ssc=1;
                }
                else if (q==1 )
                {
                    o=1;
                    q=0;
                    p=0;
                    ssc=0;
                }
                if(p==0 && o==0 && q==0&&ssc==0)
                {
                    p=1;
                }
                SDL_Delay(100);
                break ;
            case SDLK_DOWN:

                if(effect==0)
                {
                    effect=1;
                    mus=0;
                }
                else
                {
                    effect=0;
                    mus=1;
                }

                if (p==1 )
                {
                    p=0;
                    o=0;
                    q=0;
                    ssc=1;
                }
                else if(ssc==1 )
                {
                    p=0;
                    o=1;
                    q=0;
                    ssc=0;
                }
                else if(o==1 )
                {
                    p=0;
                    o=0;
                    q=1;
                    ssc=0;
                }
                else if (q==1 )
                {
                    o=0;
                    q=0;
                    p=1;
                    ssc=0;
                }
                if (p==0 && o==0 && q==0 && ssc==0 )
                {
                    q=1;
                }
                if ((o==2)||(odone==1))
                {}
                SDL_Delay(100);
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
                {
                    newdone=0;
                    new=0;
                    pdone=1;
                }
                if (solodone==1)
                solodone=0;
                break ;
            case SDLK_m:
                if(s=!0)
                {
                    s=0;
                    ef=0;
                }

                break;
            case SDLK_n:
                y=0;
                n=1;
                break;
            case SDLK_y:
                y=1;
                n=0;
                break;
            case SDLK_KP_ENTER :
                if (y==1)
                    done=0;
                else if ((n==1) && (qdone==1))
                    qdone=0;
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
                else if (ssc==1)
                {
                    ssc=2;
                }
                break;
            }
            break;
        case SDL_QUIT:
        
            done=0;
            break;
        }
    }
}

