#include "enigme.h"

void initImages(image boutoun[],image repp[])
{
 int i;
repp[0].img=IMG_Load("w");
repp[1].img=IMG_Load("lose.jpg");

repp[0].pos.x=0;
repp[0].pos.y=0;
repp[1].pos.x=0;
repp[1].pos.y=0;
    

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
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface *screen;
    SDL_Surface *back=NULL;
    SDL_Rect pos;

int i=0,r=0;

    int done=1,done1=1,direction=0,rose=0,green=0,blue=0;


    SDL_Event event;
    int rep;
    screen=SDL_SetVideoMode(1380,700,32,SDL_HWSURFACE  );
    if(!screen)
    {
        printf("Unable de set 600x300 video: %s\n", SDL_GetError());
    }
    back= IMG_Load("bac.png");
    pos.x=0;
    pos.y=0;







    image boutoun[3],repp[2];
   initImages(boutoun,repp);
    InitEnigme(e,"enigme.txt");
    while(done1)
    {
    while(done)
    {

if((rep!=0)&&(i==0))
{
             
                boutoun[rep-1].pos.y-=20;
                i=1;

                
 }
               if(rep==0) 
                {
    boutoun[0].pos.y=400;
    boutoun[1].pos.y=400;
    boutoun[2].pos.y=400;
    i=0;
    }
                
                    SDL_BlitSurface(back,NULL,screen,&pos);
        afficherbutton(boutoun[0], screen);
        afficherbutton(boutoun[1], screen);
        afficherbutton(boutoun[2], screen);
       afficherEnigme(e,screen);
        SDL_Flip(screen);

        SDL_PollEvent(&event);

        rep=0;
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
       afficherbutton(repp[0], screen);
      }
else {
        afficherbutton(repp[1], screen);
}
                   SDL_Flip(screen);
}}
