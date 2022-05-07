#include "Fonctions.h"








void initialiser_perso (perso *p)
{
p->personnage=IMG_Load("spr.png");
p->rect.x=0;//perso
p->rect.y=100;
p->direction=0;
p->rect.w=48;
p->rect.h=48;
p->vitesse_V=0;

p->pos_sprite.x=0;//mtaa cadre entier
p->pos_sprite.y=0;
p->pos_sprite.h=69;
p->pos_sprite.w=50;

p->vitesse=0;
p->acceleration=0;



}





void afficher_perso (perso *p,SDL_Surface *screen)
{
  SDL_BlitSurface(p->personnage,&p->pos_sprite,screen,&p->rect);//rect benesba l pos
}









void animation (perso *p){
  if (p->pos_sprite.x >=150)//hya ekher taswira l hya x=150
  {
    p->pos_sprite.x =0;
  }else p->pos_sprite.x +=50;
  p->pos_sprite.y = p->direction * 69;//:hasb direction(ken dir 1) des y  kol mankadm

}



void movePerso(perso *p,Uint32 dt){//(diff de temps kadeh aandha bdet boucle hata sar deplacement)
double dx;// vitesse
dx= 0.5 * dt * dt * p->acceleration + dt*p->vitesse;
if ((p->direction==0) || (p->direction==2)) //k yabda f a droite donc 2
{
  p->rect.x += dx;
}else p->rect.x -= dx ; // gauche


}



void saut (perso *p) {
  if(p->rect.y==300)//collision with ground=300 sinon maynajmch
		p->vitesse_V = -60;// verticale (yatlaa fouk)
}

void initialiser_input (Input *I)
{
I->left=0;
I->right=0;
I->jump=0;

}



