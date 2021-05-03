// Programme présentant la programmation modulaire.

/*
    La programmation modulaire permet de mettre ses
    fonctions dans une bibliothèque que l'on utilisera
    dans le programme.
    
    Les bibliothèques se composent d'un fichier .c
    où seront les fonctions et d'un fichier .h où
    seront les prototypes.
    cf prog_modulaire2.c et prog_modulaire.h.

    Ces bibliothèques peuvent avoir des noms différents,
    mais le nom des fonctions et des prototypes doivent
    rester les mêmes.
    
    Si les bibliothèques sont dans
    l'environnement de travail, on les inclu
    avec "#include <_____.h>".
    Si elles ne le sont pas, ont les inclu
    avec "  #include "_____.h"  " et on
    les met dans le même fichier que le
    fichier .h.

    Pour compiler le programme, il faut compiler
    tout les fichiers c en écrivant "gcc *.c -o le_nom_du_programme".
    Cette synthaxe permet de compiler tout les fichiers avec l'extension .c 
    dans le dossier où intéragit le terminal.

    Pour l'exemple, on fera un programme
    qui écrit "Bonjour" tout en utilisant une bibliothèque
    que l'on va créer.
*/

#include <stdio.h>
/*
    On inclu une bibliothèque qui fait parti de
    l'environnement de travail, on utilise des "<>".
*/
#include "prog_modulaire.h"
/*
    On inclu la bibliothèque que l'on a créer
    et dans laquelle se trouve la fonction
    Bonjour.
    On l'inclu avec des doubles guillemets
    car elle n'est pas dans l'environnement de travaille.
*/

int main (void)
{
    bonjour(); // La fonction que l'on a créé.
    return 0;
}