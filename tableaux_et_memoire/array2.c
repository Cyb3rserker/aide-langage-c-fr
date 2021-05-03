// Programme améliorant l'utilisation de array.
// Pour l'exemple, ce sera le calcul d'une moyenne.

#include <stdio.h>
#include <cs50.h>

float  average (int longueur, int array[]);
// Ceci est le prototype d'une fonction permettant de calculer une moyenne avec des arrays.

int main ()
{
    int n = get_int("Nombre de valeur à calculer :  ");
    // On demande combien de valeurs veut l'utilisateur pour calculer sa moyenne.

    int valeurs[n];
    // On définit l'array avec le nombre de valeurs que l'utilisateur a demandés.

    // Pour ne pas avoir à demander à chaque fois la valeur de la variable, on créé une boucle for qui va le faire.
    for (int i = 0; i < n; i++)

    {
        valeurs[i] = get_int("Valeur %i : ", i + 1);
        // En mettant la variable i dans les crochets de la variable, on lui met directement sa position (=combientième).
        // Pour que l'utlisateur n'ai pas "Valeur 0" lors de la demande de la valeurs de la variable, on fait "i +1".
    }

    printf("Moyenne : %.1f\n", average(n, valeurs));
    // Explication de  de average plus bas.
}

// On créé unr fonction qui pourra calculer la moyenne des "valeurs".

float  average (int longueur, int array[])
// Dans ce programme, les variables "longueur" et "array" seront remplacées par "n" et "valeurs".
// "array" permet d'utiliser les valeurs dans "valeurs" dans le calcul de la moyenne.
// "longueur" et le nombre de valeurs qui seront calculer dans la moyenne.
{
    int somme = 0;
    // "somme" représente la somme de toutes les valeurs dans "valeurs".
    for (int i = 0; i < longueur; i++)
    {
        somme += array[i];
        // "i" représente le prositionnement de la valeur dans l'array, qui est "valeur" dans ce programme (ex : "valeur[0]").
        // La synthaxe  équivaut à "somme = somme + array[i]".
    }
    return (float) somme / (float) longueur;
    // On met float pour que les int renvoient des chiffres à virgule parce que int et int renvoient un entier.
    // Mais si on utilise int pour l'un des deux, le float primera sur le int.
}