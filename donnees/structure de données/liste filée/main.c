// Programme introduisant les listes filées
// Une liste filé est une structure de données 
// reliant les valeurs choisies, sans utiliser de 
// tableaux. Cela peut être utile pour ne pas avoir à 
// faire de réallocation.
// (ressemble très fortement au pile, fichiers d'aide dans 
// le dossier "pile")

#include <stdio.h>
#include <stdlib.h>

typedef struct element_liste{
    int valeur;
    struct element_liste *element_suivant;
    // on fait une structure avec une valeur et un pointeur
    // qui pointe vers 'element_suivant', qui est du type de 
    // données 'element_liste'.
}element_liste;

int affichage_liste(element_liste *liste_a_afficher);

int main(void){
    element_liste *liste_donnee = malloc(sizeof(element_liste));
    if(liste_donnee == NULL){
        printf("Erreur d'allocation de mémoire.\n");
        return -1;
    }

    //------------------------------------------------------

    element_liste *element1 = malloc(sizeof(element_liste));
    if(element1 == NULL){
        printf("Erreur d'allocation de mémoire.\n");
        return -1;
    }

    element1->valeur = 72;
    
    liste_donnee->element_suivant = element1;
    // L'élément 1 est désormais relié à la liste

    //------------------------------------------------------
   
    element_liste *element2 = malloc(sizeof(element_liste)); 

    if(element2 == NULL){
        printf("Erreur d'allocation de mémoire.\n");
        return -1;
    }


    element2->valeur = 53;
    element1->element_suivant = element2;
    
    //------------------------------------------------------

    element_liste *temporaire = malloc(sizeof(element_liste));

    temporaire = liste_donnee;

    //------------------------------------------------------

    printf("_____Affichage élément 1 (= 72) et élément 2 (= 53) : _____\n");

    while(temporaire->element_suivant != NULL){
       temporaire = temporaire->element_suivant;
       printf("%d\n", temporaire->valeur);
    }
   // (utiliser un schéma pour comprendre le fonctionnement de l'algorithme 
   // d'affichage parce que même moi j'ai bégayé)

    //------------------------------------------------------
    
    printf("_____Ajout élément 3 (= 47) : _____\n");

    // Pour ajouter cette élément, je décide de le mettre au début de 
    // la liste et je vais donc le mettre entre le début de la liste 
    // et l'élément 1 :

    element_liste *element3 = NULL;
    element3 = malloc(sizeof(element_liste));
    
    if(element2 == NULL){
        printf("Erreur d'allocation de mémoire.\n");
        return -1;
    }

    element3->valeur = 47;

    element3->element_suivant = element1;
    liste_donnee->element_suivant = element3;
    
    temporaire = liste_donnee;

    while(temporaire->element_suivant != NULL){
       temporaire = temporaire->element_suivant;
       printf("%d\n", temporaire->valeur);
    }

    free(element1);
    free(element2);
    free(element3);
    free(liste_donnee);

    return 0;
}


int affichage_liste(element_liste *liste_a_afficher){
    if(liste_a_afficher == NULL){
        printf("La liste est vite.\n");
        return -1;
    }
    
    element_liste *temporaire = malloc(sizeof(element_liste));
    temporaire = liste_a_afficher;

    while(temporaire->element_suivant != NULL){
       temporaire = temporaire->element_suivant;
       printf("%d\n", temporaire->valeur);
    }
}
