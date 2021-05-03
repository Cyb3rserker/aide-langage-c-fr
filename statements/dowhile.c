// Programme montrant comment marchent "while" et "do...while".

/*
    Ces boucles permettent de d'executer des actions tant que les
    conditions voulues sont faites.

    La différence entre les deux est que la boucle while prend en charge
    la condition et ensuite fait l'action qui y correspond et la boucle
    do while fait l'action et ensuite la continue si les conditions sont remplies.
*/
#include <stdio.h>

int main (void)
{
    int i = 0, k = 0, l = 0;


    //_____WHILE_____

    /*
        Utilisation de while :
    */
    printf("Valeur de i (entre 0 et 5) : ");
    scanf("%d", i);

    while(i < 0 || i > 5)// La vérification de la condition qui vient en première.
    {
        printf("Saisie incorrecte. Veuillez saisir un nombre entre 0 et 5 : ");
        scanf("%d", &i);// L'action qui vient en boucle seulement après avoir vérifié la condition.
    }

    /*
        Dans cette partie, on montrera que while peut faire des erreurs, en vérifiant
        la condition trop tôt.
    */

    while(j > 5 || j < 0)
    {
        int j = 0;

        printf("Valeur de j (entre 0 et 5) : ");
        scanf("%d", j);
    }
    /*
        Comme on fait référence à une variable dans la condition avant qu'elle
        ne soit déclarée, cela causera une erreur de variable inexistante.
    */


    //_____DO_WHILE_____

    /*
        Utilisation de do while :
    */
    do// L'action.
    {
        printf("Valeur de k (entre 0 et 5) : ");
        scanf("%d", &k);

        printf("Saisie incorrecte. Veuillez saisir un nombre entre 0 et 5 : ");
        scanf("%d", &k);
    }while(k > 5 || k < 0);// La condition qui est vérifiée après l'action.


    /*
        Dans cette partie, même si i est dans la bonne tranche de chiffre,
        on renseignera quand même une saisie incorrecte car la condition est après
        l'action.
    */

    printf("Valeur de l (entre 0 et 5) : ");
    scanf("%d", &l);
    do
    {
        printf("Saisie incorrecte. Veuillez saisir un nombre entre 0 et 5 : ");
        scanf("%d", &l);
    }while(l > 5 || l < 0);
    // Le message d'erreur s'affichera avant d'avoir fait la vérification de la condition.
}