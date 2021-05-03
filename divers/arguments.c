// Programme expliquant l'utilisation d'arguments lors du lancement du programme.

/*
    Pour une question de clareté, on note "argc" et "argv".

    int argc : 
        - le nombre d'argument utilisés lors du lancement du programme,
         il compte aussi le nom du programme.
    
    int argv :
        - stock les arguments tapés par l'utilisateur.
*/
#include <stdio.h>

int main(int argc, char *argv[])
// On peut mettre les noms qu'on veut.
{
    printf("Nombre d'agruments : %d\n", argc);
    printf("Premier argument : %s\n", argv[1]);
    // On utilise %s car ce sont des chaînes de caractères.

    return 0;
}