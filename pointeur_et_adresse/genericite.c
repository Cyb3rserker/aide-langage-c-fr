// Programme introduisant la fonction de générécité.

/*
    - Pointeur générique : un pointeur qui peut pointer
    vers n'importe quel type de variable. Ces pointeurs 
    utilisent une synthaxe différente des pointeurs normaux.

    - Pointeur de fonction : pointeur qui stock l'adresse d'une fonction 
    ce qui permet de l'appeler.
*/

#include <stdio.h>

    //_____POINTEUR_DE_FONCTION_____

    /* Synthaxe pour déclarer un pointeur de fonction :

    int (*pointeur_fonction) (int, int);
    
    pointeur_fonction = &addition;
    (pour cette ligne en soit c'est juste utliser un autre nom pour la même fonction :
    << pointeur_fonction(14, 323) >> équivaudra à << addition(14, 323) >> )

    On met le type de retour, ensuite le nom du pointeur entre parenthèses
    pour que ce ne soit pas considéré comme une multiplication et enfin les types 
    de paramètres de la fonction. Ce pointeur de fonction peut appeler une fonction avec 
    la même valeur de retour et aussi les mêmes paramètres. */

int addition(int nb1, int nb2)
{
    return nb1 + nb2;
}

int soustraction(int nb1, int nb2)
{
    return nb1 - nb2;
}

int calculer(int nombre1, int nombre2, int (*pointeur_fonction) (int, int))
{
    pointeur_fonction(nombre1, nombre2);
}
// Ce genre de fonction est appelé "fonction de call-back" parce qu'on fait appel à une autre fonction.


int main(void)
{
    //_____POINTEUR_GENERIQUE_____
    
    void *pointeur_generique = NULL; // La déclaration.
    int nombre = 5;
    double autre_nombre = 3.14;

    pointeur_generique = &autre_nombre;
    // On peut pointer un double
    pointeur_generique = &nombre;
    // On peut aussi pointer cet entier

    /*printf("%d\n", *pointeur_generique);*/
    /* Cette synthaxe est incorrecte mais on peut imprimer une adresse 
    de la manière qui suit : */

    printf("%p\n", pointeur_generique);

    //_____POINTEUR_DE_FONCTION_____

    int a = 14, b = 123;

    int resultat = calculer(a, b, &addition);
    /* On fait appel à la fonction addition grâce au pointeur du fonction. */



    return 0;
}

