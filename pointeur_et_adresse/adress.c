// Programme introduisant la notion d'adresse dans la mémoire de l'appareil.

/*
En effet, les éléments que l'on utilise dans notre programme, comme les variables,
ont un emplacement dédié dans la mémoire de l'ordinateur.
Cet emplacement a une adresse définie en hexadécimale (ex :0x7ffef7a099b8).
*/

#include <stdio.h>

int main ()
{
    int n = 50;
    printf("%p\n", &n);
    /*
    On met %p pour afficher une adresse en hexadécimal.
    Mettre "&" devant le nom de la variable permet de faire référence à son "adresse" en hexadécimal.
    ex : 
        maVariable  : valeur de la variable
        &maVariable : adresse de la variable.$
    Pour imprimer son adresse, on met "%p" dans printf.
    */

    return 0;
}