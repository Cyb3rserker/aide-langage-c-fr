#include <stdio.h>
#include <stdlib.h>

// On commence par définir une pile :
// (Stack = pile en anglais)
// (Il est préférable de mettre les structure de données dans
// un autre fichier)
typedef struct element_pile{
    unsigned int value;
    // La valeur de l'élément.
    struct element_pile *element_suivant;
    // un élément de la pile contient aussi une adresse vers
    // l'élément suivant et donc si le pointeur est égal à
    // NULL, cela signifie qu'on a atteint la fin de la pile
    // ou qu'elle est vide.
    // note : la syntaxe utilisée pour définir le pointeur montre
    // que le pointeur 'element_suivant' pointe vers le type de
    // données 'element_pile'.
}element_pile, *Pile;
// Ces noms nous permettent de définir soit des piles, soit
// des éléments. On peut utiliser seuelemnt 'element_pile' comme
// nom et juste ajouter une étoile pour faire un pointeur mais c'est
// mieux de faire plusieurs noms différents pour plus de clareté dans
// le code.

// Explication des fonctions dans stack.c
typedef enum{
    false, //0
    true // 1
}Bool;

Bool is_empty_stack(Pile st);
Pile new_stack(void);
Pile push_stack(Pile st, unsigned int x);
Pile clear_stack(Pile st);
void afficher_pile(Pile st);
Pile suppression_element_pile(Pile st);
Pile clear_stack_v2(Pile st);
int sommet_pile(Pile st);
int hauteur_pile(Pile st);
