
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "minimap.h"
int clavier (char *nom[], SDL_Surface *screen ,TTF_Font *police)
{   SDL_Surface *a,*z,*e,*r,*t,*y,*u,*i,*o,*p,*q,*s,*d,*f,*g,*h,*j,*k,*l,*m,*w,*x,*c,*v,*b,*n,*ok,*texte,*delete;
    SDL_Rect postionimage,posa,posz,pose,posr,post,posy,posu,posi,poso,posp,posq,poss,
posd,posf,posg,posh,posj,posk,posl,posm,posw,posx,posc,posv,posb,posn,posok,position_text={400,430},posdelete;
    SDL_Event event;
    int done=1;
    char rep[30]="";
     
    SDL_Color couleurBlanche = {255,255,255};// couleur de texte
 

  
  

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
	posa.x=200;
	posa.y=550;
	posz.x=250;
	posz.y=550;
	pose.x=300;
	pose.y=550;
	posr.x=350;
	posr.y=550;
	post.x=400;
	post.y=550;
	posy.x=450;
	posy.y=550;
	posu.x=500;
	posu.y=550;
	posi.x=550;
	posi.y=550;
	poso.x=600;
	poso.y=550;
	posp.x=650;
	posp.y=550;
	
	posq.x=200;
	posq.y=600;
	poss.x=250;
	poss.y=600;
	posd.x=300;
	posd.y=600;
	posf.x=350;
	posf.y=600;
	posg.x=400;
	posg.y=600;
	posh.x=450;
	posh.y=600;
	posj.x=500;
	posj.y=600;
	posk.x=550;
	posk.y=600;
	posl.x=600;
	posl.y=600;
	posm.x=650;
	posm.y=600;

	posw.x=300;
	posw.y=650;
	posx.x=350;
	posx.y=650;
	posc.x=400;
	posc.y=650;
	posv.x=450;
	posv.y=650;
	posb.x=500;
	posb.y=650;
	posn.x=550;
	posn.y=650;
	posok.x=600;
	posok.y=650;
	posdelete.x=250;
	posdelete.y=650;
	//pos.x=50;
	//pos.y=250;


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
	


  
        	strcpy(rep,nom);
     SDL_PollEvent(&event);
     switch(event.type)

     {  case SDL_QUIT: 
			done=0;
                         break;
	
	case SDL_MOUSEBUTTONDOWN :
            
            if((event.button.button==SDL_BUTTON_LEFT)&&(event.button.x<posa.x+a->w&&event.button.x>posa.x)&&      
   (event.button.y<posa.y+a->h&&event.button.y>posa.y))

            {
	strcat(rep,"A");}
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

     
		SDL_BlitSurface(texte, NULL,screen,&position_text);
        SDL_Flip(screen);

	
    
	strcpy(nom,rep);

   return done;

}
