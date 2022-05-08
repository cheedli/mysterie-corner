#include "sauvegarde.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h>

int load_data(FILE* fichier,SDL_Rect* pos_perso,SDL_Rect* camera,int* score,int* vie)
{
	int carac,caractereLu=1 ;
	int ligne =1;
	fichier = fopen("savefile","r");
	char data[6] = {0};
	int temp=0;
	if ( fichier != NULL )
	{
		carac = fgetc(fichier);
		if ( carac == EOF )
		{
			return 1; //fichier vider donc nouveau jeu et pas continuer
		}
		else
		{
			while ( caractereLu!=EOF )
			{	
				switch ( ligne )
				{
					case 1:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						(*pos_perso).x = temp;
					break;

					case 2:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						(*pos_perso).y = temp;
					break;

					case 3:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						(*camera).x = temp;
					break;

					case 4:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						(*camera).y = temp;
					break;

					case 5:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						*score = temp;
					break;

					case 6:
						fscanf(fichier,"%s",data);
						temp = atoi(data);
						*vie = temp;
					break;
				}

				caractereLu = fgetc(fichier);
				if ( caractereLu == '\n')
					ligne++;

			}
				fclose(fichier);

		}
	}
	else
	{
		return 0; // retourner la valeur 0 car le fichier n'existe pas pour charger le jeu
	}

}


int save_data(FILE* fichier,SDL_Rect* pos_perso,SDL_Rect* camera,int* score,int* vie)
{
	
	fichier = fopen("savefile","w");

	char data[6] = {0};
	int temp=0;
	char retour_a_ligne[2] = "\n";
	int i=0;
	
	for ( i = 0 ; i<6 ; i++)
            {
                switch (i)
                {

                case 0:
                    temp = (*pos_perso).x;
                    sprintf(data,"%d",temp);
                    strcat(data,retour_a_ligne);
                    fputs(data, fichier);
                    break;

                case 1:
                    temp = (*pos_perso).y;
                    sprintf(data,"%d",temp);
                    strcat(data,retour_a_ligne);
                    fputs(data, fichier);
                    break;

                case 2:
                    temp = (*camera).x;
                    sprintf(data,"%d",temp);
                    strcat(data,retour_a_ligne);
                    fputs(data, fichier);
                    break;

                case 3:
                    temp = (*camera).y;
                    sprintf(data,"%d",temp);
                    strcat(data,retour_a_ligne);
                    fputs(data, fichier);
                    break;

                case 4:
                    temp = *score;
                    sprintf(data,"%d",temp);
                    strcat(data,retour_a_ligne);
                    fputs(data, fichier);
                    break;

                case 5:
                    temp = *vie;
                    sprintf(data,"%d",temp);
                    strcat(data,retour_a_ligne);
                    fputs(data, fichier);
                    break;
                }
            }
	fclose(fichier);


}








