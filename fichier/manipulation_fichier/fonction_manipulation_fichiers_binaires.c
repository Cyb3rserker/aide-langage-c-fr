// Programme montrant la manipulation de fichiers binaires

/*
    Les fichiers binaires contiennent des copies de la RAM.
    Ces donnés sont stockées directement sous forme d'octets dans 
    le fichier binaire. Les fichiers binaires sont plus rapide à manipuler 
    que les fichiers formatés comme les fichiers textes.
*/

/*
    [FONCTIONS]

    - fopen(<fichier_binaire>, <mode_ouverture>) : ouvre un fichier
        Les différents modes d'ouverture des fichiers binaires :
            - rb : lecture seul, le fichier doit exister
            - wb : écriture seul et supprime le contenu du fichier, 
                   si le fichier n'existe pas alors programme le crééra
            - ab : ajout en fin de fichier et conserve le contenu, le fichier 
                   peut être créer aussi
            - r+b ou rb+ : lecture / écriture, le fichier doit exister
            - w+b ou wb+ : lecture / écriture et supprime le contenu du fichier
            - a+b ou ab+ : lecture / écriture à la fin et conserve le contenu
    
    /!\ ATTENTION !!! Si le mode d'ouverture contient la lettre "a", même si on utilise "fseek" 
    avec un retour au début, le retour se fera à la fin du fichier au moment de son ouverture pour 
    conserver son contenu et donc toutes les modifications seront faîtes à cet endroit.
    
    - fwrite(<pointeur_vers_donnée_à_écrire>, <taille_élément>, 
    <nombre_élément_à_écrire>, <pointeur_vers le_fichier>); : permet 
    d'écrire des données directement sous forme d'octet dans un fichier binaire
    
    - fread(<pointeur_vers_variable_stockage>, <taille_élément>, 
    <nombre_élément_à_lire>, <pointeur_vers le_fichier>); : permet 
    de stocker des données dans une variable à partir d'un fichier binaires.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Position_du_joueur
{
    int posX;
    int posY;
}Position;


int main(void)
{ 
    /*_____ECRITURE_____*/
    
    FILE *fic;
    int positionX = 145;
    int positionY = 86;

    fic = fopen("fichier_binaire.bin", "wb");
    /* Penser à mettre "b" pour binaire et w...a pour la 
    création éventuelle et l'écriture en fin de fichier. */

    /* On met "wb" pour le mode d'ouverture de fichier binaires. 
    et l'écriture après suppression de son contenu. */

    if(fic == NULL)
    {
        fprintf(stderr, "Erreur ouverture fichier.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(&positionX, sizeof(int), 1, fic);
    fwrite(&positionY, sizeof(int), 1, fic);
    
    //_____AVEC_UN_TABLEAU_____
    
    int positions[3]= {48, 76};
    // Ne pas oublier le \0 de fin de tableau.
    
    fwrite(positions, sizeof(int), 2, fic);
    // On a 2 éléments à mettre dans le fichier.
    // On ne met pas & car c'est un tableau.

    fclose(fic);

    /*_____LECTURE_____*/
    
    fic = fopen("fichier_binaire.bin", "rb");

    if(fic == NULL)
    {
        fprintf(stderr, "Erreur ouverture fichier.\n");
        exit(EXIT_FAILURE);
    }
    
    int stockage_posX;
    int stockage_posY;
    
    fread(&stockage_posX, sizeof(int), 1, fic);
    fread(&stockage_posY, sizeof(int), 1, fic);


    printf("Position des joueurs : %d/%d\n", stockage_posX, stockage_posY);

    //_____AVEC_UN_TABLEAU_____

    int stockage_positions[3];

    fread(stockage_positions, sizeof(int), 2, fic);
    /* On met 2 éléments dans le troisième argmument donc 
    on met un 2. */

    printf("Position des joueurs : %d/%d\n", stockage_positions[0], stockage_positions[1]);

    fclose(fic);

    /*
        Le résultat de fin :

        Position des joueurs : 145/86
        Position des joueurs : 48/76
    */

    /*_____AVEC_UNE_STRUCTURE_____*/
    
    //_____ECRITURE_____
    
    FILE *fic2 = fopen("sauvegarde.bin", "wb");

    if(fic2 == NULL)
    {
        fprintf(stderr, "Erreur ouverture fichier.\n");
        exit(EXIT_FAILURE);
    }
   
    Position po;

    po.posX = 100;
    po.posY = 25;

    fwrite(&po, sizeof(po), 1, fic2);
    // C'est la taille de la structure et il y a 1 élément à écrire.
    // Avec une seule ligne, on a pu enregister 2 données à la fois.
    
    fclose(fic2);
    
    //_____LECTURE_____

    fic2 = fopen("sauvegarde.bin", "rb");

    if(fic2 == NULL)
    {
        fprintf(stderr, "Erreur ouverture fichier.\n");
        exit(EXIT_FAILURE);
    }

    Position stockage_po;

    stockage_po.posX;
    stockage_po.posY;

    fread(&stockage_po, sizeof(stockage_po), 1, fic2);
    // Encore une fois la taille de la structure avec 1 élément à écrire.
    // Encore avec une seule ligne, on a pu stocker 2 données à la fois.

    printf("Position X Joueur : %d\nPosition Y Joueur : %d", stockage_po.posX, stockage_po.posY);

    fclose(fic2);

    /* On peut voir que l'utilisation de structure facilite l'enregistrement de données en 
    des lignes de code, et donc évite le risque d'erreur. */

    return 0;
}