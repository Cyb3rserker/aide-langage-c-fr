// Programme permettant de covertir des degrés celsius en fahrenheit ou inversement.
// Dans ce programme, je verrai aussi comment utiliser "if" avec des "char".

#include <stdio.h>
#include <cs50.h>

int main(void)
{

    float d = get_float("Quelle est la valeur que vous voulez convertir ?  ");
    // J'utilise "float" pour pouvoir mettre un nombre à virgule.

    char h = get_char("Tapez c pour celsius ==> fahrenheit ou f pour fahrenheit ==> celius.  ");
    // Selon la réponse, cela fera une convertion différente.

    if (h == 'c')
    // Pour mettre un caractère dans "... == ...", il faut mettre le caractère dans des petits tirets : '...'.
    {
        printf("Cela équivaut à %.1f°F.\n", d*9/5 + 32);
        // Le "%.1f" permet de mettre seulement 1 chiffre après la virgule.
    }
    else if (h == 'f')
    {
        printf("Cela équivaut à %.1f°C.\n", (d - 32) * 5/9);
    }
}