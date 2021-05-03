// Permet de définir une variable.
// Calcule le nombre de jour de l'utilisateur.
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int âge = get_int("Quel est ton âge\n");
    // Question à l'utilisateur qui lui permet de donner le chiffres qu'il veut mettre dans la variable.
    // Pour nommer la variable, il faut ajouter "int" devant.
    // La définition de la variable se fait après le signe "=".
    printf("Tu est âgé de %i jours.\n", âge * 365);
    // Le calcul se fait avec le chiffre que l'utilisateur a choisi lorsque la question lui a été posée dans le terminal.
}