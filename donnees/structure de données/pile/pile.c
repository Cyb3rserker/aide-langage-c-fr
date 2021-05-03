#include "pile.h"
#include <stdio.h>
#include <stdlib.h>

// Pour définir une nouvelle pile vide :
Pile new_stack(void){
    return NULL;
}

// Pour vérifier que la pile est vide en utiliser le type Bool :
Bool is_empty_stack(Pile st){
    // Comme montré dans l'explication de la structure dans
    // stack.h, si l'élément de la pile pointe vers NULL alors
    // cela signifie qu'elle est vide
    if(st == NULL)
        return true;

    return false;
}

// Cette fonction permet d'ajouter des élémnents à la pile :
// (x est l'élément ajouté)
Pile push_stack(Pile st, unsigned int x){
    Pile element;
    element = malloc(sizeof(*element));
    // Cela permet d'allouer de la mémoire de la taille d'un
    // "element_pile" qui est un type de donnée car l'ordinateur
    // ne connait pas encore la taille d'un "element_pile".

    // La vérification :
    if(element == NULL){
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->element_suivant = st;
    // Prend le pointeur vers le prochain élémént de la pile
    // qui a été mis en argument.

    return element;
}

// Une fonction pour libérer la mémoire allouée proprement
Pile clear_stack(Pile st){
    element_pile *element;
    // On va stocker des infos dedans, il agit comme une sauvegarde

    // On verrifie si la pile est vide
    if(is_empty_stack(st))
        return new_stack();

    element = st->element_suivant;

    free(st);

    return clear_stack(element);
    // La fonction va se répéter avec les autres éléménts de la pile
    // jusqu'à ce qu'elle soit vide et cette vérification se fait grâce
    // au if du début de la fonction.
}

// J'ai réussi à le faire tout seul, sauf pour la condition au début.
void afficher_pile(Pile st){
    if((is_empty_stack(st)) == true){
        printf("Rien à afficher, la pile est vide.\n");
        return;
    }

    Pile element;
    element = st;

    while((is_empty_stack(element)) == false){
        printf("[%d]\n", element->value);
        element = element->element_suivant;
    }
}

// C'est pratiquement la même chose que clear_stack sauf qu'on ne retourne
// pas la fonction à la fin.
Pile suppression_element_pile(Pile st){
    Pile element;

    if(is_empty_stack(st))
        return new_stack();

    element = st->element_suivant;

    free(st);

    return element;
}

// Maintenant que l'on a la fonction suppression_element_pile, on peut faire une
// version plus courte de clear_stack :
Pile clear_stack_v2(Pile st){
    if((is_empty_stack(st)) == true)
            return new_stack();

    while((is_empty_stack(st)) != true)
        st = suppression_element_pile(st);
}

int sommet_pile(Pile st){
    if((is_empty_stack(st)) == true){
        printf("Aucun somment, la pile est vide.\n");
        return -1;
        // On a mis que des unsigned int dans les éléments des piles
    }

    return st->value;
}

int hauteur_pile(Pile st){
    int hauteur = 0;
    Pile element = st;

    while((is_empty_stack(element)) == false){
        hauteur++;
        element = element->element_suivant;
    }

    return hauteur;
}
