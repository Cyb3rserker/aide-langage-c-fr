// Programme expliquant les variables statiques.

// Une variable statique est comme une constante : 
// elle n'est pas détruite après que la fonction 
// dans laquelle on l'a utilisée est terminée mais 
// la variables statique a une valeur qui peut être 
// changée, contrairement à une constante qui garde 
// la même valeur pendant tout le déroulement du programme.

#include <stdio.h>

int conteur(void){
    static int conteur = 0;
    conteur++;
    return conteur;
}

int main(void){
    printf("Conteur : %d\n", conteur());
    printf("Conteur : %d\n", conteur());
    return 0;
}
// En testant le programme, on a pu voir que la variable "conteur" 
// était active durant toute la durée du programme et a vu sa valeur 
// changer tout au long de celui-ci.
