// Programme introduisant l'outil valgrind.
/*
    Cette outil permet de voir s'il y a des problèmes de mémoire dans
    notre programme, comme des fuites de mémoire ou de la mémoire qui ne peut
    pas être utiliser car elle n'a pas été alouer.
    Il s'utilise en tapant "valgrind ./programme".
    Pour l'exemple, on fera une fuite de mémoire et de la
    mémoire alouée insuffisante.
*/
#include <stdlib.h>

void f(void)
{
    int *x = malloc(10 * sizeof(int));
    /*
        Ici, je ne vais pas libérer cette mémoire et
        valgrind va me le faire savoir en me disant :
        "40 bytes in 1 blocks are definitely lost in loss record 1 of 1 [...]
        definitely lost: 40 bytes in 1 blocks" ce qui
        signifie que je n'ai pas libérer cette mémoire
        pour le reste du programme (cf free.c).
    */
    x[10] = 0;
    /*
        Ici, je veux créer une variable qui ne sera pas dans
        l'espace qu'elle devrait être et valgrind va me dire :
        "Invalid write of size 4 at 0x4005DA: f (memory.c:**numéro de la ligne**)"
        ce qui signifie que la variable que j'ai saisie est invalide car elle
        n'est pas dans l'espace qui devrait lui être alouer.
    */
}

int main ()
{
    f();
    return 0;
}