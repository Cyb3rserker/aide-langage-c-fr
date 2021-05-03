// Programme montrant le fonctionnement de la fonction fgets

// Cette fonction permet de faire de la lecture de données,
// comme scanf, mais avec des sécurité directement intégrées 
// dans la fonction. Elle ignore aussi automatiquement les 
// espaces mais attention ! elle prend aussi le caractère <entrer> pour le retour à la ligne.
// Sa définition : 
// char *fgets(chaîne_de_caractères_destinataire,nombre_max_caractères_à_lire, canal_de_données);
// La fonction retourne un pointeur de chaîne de caractère si 
// la lecture est réussi et retourne NULL si la lecture a 
// échoué.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_BUFFER 20
// Je met 20 car c'est une taille suffisante pour stocker pour 
// stocker un nom et un prénom.

void supp_retour_ligne(char str[]);
char *lecture_string_input(char *str, int taille);
// Cela se voit un peu plus tard

int main(void)
{
    char nom_prenom_utilisateur[TAILLE_BUFFER + 1];
    // (le +1 pour le caractères de fin de chaîne \0)
    printf("Nom prénom : ");

    fgets(nom_prenom_utilisateur, TAILLE_BUFFER, stdin);
    // On indique stdin en canal de données car on veut lire 
    // des données saisies par l'utilisateur mais on peut y 
    // mettre ce qu'on veut comme des fichiers 
    // (voir aide/fichier/manipulation_fichier/fonction_manipulation_fichier.c).
    
    printf("Nom et prénom : %s\n", nom_prenom_utilisateur);

    // Le problème avec fgets, c'est que cette fonction ajoute 
    // automatiquement le retour à la ligne (le \n). Cela peut être 
    // assez dérangeant et pour y remédier, on peut utiliser 
    // cette technique :

    char nom_prenom_utilisateur_2[TAILLE_BUFFER + 1];

    printf("Nom Prénom 2 : ");

    fgets(nom_prenom_utilisateur_2, TAILLE_BUFFER, stdin);
    
    nom_prenom_utilisateur_2[strcspn(nom_prenom_utilisateur_2, "\n")] = '\0';
    // Cette ligne va permettre de définir le caractère '\n' 
    // de retour à la ligne comme '\0', le caractère de fin de 
    // chaîne et donc d'arrêt de lecture de la chaîne de 
    // caractères. Je vais en faire une fonction pour que le 
    // code soit plus lisible.
    
    // Le problème, comme avec toutes les lectures, c'est que 
    // le buffer du canal d'enter stdin n'est pas vierge. Pour
    // y remédier, on peut utiliser ces quelques lignes de 
    // code :

    fseek(stdin, 0, SEEK_END);

    // Plus d'explication dans scanf.c situer dans le même
    // répertoire.
    // Je vais en faire une fonction appeler "nettoyage_buffer_input".
    
    // On peut se faire une fonction qui rassemble à la fois 
    // la lecture depuis stdin, la suppression du \n et le 
    // nettoyage du canal. Je vais faire cette fonction tout en
    // bas.
    
    char nom_prenom[TAILLE_BUFFER + 1];
    
    printf("Nom Prenom : ");

    lecture_string_input(nom_prenom, TAILLE_BUFFER);

    printf("Nom Prénom marqués : %s\n", nom_prenom);

    return 0;
}

void supp_retour_ligne(char str[])
{
    str[strcspn(str, "\n")] = '\0';
}

void nettoyage_buffer_input(void)
{
    fseek(stdin, 0, SEEK_END);
}

char *lecture_string_input(char *str, int taille)
{
    char *donnee;
    char identificateur_fin_buffer = 0;

    donnee = fgets(str, taille, stdin);

    if(donnee != NULL)
    {
        size_t lenght = strlen(str) - 1;
        if(str[lenght] == '\n')
            str[lenght] = '\0';
        else
        {
            fscanf(stdin, "%*[^\n]");
            fgetc(stdin);
        }
    }

    return donnee;
}
