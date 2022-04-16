#include "enigme.h"
void initImages(image boutoun[],image winorlose[])
{
 int i;

winorlose[0].img=IMG_Load("w.png");
winorlose[1].img=IMG_Load("l.png");

winorlose[0].pos.x=0;
winorlose[0].pos.y=0;
winorlose[1].pos.x=0;
winorlose[1].pos.y=0;
    

for(i=0;i<3;i++)

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
	int numerodequestion=0;

    srand(time(0));
    e->choix_question=(rand() % (4)) +1;

    SDL_Color couleurNoire= {0,0,0};
    TTF_Font *police;

    police = TTF_OpenFont("f.otf", 30);

    FILE *F;
    
    F=fopen(nomfichier, "r");
    
    if(F!=NULL)
	    {
		while((fscanf(F,"%s , %s , %s , %s  %d\n",e->question,e->r1,e->r2,e->r3,&(e->reponsejuste))!=EOF)&&( numerodequestion!=e->choix_question)) 
		{
		    numerodequestion++;;
		}
	    }
    else 
	    printf("erreur lors de l'execution du fichier\n");
	    fclose(F);


	printf("%s \n %d \n",e->question,e->reponsejuste);

    e->quest= TTF_RenderText_Solid (police,e->question,couleurNoire);
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

{

    SDL_BlitSurface(e->quest,NULL,screen,&(e->posQuestion));
    SDL_BlitSurface(e->reponses[0],NULL,screen,&(e->posRepones[0]));
    SDL_BlitSurface(e->reponses[1],NULL,screen,&(e->posRepones[1]));
    SDL_BlitSurface(e->reponses[2],NULL,screen,&(e->posRepones[2]));

}

void afficherbutton(image a, SDL_Surface *screen)
			
{
    SDL_BlitSurface(a.img,NULL,screen,&a.pos);
}

void animer (enigme *e)
{
SDL_Surface *horloge[10];
SDL_Rect p;

    time_t debut,fin;
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    debut=clock();
    SDL_Surface *screen;
    SDL_Surface *back=NULL,*b;

    SDL_Rect pos,bpos;

 

    int done=1,done1=1,rep=0,temps=0;


    SDL_Event event;

    screen=SDL_SetVideoMode(1380,700,32,SDL_HWSURFACE  );
    if(!screen)
    {
        printf("Unable de set 600x300 video: %s\n", SDL_GetError());
    }
    back= IMG_Load("bac.png");
    pos.x=0;
    pos.y=0;
    
    p.x=680;
p.y=320;
    

b=IMG_Load("b1.png");

bpos.x=200;
bpos.y=400;  



    image boutoun[3],winorlose[2];
   inithorloge(horloge);
   initImages(boutoun,winorlose);
    InitEnigme(e,"enigme.txt");
    while(done1)
    {
    while(done)
    {
    fin=clock();
        temps=(fin-debut)/CLOCKS_PER_SEC;
        if(temps==9)
        done=0;

        SDL_BlitSurface(back,NULL,screen,&pos);
         SDL_BlitSurface(horloge[temps],NULL,screen,&p);

        afficherbutton(boutoun[0], screen);
        afficherbutton(boutoun[1], screen);
        afficherbutton(boutoun[2], screen);
       afficherEnigme(e,screen);
        SDL_Flip(screen);

        SDL_PollEvent(&event);


        switch(event.type)
        {
        case SDL_QUIT:
        {
            done=0;
        }
        break;




        case SDL_KEYDOWN:
        {

            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                done = 0;
            }


            switch(event.key.keysym.sym)
            {
            
            case SDLK_a:
                               
                rep=1;
                break;
            case SDLK_q:
                rep=1;
                break;
            case SDLK_b:
                rep=2;
                break;
            case SDLK_c:
                rep=3;
                break;
                 case SDLK_SPACE:

                        done=0;
                break;
                
               
               

                
            }
        }
        break;
        case SDL_MOUSEMOTION: 
            	
rep=0;

            if (event.motion.x>220 && event.motion.y>400 && event.motion.x<520 && event.motion.y<550 )
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
            
             case SDL_MOUSEBUTTONDOWN:
             
            if (event.button.button==SDL_BUTTON_LEFT)
            {
                if (rep!=0)
                
		done=0;
                }
        }
    }

            SDL_PollEvent(&event);
    if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                done1= 0;
            }
if(rep==e->reponsejuste){
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

    
