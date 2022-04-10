#include "test.h"


void initialiser_perso (perso *p)
{
p->personnage=IMG_Load("pic/stop.png");
p->rect.x=0;//perso
p->rect.y=100; 
p->direction=0;
p->pos_sprite.x=0;
p->pos_sprite.y=0;
p->pos_sprite.h=p->personnage->h;
p->pos_sprite.w=p->personnage->w/9;
p->vitesse_V=0;

p->vitesse=5;
p->acceleration=0;



}
void initialiser_jump (perso *p)
{
p->personnage=IMG_Load("pic/jump.png");
p->rect.x=0;//perso
p->rect.y=100; // position mtaa il surface 
p->direction=0;
p->pos_sprite.x=0;
p->pos_sprite.y=0;
p->pos_sprite.h=p->personnage->h;
p->pos_sprite.w=p->personnage->w/6;
p->vitesse_V=0;

p->vitesse=0;
p->acceleration=0;




}
void initialiser_walk (perso *p)
{
p->personnage=IMG_Load("pic/walk.png");
p->rect.x=0;//perso
p->rect.y=100; // position mtaa il surface 
p->direction=0;
p->pos_sprite.x=0;
p->pos_sprite.y=0;
p->pos_sprite.h=p->personnage->h;
p->pos_sprite.w=p->personnage->w/5;
p->vitesse_V=0;


p->vitesse=5;
p->acceleration=0;

}
void initialiser_wl (perso *p)
{
p->personnage=IMG_Load("pic/wl.png");
p->rect.x=400;//perso
p->rect.y=100; 
p->direction=0;
p->pos_sprite.x=0;
p->pos_sprite.y=0;
p->pos_sprite.h=p->personnage->h;
p->pos_sprite.w=p->personnage->w/5;
p->vitesse_V=0;

p->vitesse=5;
p->acceleration=0;



}


 

void afficher_perso (perso p,SDL_Surface *screen)
{
  SDL_BlitSurface(p.personnage,&p.pos_sprite,screen,&p.rect);//rect benesba l pos
}






void animation (perso *p,Input i){
  if (i.right==1 && p->pos_sprite.x >=1140)//hya ekher taswira l hya x=4500
  {
    p->pos_sprite.x =0;
  }else p->pos_sprite.x +=228;

 if (i.jump==1 && p->pos_sprite.x >=1080)//hya ekher taswira l hya x=4500
  {
    p->pos_sprite.x =0;
  }else p->pos_sprite.x +=179;

 if (i.left==1 && p->pos_sprite.x >=1250)//hya ekher taswira l hya x=4500
  {
    p->pos_sprite.x =0;
  }else p->pos_sprite.x +=250;
}



void movePerso(perso *p,Uint32 dt,Input i){//(diff de temps kadeh aandha bdet boucle hata sar deplacement)
double dx;// vitesse
dx= 0.5 * dt * dt * p->acceleration + dt*p->vitesse;
if (i.right==1) //k yabda f a droite donc 2
{
  p->rect.x += dx;
}else  if (i.left==1) {p->rect.x -= dx ;} // gauche


}



void saut (perso *p) {
  if(p->rect.y==100)//collision with ground=300 sinon maynajmch
		p->vitesse_V = -60;// verticale (yatlaa fouk)
}

void initialiser_input (Input *I)
{
I->left=0;
I->right=0;
I->jump=0;

}

