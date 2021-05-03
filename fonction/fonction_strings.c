// Programme qui montre le fonctionnement des chaînes de caractères.

/*
    Les strings sont enfaite des arrays de
    caractères.
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    // _____INITIALISATION ET AFFICHAGE_____


    // Pour créer un string, on peut faire comme ça :
    char phrase[] = "Bonjour tout le monde !";
    // C'est un tableau de caractères.
    /* On ne met rien dans les crochets car le
    compilateur calcul directement la place nécessaire mais
    cela ne marche pas si on ne met pas la suite de caractères
    à stocker (char phrase[]; ne marcherait pas).*/

    /* Pour l'afficher, on utilise %s */
    printf("%s\n", phrase);

    /* Si on veut définir nous même une taille, on remplit
    les crochets avec le nombre de la limite de caractère
    mais en ajoutant 1 car le \0 qui montre la fin de la suite de
    caractères est inclu. */
    char string_avec_espace_limite[8] = "Medoune";
    // C'est donc "Medoune\0" dans la mémoire, donc 8 caractères.

    /* On peut aussi initialiser des strings avec la
    saisie de l'utilisateur (get_string) */
    char prenom_utilisateur[25];
    printf("Comment vous appelez vous ? ");
    scanf("%s", prenom_utilisateur);
    /* On ne met pas le & parce que c'est comme un pointeur. */
    printf("Votre prenom : %s.\n", prenom_utilisateur);


    /*
        On ne peut pas réinitialiser un string comme ça :
        phrase = "Bonjour tout le monde moi c'est Médoune !";
        Pour le faire, on utilise la fonction strcpy dans string.h :
    */


    // Les fonctions qui viennent se trouvent dans string.h.


    // _____STRCPY_____

    /* Elle permet de copier le contenu d'une chaîne de caractère dans une autre. */
    char prenom[25] = "Medoune";
    char stockage[256];

    printf("Ton prénom de base : %s\n", prenom);

    printf("Changer ton prenom ? ");
    scanf("%s", stockage);

    strcpy(prenom, stockage);
    /* On met en premier le tableau de destination et
    ensuite le contenu à copier. On peut ne pas utiliser d'arrays
    de stockage en mettant
    <<strcpy(prenom, "les caractères qu'on veut")>>. */

    printf("Ton nouveau prenom : %s\n", prenom);


    // _____STRLEN_____


    /* Il existe aussi une fonction qui permet de calculer la
    longueur d'une chaîne de caractères : strlen.
    Elle permet de calculer la longueur d'un string, c'est à dire
    le nombre de caractères dans le string (sans compter \0). */

    char mot1_a_comparer[] = "Medoune";
    char mot2_a_comparer[] = "Bateau";
    int test = strcmp(mot1_a_comparer, mot2_a_comparer);

    if(test == 0)
        printf("Les deuxx mots sont les memes.\n");
    if(test < 0)
        printf("%s < %s.\n", mot1_a_comparer, mot2_a_comparer);
    if(test > 0)
        printf("%s > %s.\n", mot1_a_comparer, mot2_a_comparer);
        // Dans le sens "a < b | 1 < 2".


    // _____STRCAT_____

    /* Cette fonction permet de fusionner (concaténer)
    deux chaînes de caratères. */

    char mot1_a_fusionner[] = "Boul";
    char mot2_a_fusionner[] = " et Bill";

    printf("%s\n", strcat(mot1_a_fusionner, mot2_a_fusionner));
    // Cela affichera "Boul et Bill".
    /* L'ordre de positionnement des variables dans la fonction
    a son importance :
    si on avait mis "strcat(mot2_a_fusionner, mot1_a_fusionner)",
    cela aurait afficher " et BillBoul". */


    // _____STRSTR_____

    /* Cette fonction permet de trouver un string dans un autre.
    Cette fonction renvoie un pointeur vers le premier caractère de
    la chaîne si le sous-string se trouve dans le string. Si le
    texte chercher ne se trouve pas dans le texte, alors la fonction
    reverra NULL. */

    char texte[] = "Boul et Bill";
    // Le string dans lequel on cherchera le sous-string
    char mot[] = "Bill";
    // Le sous-string qu'on cherchera dans le texte

    if(strstr(texte, mot) != NULL)
        printf("Le mot ""%s"" est bien dans le texte ""%s"" \n", mot, texte);

    else if(strstr(texte, mot) == NULL)
        printf("Le mot ""%s"" n'est pas dans le texte ""%s"" \n", mot, texte);


    // _____STRCHR_____(doute)

    /* Cette fonction permet de chercher un caractère dans un 
    string et retourne tout ce qui se trouve après le caractère 
    trouvé dans le string */

    char text[] = "Ceci est un texte";
    char caractere = 'i';

    char *pointeur_vers_le_caractere_trouve = strchr(text, caractere);
    // Pointeur vers "text[4]", qui est i dans text.

    printf("%s\n", pointeur_vers_le_caractere_trouve);
    // Cela imprimera "i est un texte".

    //_____SPRINT_____(dans stdio.h)

    /* Cette fonction permet d'écrire dans une chaîne. 
    Ca peut être plus approprié que strcpy. */

    char chaine_de_caractere[256];

    sprintf(chaine_de_caractere, "Medoune", 7);
    /* Je met d'abord la chaîne où je veux écrire, ensuite ce que je veux 
    écrire et enfin la taille de ce que je veux écrire. */

    printf("%s\n", chaine_de_caractere);

    return 0;
}