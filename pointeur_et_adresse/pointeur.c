// Programme introduisant les pointeur (cf adress).

/*
    Les pointeurs sont des variables stock l'adresse
    d'autres variables.
    Ils permettent de se référer à une variable 
    présente dans la mémoire pour, par exemple, 
    voir sa valeur ou la changer.
    Ils servent principalement à modifier des données
    dans une fonction.
    
    __type de données__*monPointeur = NULL ou
    __type de données__*monPointeur = &maVariable ou
    __type de données__*monPointeur = maVariable (== qui se refère à son contenu)
    (déclaration et initialisation d'un pointeur)
    
    monPointeur  : adresse de la variable pointée
    *monPointeur : valeur de la variable pointée
    &monPointeur : adresse du pointeur en lui même.
    
*/

#include <stdio.h>

int main ()
{
    int n = 50;
    // On créé une variable n et son contenu est 50.

    int *p = &n;
    /* 
        Pour définir un pointeur, on utilise cette synthaxe :
        (type de donnée sur lequel le pointeur agira) *(nom du pointeur).
        Dans ce cas, on créé un pointeur d'entier qui stock
        l'adresse (= emplacement) de la variable n.
    */
    
    printf("%i\n", *p);
    // valeur de n (=printf("%i\n", n);).
    
    printf("%i\n", p);
    // l'adresse de n.
    
    printf("%p\n", &p);
    // adresse de p.

    return 0;
}