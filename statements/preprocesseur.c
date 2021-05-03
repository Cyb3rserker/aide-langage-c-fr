// Programme expliquant les préprocesseurs.

/*
    Les préprocesseurs sont des directives
    qui se lancent avant le programme, comme
    inclure des bibliothèque de fonctions.
    Ils commencent toujours par #.
*/

#include <stdio.h>
/*
    Cette diréctive permet d'inclure la bilbilothèque
    standard.
*/

/*
    On utilise #define pour faire correspondre un mot à un autre.
    C'est une diréctive qui n'a pas d'incluence sur la compilation,
    c'est plus une aide au dévloppement.
    On peut par expemple l'utiliser pour des noms de fonctions très longs.
*/

#define TVA 25
/*
    Dans cette exemple, le mot "TVA" correspond au mot "25".
*/

/*
    On peut aussi par exemple remplacer le nom de 
    la fonction printf par "afficher".
*/
#define afficher printf


//On peut aussi mettre des calculs

#define LONGUEUR 38
#define LARGEUR 15
#define AIRE (LONGUEUR * LARGEUR)
// Equivalent de "AIRE (38 * 15)"

// Son utilisation peut aller plus loin.

#define coucou printf("Coucou !\n")

int main (void)
{
    int prix_hors_taxe = 15;
    int prix_TTC = 0;

    prix_TTC = prix_hors_taxe + (prix_hors_taxe * TVA / 100);
    // "TVA" correspond à "25".

    afficher("prix hors taxe : %d\nPrix TTC : %.d\n", prix_hors_taxe, prix_TTC);
    // "afficher" correspond à "print".

    coucou;
    // Le compilateur comprendra << printf("Coucou !\n") >>.

    printf("%d", AIRE);
    return 0;
}