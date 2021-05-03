// Programme introduisant la fonction char *.

/*
Depuis le début, string était un équivalent à char *. Oui.
char * est dans la bibliothèque standars et cela lui permet d'être
utiliser dans tous les programmes en c.
char * pointe le premier caractère de l'ensemble de char,
ensuite le pc va utiliser tous les autres char jusqu'arriver à \0.
Pour l'utiliser dans printf, on utilise aussi %s.
*/

#include <stdio.h>

int main ()
{
    char *s = "EMMA";
    // Cela correspond à "string s = "EMMA".

    printf("%s\n", s);
}