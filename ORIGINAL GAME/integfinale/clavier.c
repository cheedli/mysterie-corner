#include "minimap.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
void clavier (char *nom[])
{   SDL_Surface *screen=NULL,*image,*a,*z,*e,*r,*t,*y,*u,*i,*o,*p,*q,*s,*d,*f,*g,*h,*j,*k,*l,*m,*w,*x,*c,*v,*b,*n,*ok,*texte,*delete;
    SDL_Rect 					   			         postionimage,posa,posz,pose,posr,post,posy,posu,posi,poso,posp,posq,poss,
posd,posf,posg,posh,posj,posk,posl,posm,posw,posx,posc,posv,posb,posn,posok,position_text={530,230},posdelete;
    SDL_Event event;
    int done=1;
    char rep[30]="";
    TTF_Font *police = NULL;
    SDL_Color couleurBlanche = {127,20,0};// couleur de texte
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    
    screen=SDL_SetVideoMode(1380,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    


    image=IMG_Load("background.png");
    postionimage.x=0;
    postionimage.y=0;
	delete=IMG_Load("minimap/delete.png");
	a=IMG_Load("minimap/a.png");
	z=IMG_Load("minimap/z.png");
	e=IMG_Load("minimap/e.png");
	r=IMG_Load("minimap/r.png");
	t=IMG_Load("minimap/t.png");
	y=IMG_Load("minimap/y.png");
	u=IMG_Load("minimap/u.png");
	i=IMG_Load("minimap/i.png");
	o=IMG_Load("minimap/o.png");
	p=IMG_Load("minimap/p.png");
	q=IMG_Load("minimap/q.png");
	s=IMG_Load("minimap/s.png");
	d=IMG_Load("minimap/d.png");
	f=IMG_Load("minimap/f.png");
	g=IMG_Load("minimap/g.png");
	h=IMG_Load("minimap/h.png");
	j=IMG_Load("minimap/j.png");
	k=IMG_Load("minimap/k.png");
	l=IMG_Load("minimap/l.png");
	m=IMG_Load("minimap/m.png");
	w=IMG_Load("minimap/w.png");
	x=IMG_Load("minimap/x.png");	
	c=IMG_Load("minimap/c.png");
	v=IMG_Load("minimap/v.png");
	b=IMG_Load("minimap/b.png");
	n=IMG_Load("minimap/n.png");
	ok=IMG_Load("minimap/ok.png");	
	posa.x=400;
	posa.y=300;
	posz.x=450;
	posz.y=300;
	pose.x=500;
	pose.y=300;
	posr.x=550;
	posr.y=300;
	post.x=600;
	post.y=300;
	posy.x=650;
	posy.y=300;
	posu.x=700;
	posu.y=300;
	posi.x=750;
	posi.y=300;
	poso.x=800;
	poso.y=300;
	posp.x=850;
	posp.y=300;
	
	posq.x=400;
	posq.y=350;
	poss.x=450;
	poss.y=350;
	posd.x=500;
	posd.y=350;
	posf.x=550;
	posf.y=350;
	posg.x=600;
	posg.y=350;
	posh.x=650;
	posh.y=350;
	posj.x=700;
	posj.y=350;
	posk.x=750;
	posk.y=350;
	posl.x=800;
	posl.y=350;
	posm.x=850;
	posm.y=350;
	
	posw.x=500;
	posw.y=400;
	posx.x=550;
	posx.y=400;
	posc.x=600;
	posc.y=400;
	posv.x=650;
	posv.y=400;
	posb.x=700;
	posb.y=400;
	posn.x=750;
	posn.y=400;
	posok.x=800;
	posok.y=400;
	posdelete.x=450;
	posdelete.y=400;
	//pos.x=50;
	//pos.y=250;

	police = TTF_OpenFont("minimap/Montserrat-Regular.ttf", 30);
	

        SDL_BlitSurface(image, NULL,screen,&postionimage);
	SDL_BlitSurface(a,NULL,screen,&posa);
	SDL_BlitSurface(z,NULL,screen,&posz);
	SDL_BlitSurface(e,NULL,screen,&pose);
	SDL_BlitSurface(r,NULL,screen,&posr);
	SDL_BlitSurface(t,NULL,screen,&post);
	SDL_BlitSurface(y,NULL,screen,&posy);
	SDL_BlitSurface(u,NULL,screen,&posu);
	SDL_BlitSurface(i,NULL,screen,&posi);
	SDL_BlitSurface(o,NULL,screen,&poso);
	SDL_BlitSurface(p,NULL,screen,&posp);
	SDL_BlitSurface(q,NULL,screen,&posq);
	SDL_BlitSurface(s,NULL,screen,&poss);
	SDL_BlitSurface(d,NULL,screen,&posd);
	SDL_BlitSurface(f,NULL,screen,&posf);
	SDL_BlitSurface(g,NULL,screen,&posg);
	SDL_BlitSurface(h,NULL,screen,&posh);
	SDL_BlitSurface(j,NULL,screen,&posj);
	SDL_BlitSurface(k,NULL,screen,&posk);
	SDL_BlitSurface(l,NULL,screen,&posl);
	SDL_BlitSurface(m,NULL,screen,&posm);
	SDL_BlitSurface(w,NULL,screen,&posw);
	SDL_BlitSurface(x,NULL,screen,&posx);
	SDL_BlitSurface(c,NULL,screen,&posc);
	SDL_BlitSurface(v,NULL,screen,&posv);
	SDL_BlitSurface(b,NULL,screen,&posb);
	SDL_BlitSurface(n,NULL,screen,&posn);
    SDL_BlitSurface(ok,NULL,screen,&posok);
	 SDL_BlitSurface(delete,NULL,screen,&posdelete);
	SDL_Flip(screen);


    while(done)
    {  
	
    
     SDL_WaitEvent(&event);
     switch(event.type)

     {  case SDL_QUIT: 
			done=0;
                         break;
	
	case SDL_MOUSEBUTTONDOWN :
            
            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posa.x+a->w&&event.button.x>posa.x)&&      
   (event.button.y<posa.y+a->h&&event.button.y>posa.y))

            {
	strcat(rep,"A");
	

        

		}
		 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posz.x+z->w&&event.button.x>posz.x)&&
(event.button.y<posz.y+z->h&&event.button.y>posz.y))

            {	strcat(rep,"Z");

		}
	 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<pose.x+e->w&&event.button.x>pose.x)&&
(event.button.y<pose.y+e->h&&event.button.y>pose.y))

            {	strcat(rep,"E");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posr.x+r->w&&event.button.x>posr.x)&&
(event.button.y<posr.y+r->h&&event.button.y>posr.y))

            {	strcat(rep,"R");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<post.x+t->w&&event.button.x>post.x)&&
(event.button.y<post.y+t->h&&event.button.y>post.y))

            {	strcat(rep,"T");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posy.x+y->w&&event.button.x>posy.x)&&
(event.button.y<posy.y+y->h&&event.button.y>posy.y))

            {	strcat(rep,"Y");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posu.x+u->w&&event.button.x>posu.x)&&
(event.button.y<posu.y+u->h&&event.button.y>posu.y))

            {	strcat(rep,"U");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posi.x+i->w&&event.button.x>posi.x)&&
(event.button.y<posi.y+i->h&&event.button.y>posi.y))

            {	strcat(rep,"I");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<poso.x+o->w&&event.button.x>poso.x)&&
(event.button.y<poso.y+o->h&&event.button.y>poso.y))

            {	strcat(rep,"O");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posp.x+p->w&&event.button.x>posp.x)&&
(event.button.y<posp.y+p->h&&event.button.y>posp.y))

            {	strcat(rep,"P");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posq.x+q->w&&event.button.x>posq.x)&&
(event.button.y<posq.y+q->h&&event.button.y>posq.y))

            {	strcat(rep,"Q");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<poss.x+s->w&&event.button.x>poss.x)&&
(event.button.y<poss.y+z->h&&event.button.y>poss.y))

            {	strcat(rep,"S");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posd.x+d->w&&event.button.x>posd.x)&&
(event.button.y<posd.y+d->h&&event.button.y>posd.y))

            {	strcat(rep,"D");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posf.x+f->w&&event.button.x>posf.x)&&
(event.button.y<posf.y+f->h&&event.button.y>posf.y))

            {	strcat(rep,"F");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posg.x+g->w&&event.button.x>posg.x)&&
(event.button.y<posg.y+g->h&&event.button.y>posg.y))

            {	strcat(rep,"G");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posh.x+h->w&&event.button.x>posh.x)&&
(event.button.y<posh.y+h->h&&event.button.y>posh.y))

            {	strcat(rep,"H");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posj.x+j->w&&event.button.x>posj.x)&&
(event.button.y<posj.y+j->h&&event.button.y>posj.y))

            {	strcat(rep,"J");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posk.x+k->w&&event.button.x>posk.x)&&
(event.button.y<posk.y+k->h&&event.button.y>posk.y))

            {	strcat(rep,"K");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posl.x+l->w&&event.button.x>posl.x)&&
(event.button.y<posl.y+l->h&&event.button.y>posl.y))

            {	strcat(rep,"L");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posm.x+m->w&&event.button.x>posm.x)&&
(event.button.y<posm.y+m->h&&event.button.y>posm.y))

            {	strcat(rep,"M");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posw.x+w->w&&event.button.x>posw.x)&&
(event.button.y<posw.y+w->h&&event.button.y>posw.y))

            {	strcat(rep,"W");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posx.x+x->w&&event.button.x>posx.x)&&
(event.button.y<posx.y+x->h&&event.button.y>posx.y))

            {	strcat(rep,"X");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posc.x+c->w&&event.button.x>posc.x)&&
(event.button.y<posc.y+c->h&&event.button.y>posc.y))

            {	strcat(rep,"C");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posv.x+v->w&&event.button.x>posv.x)&&
(event.button.y<posv.y+v->h&&event.button.y>posv.y))

            {	strcat(rep,"V");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posb.x+b->w&&event.button.x>posb.x)&&
(event.button.y<posb.y+b->h&&event.button.y>posb.y))

            {	strcat(rep,"B");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posn.x+n->w&&event.button.x>posn.x)&&
(event.button.y<posn.y+n->h&&event.button.y>posn.y))

            {	strcat(rep,"N");

		}
 if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posok.x+ok->w&&event.button.x>posok.x)&&
(event.button.y<posok.y+ok->h&&event.button.y>posok.y))

            {
            done=0;
		
		
	}
if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posdelete.x+delete->w&&event.button.x>posdelete.x)&&
(event.button.y<posdelete.y+delete->h&&event.button.y>posdelete.y))

            {
		rep[strlen(rep)-1] = '\0';

	    }
      
     }  
texte = TTF_RenderText_Blended(police, rep, couleurBlanche);	
	SDL_BlitSurface(image, NULL,screen,&postionimage); 
       SDL_BlitSurface(a,NULL,screen,&posa);
	SDL_BlitSurface(z,NULL,screen,&posz);
	SDL_BlitSurface(e,NULL,screen,&pose);
	SDL_BlitSurface(r,NULL,screen,&posr);
	SDL_BlitSurface(t,NULL,screen,&post);
	SDL_BlitSurface(y,NULL,screen,&posy);
	SDL_BlitSurface(u,NULL,screen,&posu);
	SDL_BlitSurface(i,NULL,screen,&posi);
	SDL_BlitSurface(o,NULL,screen,&poso);
	SDL_BlitSurface(p,NULL,screen,&posp);
	SDL_BlitSurface(q,NULL,screen,&posq);
	SDL_BlitSurface(s,NULL,screen,&poss);
	SDL_BlitSurface(d,NULL,screen,&posd);
	SDL_BlitSurface(f,NULL,screen,&posf);
	SDL_BlitSurface(g,NULL,screen,&posg);
	SDL_BlitSurface(h,NULL,screen,&posh);
	SDL_BlitSurface(j,NULL,screen,&posj);
	SDL_BlitSurface(k,NULL,screen,&posk);
	SDL_BlitSurface(l,NULL,screen,&posl);
	SDL_BlitSurface(m,NULL,screen,&posm);
	SDL_BlitSurface(w,NULL,screen,&posw);
	SDL_BlitSurface(x,NULL,screen,&posx);
	SDL_BlitSurface(c,NULL,screen,&posc);
	SDL_BlitSurface(v,NULL,screen,&posv);
	SDL_BlitSurface(b,NULL,screen,&posb);
	SDL_BlitSurface(n,NULL,screen,&posn);
	SDL_BlitSurface(ok,NULL,screen,&posok);
	SDL_BlitSurface(texte, NULL,screen,&position_text);
	SDL_BlitSurface(delete,NULL,screen,&posdelete);
        SDL_Flip(screen);

	
    }
	strcpy(nom,rep);

   
}
