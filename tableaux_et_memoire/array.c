// Programme introduisant les tableaux de caractères.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int array[4];
    // Ceci est un tableau d'entiers. On met le nombre de "case"
    // dans les crochets. 
    // Comme là on va y mettre des entiers, on met "int" devant le nom de l'array.

    array[0] = 72;
    // Quand une variable a des crochets, elle fait donc partie d'une array.
    // C'est la "positions" de CETTE variable (=combientème) dans l'array (et on commence toujours par compter avec 0).
    // Ce sera entre les crochets.
    // Faire attention à donner le même nom au variables qu'à l'array.
    array[1] = 73;
    array[2] = 33;

    // Si on connait déjà la valeur de chaque variables de l'array, on peut utiliser une synthaxe différente.

    int arrayx[3] = {42, 6, 63};
    // On met la valeur de chaque variable de l'array dans des accolades et elles sont séparées par des virgules.
    // Ne pas oublier le ; à la fin.
}
