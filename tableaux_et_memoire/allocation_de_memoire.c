// Programma montrant l'allocation dynamique de mémoire

/*
    Les fonctions permettant l'allocation dynamique de mémoire :

    - sizeof(<donne>)            : retourne la taille en octets d'une donnée

    - malloc(<taille_en_octets>) : permet d'allouer dynamiquement une zone mémoire
    - free(<donnee_allouee>)     : permet de libérer l'espace mémoire qu'on a alloué
    - realloc(<donnee>, <nouvelle_taille>) : permet réallouer un espace mémoire

    - calloc(<donnee>, <taille_en_octets>) : alloue et initialise toute la zone mémoire réservée à 0
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nombre_joueur = 0;
    int *liste_de_joueur = NULL; // Tableau de joueurs dont on ne connait pas encore la taille.

    printf("Combien de joueurs ? ");
    scanf("%d", &nombre_joueur);

    liste_de_joueur = malloc(sizeof(int) * nombre_joueur);
    // "Reserve <nombre_joueur> emplacement pour le tableau liste_de_joueur."
    // Cela permet de ne pas réserver de la place avant inutilement.

    /* Parfois, l'allocation de mémoire peut ne pas marcher et donc 
    le pointeur que l'on a déclaré ne pointe rien. Dans ces cas là, il faut immédiatement 
    arrêter le programme car sinon le programme tentera d'accéder à des zones mémoire
    non autorisées et plantera. */

    if(liste_de_joueur == NULL)
        exit(1); // On quitte le programme en signalant une erreur.

    // Maintenant que la mémoire est allouée, on peut la manipuler.

    for(int i = 0; i < nombre_joueur; i++)
    {
        printf("Joueur %d -> numero du joueur : %d\n", i + 1, i * 3);
        liste_de_joueur[i] = i * 3;
    }
    for(int i = 0; i < nombre_joueur; i++)
    {
        printf("[%d] ", liste_de_joueur[i]);
    }
    printf("\n");

    /* Lorsque la mémoire allouée ne nous sert plus, 
    on doit la libérer pour ne pas saturer la mémoire. */
    free(liste_de_joueur);

    printf("\n-----------------\n");
    
    /* La fonction alloc met des valeurs quelconque dans 
    les cases de la mémoire allouée, mais la fonction calloc 
    permet d'initialiser toutes les places réservées à 0. */

    int nombre_joueur_2 = 0;
    int *liste_de_joueur_2 = NULL;

    printf("Combien de joueurs ? ");
    scanf("%d", &nombre_joueur_2);

    liste_de_joueur_2 = calloc(nombre_joueur_2, sizeof(int) * nombre_joueur_2);
    /* Cela permet de ne pas avoir à initialisé toutes les places nous même à 0 
    et malloc aurait mis n'importe quelle valeur. */

    if(liste_de_joueur_2 == NULL)
        exit(1);

    for(int i = 0; i < nombre_joueur_2; i++)
    {
        printf("[%d] ", liste_de_joueur_2[i]); // Imprimera "0" à chaque fois.
    }

    printf("\n");

    free(liste_de_joueur_2);

    printf("\n-----------------\n");

    /* Pour réallouer de la mémoire sans passer par free ensuite alloc, 
    on peut utiliser la fonction realloc. */

    int nombre_joueur_3 = 4;
    int *liste_de_joueur_3 = NULL;

    liste_de_joueur_3 = malloc(nombre_joueur_3 * sizeof(int));

    if(liste_de_joueur_3 == NULL)
        exit(1);

    printf("Nombre de joueur : %d\n", nombre_joueur_3);
    
    for(int i = 0; i < nombre_joueur_3; i++)
    {
        printf("Joueur %d -> numero du joueur : %d\n", i + 1, i * 3);
        liste_de_joueur_3[i] = i * 3;
    }
    for(int i = 0; i < nombre_joueur_3; i++)
    {
        printf("[%d] ", liste_de_joueur_3[i]);
    }
    printf("\n");

    printf("\n-----------------\n");

    nombre_joueur_3 = 2; 
    realloc(liste_de_joueur_3, nombre_joueur_3 * sizeof(int));

    if(liste_de_joueur_3 == NULL)
        exit(1);

    printf("Nombre de joueur : %d\n", nombre_joueur_3);

    for(int i = 0; i < nombre_joueur_3; i++)
    {
        printf("Joueur %d -> numero du joueur : %d\n", i + 1, i * 3);
        liste_de_joueur_3[i] = i * 3;
    }
    for(int i = 0; i < nombre_joueur_3; i++)
    {
        printf("[%d] ", liste_de_joueur_3[i]);
    }
    printf("\n");

    free(liste_de_joueur_3);

    return 0;
}
