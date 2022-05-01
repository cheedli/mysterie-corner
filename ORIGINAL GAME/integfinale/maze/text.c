#include "text.h"
void initexte(text *A)
{
    A->position.x=1240;
    A->position.y=15;
// couleur noir
    A->textColor.r=255;
    A->textColor.g=255;
    A->textColor.b=255;

    A->font = TTF_OpenFont( "police.ttf", 20 );
}


void displayText(text t,SDL_Surface *screen,char cc[30])
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, cc, t.textColor );
    SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position);
}

