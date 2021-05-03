// Programme introduisant les piles

// La pile est une structure de données.

// Vocabulaire :
//  - longueur / hauteur : le nombre d'élément dans
//  la pile
//
//  - le sommet : la dernière valeur enregistrer
//  dans la pile
//
//  - empiler : ajouter une donnée en haut de la pile

#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

int main(void)
{
    Pile sta = new_stack();
    // pointeur vers une pile qui va, plus tard, pointer vers
    // le sommet de la pile en question.

    printf("\n-------------------------\n");

    afficher_pile(sta);

    printf("Sommet actuel : %d\n", sommet_pile(sta));
    printf("Hauteur de la pile : %d\n", hauteur_pile(sta));
    sta = push_stack(sta, 14);
    sta = push_stack(sta, 15);
    sta = push_stack(sta, 16);

    afficher_pile(sta);
    printf("Hauteur de la pile : %d\n", hauteur_pile(sta));
    printf("Sommet actuel : %d\n", sommet_pile(sta));

    printf("\n-------------------------\n");

    sta = suppression_element_pile(sta);
    afficher_pile(sta);
    printf("Hauteur de la pile : %d\n", hauteur_pile(sta));
    printf("Sommet actuel : %d\n", sommet_pile(sta));

    printf("\n-------------------------\n");

    sta = suppression_element_pile(sta);
    afficher_pile(sta);
    printf("Hauteur de la pile : %d\n", hauteur_pile(sta));
    printf("Sommet actuel : %d\n", sommet_pile(sta));

    printf("\n-------------------------\n");

    sta = suppression_element_pile(sta);
    afficher_pile(sta);
    printf("Hauteur de la pile : %d\n", hauteur_pile(sta));
    printf("Sommet actuel : %d\n", sommet_pile(sta));

    sta = clear_stack_v2(sta);
    printf("Hauteur de la pile : %d\n", hauteur_pile(sta));
    printf("Sommet actuel : %d\n", sommet_pile(sta));

    return 0;
}
