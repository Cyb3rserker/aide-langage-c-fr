// Programme introduisant le fait de "caster" des éléments.
// "caster" signifie mettre un élément sous une autre forme.

#include <stdio.h>
#include <cs50.h>

int main ()
{
    char c = get_char("Donnez un caractère :  ");
    // On prendra pour exemple un caractère que l'on vas changer en entier.
    printf("%i\n", (int) c);
    // On le cast grâce à %i et (int).
}