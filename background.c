#include "background.h"



void initBackMasque (background *b)
{
//background
b->imgback=IMG_Load("ba1.png");
b->posback.x=0;
b->posback.y=0;

//camera
b->camera.x=0;
b->camera.y=0;
b->camera.w=2048; 
b->camera.h=429;
b->son=Mix_LoadMUS("musique.mp3");
}

void initBack2 (background *b)
{
//background2
b->imgback=IMG_Load("ba.png");
b->posback2.x=0;
b->posback2.y=0;
//camera2
b->camera2.x=0;
b->camera2.y=0;
b->camera2.w=2048; 
b->camera2.h=429;
//musique
b->son=Mix_LoadMUS("musique.mp3"); //Chargement de la musique
	b->image_flower=IMG_Load("flower.png");  
	b->pos_image_flower.x=100;
	b->pos_image_flower.y=300;
	
	b->single_flower.w=56;
	b->single_flower.h=107;
	b->single_flower.x=0;
	b->single_flower.y=0;

	b->flower_num=0;

}


void initialisation_back(background *b)
{
	//initBackMasque(b);	
	initBack2(b);
}



void afficheBack (background b, SDL_Surface *ecran)
{
/* On blitte par-dessus l'écran */
Mix_PlayMusic(b.son, -1);
SDL_BlitSurface(b.imgback,&b.camera,ecran,&b.posback);
}

void afficheBack2 (background b, SDL_Surface *ecran)
{
/* On blitte par-dessus l'écran */
Mix_PlayMusic(b.son, -1); //Jouer infiniment la musique
SDL_BlitSurface(b.imgback,&b.camera2,ecran,&b.posback2);
displayFlower(b,ecran);

}
/*void afficher_back(background b, SDL_Surface *ecran)
{
	afficheBack(b,ecran);
	afficheBack2(b,ecran);
	
}*/

void scrolling (background *b,int direction)
{
 const int speed=5;
if (direction ==0){//right  
	b->camera.x+= speed;          

	b->camera2.x+= speed;
	
        }
else if (direction ==1){//left         
	b->camera.x-=speed; 

	b->camera2.x-=speed; 
	}


else if (direction ==2){//up  
        b->camera.y-= speed;

         b->camera2.y-= speed;
	}
else if (direction ==3){//down       
        b->camera.y+= speed;

	 b->camera2.y+= speed;
	 }

}


void displayFlower(background b,SDL_Surface *ecran){
			
 		SDL_BlitSurface(b.image_flower,&(b.single_flower), ecran, &b.pos_image_flower);
}
void animerBackground(background *b){
		 	
	if (b->flower_num >=0 && b->flower_num <8) {
	b->single_flower.x=b->flower_num * b->single_flower.w;
	b->flower_num++;
	}
	
	if ( b->flower_num == 8) {
	b->single_flower.x=b->flower_num * b->single_flower.w;
	b->flower_num=0;
	}
 
	 
}
