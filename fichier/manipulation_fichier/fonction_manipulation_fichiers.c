// Programme introduisant la gestion des fichiers.

/* /!\ATTENTION !!! ne pas compiler le programme en entier et prendre le résultat 
comme exemple car les lignes de codes servent juste à montrer la synthaxe et l'utilisation
des fonctions. Pour voir leurs comportements, il faut les utiliser séparément.*/

/*
    - fopen(<fichier>, <mode_ouverture>) : ouvre un fichier
    - Les différents modes d'ouvertures :
        - r  : lecture seul, le fichier doit exister
        - w  : écriture seule et supprime le contenu du fichier, si le fichier 
               n'existe pas alors programme le crééra
        - a  : ajout en fin de fichier et conserve le contenu, le fichier peut être créer aussi
        - r+ : lecture / écriture, le fichier doit exister
        - w+ : lecture / écriture et supprime le contenu du fichier
        - a+ : ajout lecture / écriture en fin de fichier qui peut être créer et s'il est créé, 
               le contenu est conservé

    /!\ ATTENTION !!! Si le mode d'ouverture contient la lettre "a", même si on utilise "fseek" 
    avec un retour au début, le retour se fera à la fin du fichier au moment de son ouverture pour 
    conserver son contenu et donc toutes les modifications seront faîtes à cet endroit.

        - fclose(<pointeur_du_fichier>) : permet de fermer un fichier ouvert
        (Tous fichier ouvert doit être fermé ensuite comme avec malloc car cela 
        cause des problèmes comme des fuites de mémoire)

        - feof(<pointeur_du_fichier>) : permet de vérifier si la fin d'un fichier est atteinte

    [LECTURE]
        - fgetc(<pointeur_du_fichier>) : permet de lire un caractère.
        - fgets(<chaine>, <taille_chaine>, <pointeur_du_fichier>): permet de lire une ligne.
        - fscanf(<pointeur_du_fichier>, <format>, ...) : permet de lire du texte formaté et de le stocker.

    [ECRITURE]
        - fputc(<caractère>, <pointeur_du_fichier>) : permet d'écrire un caractère dans un fichier
        - fputs(<chaîne>, <pointeur_du_fichier>) : permet d'écrire une ligne de texte dans un fichier
        - fprintf(<pointeur_du_fichier>, <format>, ...) : permet d'écrire du texte formaté

    [POSITIONNEMENT]
        - ftell(<pointeur_du_fichier>) : retourne la position du curseur dans un fichier
        - fseek(<fichier>, <déplacement>, <origine>) : déplace le curseur
            -> <origine> : SEEK_SET = début du fichier
                           SEEK_CUR = position actuelle dans le fichier
                           SEEK_END = fin du fichier
        - rewind(<fichier>) : réinitialise la position du curseur

    [DIVERS]
        - rename(<ancien_nom_du_fichier>, <nouveau_nom_du_fichier>) : renome un fichier
            et il faut que celui-ci soit fermé que ce soit dans le code ou autre
            (ex : traitement de texte)

        - remove : 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //_____LECTURE_____
    
    /* Pour déclarer un fichier, on déclare en fait un pointeur 
    vers le fichier en utilisant cette synthaxe : */

    FILE *pointeur_vers_le_fichier = fopen("fichier_texte.txt", "r");
    // On ne fait que lire le fichier (r).
    // FILE est un type de donnée spéciale créée par le language C.

    if(pointeur_vers_le_fichier == NULL)
        exit(1);
    // On quitte le programme quand le fichier n'est pas trouvé.

    int lettre = 0;

    lettre = fgetc(pointeur_vers_le_fichier);
    printf("%c\n", lettre);
    /* Cette fonction va donc lire le premier caractère du de la première ligne du fichier 
    Elle prend le caractère qui suit au fur et à mesure qu'on l'appel 
    (même avec une variable différente), jusqu'à ce qu'elle retourne la constante "EOF" 
    (End Of File) qui signal une fin de fichier ou une erreur de lecture. On peut 
    imprimer tout les caractères en faisant une boucle while avec EOF en 
    condition. */

    while ((lettre = fgetc(pointeur_vers_le_fichier)) != EOF)
    {
        /* On a pas besoin de taper <<lettre = fgetc(pointeur_vers_le_fichier)>>
        avant la ligne printf. */
        printf("%c", lettre);
    }
    // Cela va afficher tout les derniers caractères de la deuxième ligne du fichier.
    
    unsigned char texte[256];

    fgets(texte, 255, pointeur_vers_le_fichier);
    /* Cela signifie que l'on a mis les 255 premiers caractères 
    de la première ligne du fichier dans le tableau de caractère 
    "texte". Tant qu'on ne met pas l'intégralité des caractères de
    la ligne du fichier dans le texte, on peut copier 
    le reste dans un autre tableau. */
    printf("%s", texte);
    // (revient à la ligne automatiquement après avoir afficher la chaîne)

    /* Pour afficher les autres lignes 
    avec le même tableau, on refait un fgets : */

    fgets(texte, 255, pointeur_vers_le_fichier);
    printf("%s", texte);

    // On peut là aussi faire une boucle while :
    
    while(fgets(texte, 255, pointeur_vers_le_fichier) != NULL)
        printf("%s", texte);
    // Cela va afficher toutes les lignes du fichier.


    int age = 0, poids = 0;
    signed char texte_a_stocker[256];

    fscanf(pointeur_vers_le_fichier, "%s %d %d", texte_a_stocker, &age, &poids);
    // On met des espaces entre les formats.
    printf("Prenom : %s\nAge : %d ans\nPoids : %d kg\n", texte_a_stocker, age, poids);
    // Si la ligne était la seule dans le programme, cela aurait afficher "Medoune 15 75".
    
    fclose(pointeur_vers_le_fichier);

    //_____ECRITURE_____

    FILE *pointeur_vers_le_fichier = fopen("fichier_texte.txt", "w");

    if(pointeur_vers_le_fichier == NULL)
        exit(1);

    fputc('M', pointeur_vers_le_fichier);// Cela va ajouter "J" dans "fichier_texte.txt"
    fputc('e', pointeur_vers_le_fichier);// Les caractères ajouter se suivent sur la même ligne

    char mot[] = "Bonjour";
    fputs(mot, pointeur_vers_le_fichier);
    /* On peut aussi mettre directement le texte qu'on veut entre guillemets :
        ex : <<fputs("Bonjour", pointeur_vers_le_fichier)>> */
    // Si le fichier "fichier_texte.txt" n'existe pas, alors il sera créé.

    int poids = 75, taille = 180;
    char prenom[] = "Medoune";
    fprintf(pointeur_vers_le_fichier, "%d kg %s %d cm", poids, prenom, taille);
    // Là aussi un fichier sera créé si il n'existe pas.

    //_____POSITIONNEMENT_____

    printf("Position du curseur : %d\n", ftell(pointeur_vers_le_fichier));
    
    fseek(pointeur_vers_le_fichier, 5, SEEK_SET);
    // "Met le curseur 5 position plus loin à partir de l'origine dans le fichier."

    printf("Position du curseur : %d\n", ftell(pointeur_vers_le_fichier));
    
    rewind(pointeur_vers_le_fichier);

    fclose(pointeur_vers_le_fichier);

    //_____DIVERS_____
    
    // Pour les prochaines commande, le fichier doit être fermé

    rename("fichier_texte.txt", "nouveau_fichier_texte.txt");
    remove(pointeur_vers_le_fichier);
    // Cela supprimera directement le fichier sans passer par la corbeille.



    return 0;
}