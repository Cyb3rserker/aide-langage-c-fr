// Programme introduisant le fait de "caster" des éléments.
// "caster" signifie changer la manière dont le programme 
// interprète une donnée.

#include <stdio.h>
#include <cs50.h>

int main ()
{
    char c = 'F';
    // On prendra pour exemple un caractère que l'on vas changer en entier.
    int c2 = (int) c;
    // On change l'interprétation du programme concernant la donnée, ce qui 
    // permet de faire l'initialisation de la variable correctement.
    printf("%i\n", c2);
    // Ce qui équivaut aussi à :
    // printf("%i\n", (int) c);

    // Sortie au terminal :
    // 70
}
