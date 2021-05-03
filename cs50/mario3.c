// Permet de dessiner des colonnes comme dans mario.
#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int t;
    do
    {
        t = get_int("taille de la colonne :");
    }
    while (t < 1);
    for (int f = 0; f < t; f++)
    // Cette boucle for vas déterminer le nombre de fois que la prochaine boucle vas se réaliser (de haut en bas).
    {
        for (int h = 0; h < t; h++)
        // Cette boucle détermine le nombre de "#" par ligne que le programme vas écrire (de gauche à droite).
        {
            printf("#");
        }
        printf("\n");
        // Cette commande "printf" permet de revenir à la ligne pour faire le dessins de la colonne en 2 dimensions (longueur et largeur).
    }
}
