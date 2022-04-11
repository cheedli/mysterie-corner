#include "enigme.h"
//fonction taamlk initialisation lil tableau t3 les botouns o tsawer win or lose
void initImages(image boutoun[],image winorlose[])
{
 int i;
 //tableau ta3 repp fyh zouz tsawer taswira win o taswira lose
winorlose[0].img=IMG_Load("w.png");
winorlose[1].img=IMG_Load("l.png");

winorlose[0].pos.x=0;
winorlose[0].pos.y=0;
winorlose[1].pos.x=0;
winorlose[1].pos.y=0;
    

for(i=0;i<3;i++)
//tableau fyh l kol nafs e tasswira fyh l bouton e saghroun ly fyh les reponses
    boutoun[i].img=IMG_Load("b.png");


    boutoun[0].pos.x=200;
    boutoun[0].pos.y=400;
   
    boutoun[1].pos.x=550;
    boutoun[1].pos.y=400;
    
    boutoun[2].pos.x=900;
    boutoun[2].pos.y=400;


}

void InitEnigme(enigme *e, char *nomfichier)

{
	int numerodequestion=0;//nomrou l question or d'autre façon anahuwa star ly bch yekhdh menou kol chy

    srand(time(0));//tb3a random chaalik feha
    e->choix_question=(rand() % (4)) +1;//bch taatik 3dad aleatoire mabyn 1 et 4

    SDL_Color couleurNoire= {0,0,0};
    TTF_Font *police;

    police = TTF_OpenFont("f.otf", 30);//ism l police ily bch testaamlha o taille

    FILE *F;
    
    F=fopen(nomfichier, "r");//7alina fichier en mode read
    
    if(F!=NULL)//idha l fichier mawjoud
	    {
		while((fscanf(F,"%s , %s , %s , %s  %d\n",e->question,e->r1,e->r2,e->r3,&(e->reponsejuste))!=EOF)&&( numerodequestion!=e->choix_question))//fscanf bch tkhazen  les variables  o nombre de question yaani bch youssl lil sstar ly hchtou bih
		{
		    numerodequestion++;;
		}
	    }
    else 
	    printf("erreur lors de l'execution du fichier\n");
	    fclose(F);//sakrna l fichier


	printf("%s \n %d \n",e->question,e->reponsejuste);

    e->quest= TTF_RenderText_Solid (police,e->question,couleurNoire);//n7adher fy surface t3 text lil question o les reponse yaani kol wahda andha police mt3ha o chnuwa chaine de caharactere ly bch tkoun feha o l couleur mt3ha
    e->posQuestion.x=300;
    e->posQuestion.y=250;

    e->reponses[0]= TTF_RenderText_Blended (police,e->r1,couleurNoire);
     e->posRepones[0].x=250;
    e->posRepones[0].y=450;
    
    e->reponses[1]= TTF_RenderText_Blended (police,e->r2,couleurNoire);
    
    e->posRepones[1].x=620;
    e->posRepones[1].y=450;

    e->reponses[2]= TTF_RenderText_Blended (police,e->r3,couleurNoire);
 e->posRepones[2].x=980;
    e->posRepones[2].y=450;

}


void afficherEnigme(enigme *e, SDL_Surface *screen)

{//affichage mt3 question o les 3 reponses

    SDL_BlitSurface(e->quest,NULL,screen,&(e->posQuestion));
    SDL_BlitSurface(e->reponses[0],NULL,screen,&(e->posRepones[0]));
    SDL_BlitSurface(e->reponses[1],NULL,screen,&(e->posRepones[1]));
    SDL_BlitSurface(e->reponses[2],NULL,screen,&(e->posRepones[2]));

}

void afficherbutton(image a, SDL_Surface *screen)
			
{//affichage t3 l bouton
    SDL_BlitSurface(a.img,NULL,screen,&a.pos);
}

void animer (enigme *e)
{
SDL_Surface *horloge[10];
SDL_Rect p;

    time_t debut,fin;
    TTF_Init();//initialisation t3 text
    SDL_Init(SDL_INIT_VIDEO);//initialisition t3 l ecran
    debut=clock();
    SDL_Surface *screen;
    SDL_Surface *back=NULL,*b;

    SDL_Rect pos,bpos;

 

    int done=1,done1=1,rep=0,temps=0;//done heya m loul blkol o done1 heya ky tkhtar wahda shyha o r heya reponse ly bch ykhtarha utilisateur


    SDL_Event event;

    screen=SDL_SetVideoMode(1380,700,32,SDL_HWSURFACE  );//initialisation t3 screen
    if(!screen)
    {
        printf("Unable de set 600x300 video: %s\n", SDL_GetError());
    }
    back= IMG_Load("bac.png");//initialisation t3 background
    pos.x=0;
    pos.y=0;
    
    p.x=680;
p.y=320;
    

b=IMG_Load("b1.png");//initialisation t3 l boutons fbly t3awdet khaleha haka

bpos.x=200;
bpos.y=400;



    image boutoun[3],winorlose[2];//declaration t3 bouton ly huma 3 kaabet o tableau winorlose
   inithorloge(horloge);
   initImages(boutoun,winorlose);//initialisation t3 les tableau
    InitEnigme(e,"enigme.txt");
    while(done1)//done1 yaani baad matjewb bch y93d ywarik fy tasswirt win wala lose lin tnzel 3al echarp o yufa l prog
    {
    while(done)//done yaani madmk mazlt majwbtch l taw bch yb9a ywari fik fyl les reponse lin tjwb
    {
    fin=clock();
        temps=(fin-debut)/CLOCKS_PER_SEC;
        if(temps==9)
        done=0;

        SDL_BlitSurface(back,NULL,screen,&pos);//affichage du background
         SDL_BlitSurface(horloge[temps],NULL,screen,&p);

        afficherbutton(boutoun[0], screen);
        afficherbutton(boutoun[1], screen);
        afficherbutton(boutoun[2], screen);
       afficherEnigme(e,screen);//affichage t3 question o les reponses
        SDL_Flip(screen);//refrichessement d'ecran

        SDL_PollEvent(&event);//bch y93d ydour may9fch l prog


        switch(event.type)//selon l event ly bch yssir
        {
        case SDL_QUIT://idha nty sakrt l prog mn l kaaboura l hamra ytsaker
        {
            done=0;//condition d'arret du prog
        }
        break;




        case SDL_KEYDOWN://idha massyt heja bl clavier
        {

            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                done = 0;
            }


            switch(event.key.keysym.sym)
            {
            
            case SDLK_a:
                               
                rep=1;//bch y9aydlk anahya reponse ly bch tkhtarha o baadika y9aren b reponse shyha
                break;
            case SDLK_q://7atina q khtr fama des clavier l boton a o l boton q ma9loubin
                rep=1;
                break;
            case SDLK_b:
                rep=2;
                break;
            case SDLK_c:
                rep=3;
                break;
                 case SDLK_SPACE://SDL may9rch l boton t3 l entree donc idha khtrt wehd ml les reponses o nzlt espace bch y9olk rbe7t wala khsart

                        done=0;
                break;
                
               
               

                
            }
        }
        break;
        case SDL_MOUSEMOTION: //le cas  ou 9a3da testaaml  fyl souris
            	
rep=0;

            if (event.motion.x>220 && event.motion.y>400 && event.motion.x<520 && event.motion.y<550 )//hedhy yaani idha huwa fyl perimetre t3 l boton heka o same for the others
            {
                            rep=1;


            }
            if (event.motion.x>570 && event.motion.y>400 && event.motion.x<870 && event.motion.y<550)
            {
                            rep=2;

            }
            if (event.motion.x>920 && event.motion.y>400 && event.motion.x<1220 && event.motion.y<550 )
            {                rep=3;

            }
            
             case SDL_MOUSEBUTTONDOWN://idha nzelt 3al l boutons heka o nty deja fyl perimetre t3 botton bch ytnzel alih o  yaatik resultat
             
            if (event.button.button==SDL_BUTTON_LEFT)
            {
                if (rep!=0)
                
		done=0;
                }
        }
    }

            SDL_PollEvent(&event);
    if(event.key.keysym.sym == SDLK_ESCAPE)//idha nzelt 3al echarpe prog yufa
            {
                done1= 0;
            }
if(rep==e->reponsejuste){//idha khtrt shyha bch tjik you win o same lily ta7tha bch tjik you lose
       afficherbutton(winorlose[0], screen);
      }
else {
       SDL_BlitSurface(b,NULL,screen,&bpos);
        afficherbutton(winorlose[1], screen);
}
                   SDL_Flip(screen);
}}

void inithorloge(SDL_Surface *horloge[])
{

horloge[0] =IMG_Load("horloge/1horloge.gif");
horloge[1] =IMG_Load("horloge/2horloge.gif");
horloge[2] =IMG_Load("horloge/3horloge.gif");
horloge[3] =IMG_Load("horloge/4horloge.gif");
horloge[4] =IMG_Load("horloge/5horloge.gif");
horloge[5] =IMG_Load("horloge/6horloge.gif");
horloge[6] =IMG_Load("horloge/7horloge.gif");
horloge[7] =IMG_Load("horloge/8horloge.gif");
horloge[8] =IMG_Load("horloge/9horloge.gif");
horloge[9] =IMG_Load("horloge/10horloge.gif");


}

    
