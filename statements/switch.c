// Programme introduisant la fonction switch.

/*
    La fonction switch permet de vérifier la
    valeurs d'une variable plusieurs fois et
    de définir les actions à faire dans certains cas (?)
    C'est un gain de temps comparé à if mais seulement si on
    a une seule variable à vérifier.
*/

#include <stdio.h>

int main(void)
{
    int variable_a_verifier = 0;

    printf("variable : ");
    scanf("%d", &variable_a_verifier);

    switch (variable_a_verifier)
    // Attention à ne pas mettre de point virgule !!!
    {
    case 1:
            printf("variable = %d", variable_a_verifier);
        break;
    /*
        Dans le cas où variable_a_verifier == 1 :
        - afficher "variable = 1"
        - arrêter switch.
    */

    case 2:
            printf("variable = %d", variable_a_verifier);
        break;

    case 3:
            printf("variable = %d", variable_a_verifier);
        break;

    /*
        Si on ne met pas le break après les instructions,
        les autre cas vont s'executer
    */
    case 4:
    case 5:
    case 6:
            printf("variable est soit egale a 4, soit a 5, soit a 6.\n");
        break;

    // Le cas où tous les autres ne se sont pas réalisés.
    default:
            printf("La variable n'est ni egale a 1, ni a 2, ni a 3, ni a 4, ni a 5, ni a 6.\n");
        break;
    }

    return 0;
}
