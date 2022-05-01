#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "xo.h"


int main(int argc, char *argv[])
{
	SDL_Surface*ecran;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Erreur.\n");
		return 1;
	}
	ecran = SDL_SetVideoMode(321,321, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	Play_Xo(ecran);

	SDL_Quit();
	return 0;
}


