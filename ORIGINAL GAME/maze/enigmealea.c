#include "header.h"

void main()
{
enigme e;
animer (&e);
	SDL_Quit();
}
/*
    srand(time(0));
    e->choix_question=(rand() % (4)) +1;

    SDL_Color couleurNoire= {0,0,0};
    TTF_Font *police;

    police = TTF_OpenFont("f.otf", 30);

    FILE *F;
    int nb=0;
    F=fopen(nomfichier, "r");
    if(F!=NULL)
    {
        while((fscanf(F,"%s , %s , %s , %s  %d\n",e->question,e->reponse1,e->reponse2,e->reponse3,&(e->rp))!=EOF)&&(nb!=e->choix_question))
        {
            nb++;
        }
    }
    else 
    printf("erreur lors de l'execution du fichier\n");
    fclose(F);

*/
