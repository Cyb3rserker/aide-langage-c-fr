// Programme introduisant les constantes.

/*
    Les constantes permettent de définir une variable qui sera active 
    dans la partie du progrramme où on la met
    et ne peut être modifier, on ne peut donc pas demander la 
    valeur d'une constante à l'utilisateur.
*/

#include <stdio.h>

const int N = 2;
/*
    Comme je l'ai mise en haut, cette constante sera active dans tout le code.
    Lorsqu'on définit une constante, il faut la mettre en majuscule.
    Dans mon cas, cette constante est un entier.
*/

/*
    Les constantes prédéfinies du language c sont :
        __FILE__ (nom du fichier)
        __LINE__ (ligne du fichier)
        __DATE__ (date de compilation)
        __TIME__ (heure de compilation)
    Elles peuvent servir pour du débogage par exemple.
*/

int main (void)
{
    printf("Ceci est la valeur de N : %i\n", N);
    /*
        Lors de l'execution de cette ligne,
        la constante N restera toujours à la même valeur.
    */
   
    return 0;
}