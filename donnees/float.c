// Ce programme introduit la commande "float", permettant de manipuler des chiffres à virgule.
// Pour l'exemple, voici un programme qui permet de calculer son IMC.
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float taille = get_float("Quelle est votre taille ?\n");
    float poids = get_float("Quelle est votre poids ?\n");
    printf("Votre IMC est de %.2f.\n", poids/(taille*taille));
    // "%f" est un emplacement dédier au chiffre à virgule.
    // Le ".2" entre % et f permet de n'avoir que 2 chiffre après la vigule. Cela peut être modifier.
    // On peut mettre des calcules dans les emplacelments dédié.
}
