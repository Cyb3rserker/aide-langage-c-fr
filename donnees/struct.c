// Programme introduisant les structures et les types de données (avec typedef.c).

/*
    Les stuctures permettent de rassembler plusieurs
    types de données en une seule structure.
    Il est possible d'avoir des strucures dans des structures.
*/

#include <stdio.h>

struct Player
// On donne le nom de la structure.
{
    signed char username[256];
    int hp ;
    int mp ;
    /*
        Cette structure est composer de plusieurs
        données. Losqu'on les déclare, on ne met pas "= ___".
        Ces données sont appelées des champs et dans ce cas, 
        il y a trois champs.
    */
};

int main (void)
{
    // Les différentes données dans les structures s'initialisent comme ça :

    /*
        struct **nom structure** **nom pour ensemble de données** = {**Différentes informations séparer avec virgules**};
        L'initialisation peut se faire comme avec des arrays
    */

    struct Player p1 = {"Médoune", 100, 100};
    // On a initialisé le nom, les hp et les mp de p1.

    /*
        Pour manipuler les différentes données de la structure,
        on utilise cette synthaxe :
        **nom ensemble de données** . **données que l'on veut modifier**
    */

    printf("Nom du joueur : %s.\n", p1.username);
    printf("PV : %d\n", p1.hp);
    printf("PM : %d.\n", p1.mp);

    // Quand on veur faire appelle à une élément d'une structures
    // qui a un pointeur comme nom (?), on utilise des flèches :

    typedef struct exemple{
        int age;
    }*age_utilisateur;

    age_utilisateur test->age = 14;
    // équivalent à "(*test).age = 14"

    return 0;
}
