// Programme qui pousse un peu plus loin le fonctionnement des arrays et qui montre le fonctionnement de string.
// String est en fait un assemblage de plusieurs char, et le tout se termine par \0.
// String est donc une array de char.

#include <stdio.h>
#include <cs50.h>

int main ()
{
    string names[4];
    names[0] = "EMMA";
    names[1] = "RODRIGO";
    names[2] = "BRIAN";
    names[3] = "DAVID";

    printf("%s\n", names[0]);
    printf("%c%c%c%c%i\n", names[0][0], names[0][1], names[0][2], names[0][3], names[0][400]);
    // Si met %i à la place de %c pour le 5ème caractère d'emma, on verra le 0 apparaître.
    // "names[0]" dis à l'ordi d'aller dans l'array "names".
    // "names[0][0]" dis à l'ordi d'aller chercher le premier élément dans names[0], qui et lui même considéré comme une array.
    // Les deuxièmes crochets représentent les différents caractères dans la variables.
}