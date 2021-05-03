// Programme montrant l'utiliter de return.
// Si on marque "return 0", on dit au pc que le programme a bien fonctionné et qu'il peut s'arrêter à ce point.
// Si on marque "return 1" ou autre nombre, on dit au pc que le programme a mal fonctionné.
// Pour l'exemple, on fait la recherche du prénom "EMMA".

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string names[4] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

    for(int i = 0; i < 4; i++)
    {
        if (strcmp(names[i], "EMMA") == 0)
        {
            printf("Found\n");
            return 0;
            // Comme on a rempli notre objectif, on marque "return 0" et le programme s'arrêtera là, ou du moins la fonction main.
            // Si on ne l'avait pas mis, le programme aurait continué.
        }
    }
    printf("Not found\n");
    return 1;
    // Comme on n'a pas rempli notre objectif, on marque "return 1" pour dire que ça n'a pas marché.
}