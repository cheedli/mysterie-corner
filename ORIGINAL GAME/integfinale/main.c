#include"menu.h"
#include "enigme.h"
#include "maze.h"
#include "minimap.h"
#include "perso.h"
#include "background.h"
#include "ennemi.h"
int main(int argc, char** argv)
{
    enigme2  maze;
    enigme enigmetxt;
    Ennemi monstre;
    minimap map;
    perso personnage ;
    
    InitEnigme(&enigmetxt,"enigme1.txt");
    InitEnigme2(&maze, "enigme.txt");
    initEnnemi(&monstre);
    init_map (&map);
    initialiser_perso (&personnage);













    menu();
    
    persooo();
     //back();
    TTF_Quit();
    SDL_Quit();
    return 0 ;
}

