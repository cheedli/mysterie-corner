#include"header.h"
int main(int argc, char** argv)
{
    int done=1,o=0,p=0,q=0;
    image q1, q21, q22, q23, q31, q32, q33;
    image o1,o21,o22,o23,o31,o32, o33;
    image p1,p21,p22,p23, p31, p32, p33;
    SDL_Init ( SDL_INIT_VIDEO );
    SDL_Surface* screen;
    image backg;
    SDL_Event event;
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,SDL_HWSURFACE|SDL_HWSURFACE);
    if ( !screen )
    {
        printf("Unable to set 1920x1080video: %s\n", SDL_GetError());
        return 1;
    }
    SDL_WM_SetCaption("MYSTERIOUS-CORNER", NULL);
    initBackground(&backg);
    initplay(&p1, &p21, &p22, &p23, &p31, &p32,&p33);
    initquit(&q1, &q21, &q22, &q23, &q31, &q32,&q33);
    initoption(&o1, &o21, &o22,&o23,&o31,&o32,&o33);

    while (done)
    {
        afficher(backg,screen);
        afficher(p1,screen);
        afficher(o1,screen);
        afficher(q1,screen);
        SDL_Flip(screen);
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:

            SDL_FreeSurface(screen);
            return 0;
            break ;
        case SDL_KEYDOWN:

            switch(event.key.keysym.sym)
            {

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
                o=0;
                q=0;
                p=1;
                break;
            case SDLK_q:
                o=0;
                q=1;
                p=0;

                break;
            case SDLK_o:
                p=0;
                o=1;

                q=0;
                break;
            }
            break;

//avec souris

        case SDL_MOUSEMOTION:
            q=0;
            p=0;
            o=0;
            if (event.motion.x>210 && event.motion.y>320 && event.motion.x<460 && event.motion.y<570 )
            {
                p=1;
            }

            else if (event.motion.x>210 && event.motion.y>400 && event.motion.x<460 && event.motion.y<650 )
            {
                o=1;
            }

            else if (event.motion.x>210 && event.motion.y>500 && event.motion.x<460 && event.motion.y<750 )
            {
                q=1;
            }

            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button==SDL_BUTTON_RIGHT)
            {
                if (p==1)
                {
                    p=2;
                }
                else if (o==1)
                {
                    o=2;
                }

                else if (q==1)
                {
                    q=2;
                }
            }
            break;


        }
        if(p==1)
        {
            fre(p1);
            afficher(p21,screen);
 	    fre(p21);
            afficher(p22,screen);
            fre(p22);
            afficher(p23,screen);
        SDL_Flip(screen);
        }
        if(p==2)
        {
            
            fre(p23);
            afficher(p31,screen);
            fre(p31);
            afficher(p32,screen);
	    fre(p32);
            afficher(p33,screen);
        SDL_Flip(screen);
        }
         if(o==1)
        {
            fre(o1);
            afficher(o21,screen);
	    fre(o21);
            afficher(o22,screen);
            fre(o22);
            afficher(o23,screen);
        SDL_Flip(screen);
        }
        if(o==2)
        {
            
            fre(o23);
            afficher(o31,screen);
            fre(o31);
            afficher(o32,screen);
            fre(o32);
            afficher(o33,screen);
        SDL_Flip(screen);
        }
         if(q==1)
        {
            fre(q1);
            afficher(q21,screen);
	    fre(q21);
            afficher(q22,screen);
            fre(q22);
            afficher(q23,screen);
        SDL_Flip(screen);
        }
        if(q==2)
        {
            
            fre(q23);
            afficher(q31,screen);
	    fre(q31);
            afficher(q32,screen);
	    fre(q32);
            afficher(q33,screen);
        SDL_Flip(screen);
        }
    }
fre(backg);
fre(p1);
fre(p22);
fre(p21);
fre(p23);
fre(p31);
fre(p32);
fre(p33);
fre(q1);
fre(q21);
fre(q22);
fre(q23);
fre(q31);
fre(q32);
fre(q33);
fre(o1);
fre(o21);
fre(o22);
fre(o23);
fre(o31);
fre(o32);
fre(o33);
SDL_Quit();

return 0 ;



}

