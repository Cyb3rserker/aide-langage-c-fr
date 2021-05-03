// Programme qui introduit les fonctions.
#include <stdio.h>

void bonjour(void);
// Le prototyp (=trace) de la fonction se met en début en C pour que celle-ci soit active.
// Comme là c'est une déclaration donc il faut mettre ";".
// On remplace void par un type de donnée si on veut que la fonction renvoie quelque chose.

int main(void)
{
    bonjour();
    // La fonction.
}


// l'integralité de la fonction.

void bonjour(void)
/*
    Cette fonction ne prend pas d'input
    Il faut bien ne pas mettre le point virgule dans
    la définition de la fonction.
*/
{
    printf("Bonjour.\n");
}
