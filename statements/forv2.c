// Permet de faire une boucle, mais ici on peut séléctionner le nombre de tour par le biais d'une question.
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int m = get_int("Combien de fois voulez vous dire que vous être un hackeur?\n");
    for (int i = 0; i < m; i++)
    {
        printf("je suis un H4CK3R\n");
    }
}
