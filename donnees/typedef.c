// Programme qui pousse plus loin l'utilisation de structure en définissant des données.

/*
    typedef permet de définir une strucure ou une énumération
    comme un type et de donner un nom à celles-ci, ce qui permet
    d'en simplifier l'écriture.
*/

#include <stdio.h>

typedef struct Player
{
    signed char username[256];
    int hp ;
    int mp ;
} Joueur ;
/*
    pseudo code :
    définir comme type de variable toute la structure Player et nomme ce type "Joueur".

    Ca permet de ne pas écrire "struct Player".
*/

int main (void)
{
    Joueur p1 = {"Médoune", 100, 100};
    
    printf("Nom du joueur : %s.\n", p1.username);
    printf("PV : %d\n", p1.hp);
    printf("PM : %d.\n", p1.mp);

    return 0;
}