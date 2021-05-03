// Programme poussant plus loin l'utilisation d'un pointeur.

/*
    On prendra un exemple de base de l'utilisation des pointeurs :
    l'inversion de valeurs avec deux variables.
*/

#include <stdio.h>

void inverser_nombre(int *a, int *b)
/*
    On utilise des pointeurs comme entrée car on vas
    intéragir avec les valeurs des variables pointées.
    Ca sert aussi à conserver les changement effectuer
    sur les valeurs des variables.
*/
{
    /*
        La manipulation pour inverser les valeurs.
        Ici on se sert des valeurs en elles-même.
        (cf pointeur.c).
    */
    int temporaire = 0;
    temporaire = *b;
    *b = *a;
    *a = temporaire;
    // Dans cette partie, on modifie vraiment les valeurs des variables.
}
/*
    Les changements vont ensuite rester et ne vont pas être effacer,
    ce qui ne serait pas le cas si on n'avait pas utiliser de pointeur.
*/

int main (void)
{
    int nombreA = 15;
    int nombreB = 28;

    printf("AVANT : A = %d et B = %d\n", nombreA, nombreB);

    inverser_nombre(&nombreA, &nombreB);
    // Comme on modifie les valeur, on met les adresses.

    printf("APRES : A = %d et B = %d\n", nombreA, nombreB);

    return 0;
}