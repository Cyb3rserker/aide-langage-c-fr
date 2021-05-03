// Programme introduisant la fonction scanf

/*
    La fonction scanf permet de stocker des informations venant du canal stdin
    (canal d'entrée comme le terminal) à une adresse dans la mémoire. Cette
    fonction est considérée comme non sécurisée car si on l'utilise mal, elle
    peut causer un grand nombre de problèmes comme le buffer overflow ou encore
    les erreurs de saisie par l'utilisateur qui ne sont pas prise en compte. On
    regardera d'abord le fonctionnement de base de la fonction puis comment
    bien l'utiliser avec sécurité.
*/

#include <stdio.h>
#include <stdlib.h>

// Ne pas prêter attention pour le moment
void nettoyage_buffer_input(void);

int main (void)
{
    //_____UTILISATION_STANDARD_____
    printf("\n_____UTILISATION_STANDARD_____\n");

    /* On utilise scanf de la manière qui suit : */

    printf("\nSAISIE DE NOMBRE :\n");

    int nombre_saisie_par_utilisateur = 0;

    printf("Nombre choisi : ");
    // L'utilisateur va taper le nombre qu'il a choisi puis va appuyer sur entrer

    scanf("%d", &nombre_saisie_par_utilisateur);
    /* Cette ligne va récupérer un entier dans la saisie de l'utilisateur puis va
    stocker ces informations à l'adresse de la variable nombre_saisie_par_utilisateur,
    ce qui affectera cette valeur à la variable. */

    printf("Nombre saisi : %d\n", nombre_saisie_par_utilisateur);

    /*
        Dans le terminal :

        Nombre choisi : 3563
        Nombre saisi : 3563
    */

    /* On peut stocker des données de tous les types comme des entiers, des nombres à
    virgule, des chiffre en héxadécimale etc et tout ça seulement en changeant le drapeau
    dans le premier argument de la fonction. On peut aussi stocker des chaînes de caractères
    mais la synthaxe et légèrement différente : */

    printf("\nSAISIE DE MOT :\n");

    char mot_saisie_par_utilisateur[25];

    printf("Mot choisie : ");
    scanf("%s", mot_saisie_par_utilisateur);
    /* On ne met pas de "&" car le nom de du tableau se comporte comme un pointeur vers le début dudit tableau et donc l'adresse où sera stocker l'information est déjà précisée. */ 
    printf("Mot saisi : %s\n", mot_saisie_par_utilisateur);

    /*
        Dans le terminal :

        Mot choisie : Bateau
        Mot saisi : Bateau
    */

    /* On peut aussi stocker plusieurs informations dans la même ligne de code : */

    printf("\nSAISIE DE PLUSIEURS ELEMENTS SUR LA MEME LIGNE :\n");

    int position_x = 0;
    int position_y = 0;

    printf("X / Y : ");
    scanf("%d / %d", &position_x, &position_y);
    // Malheureusement, l'utilisateur sera obligé de marquer "/" entre les deux coordonnées

    //---------------------------------------------------------------
    nettoyage_buffer_input();//--------------------------------------
    // Ne pas faire attention cela se voit dans les sections plus bas
    //---------------------------------------------------------------

    printf("X : %d / Y : %d\n", position_x, position_y);
    /* L'utilisateur va saisir la coordonnée X, mettra une barre "/" puis mettra Y.
    Cela permet de garder une clareté pendant la saisie et en même temps de ne pas
    stocker la barre. */

    /*
        Dans le terminal :

        X / Y : 3424 / 435
        X : 3424 / Y : 435
    */

    //_____SOLUTION_POUR_SECURITE_____
    printf("\n_____SOLUTION_POUR_SECURITE_____\n");
    /* Comme dit plus haut, on peut rencontrer des problème de sécurité  comme les buffer
    overflows si on ne prend pas les mesures nécessaires. Par exemple, la fonction scanf
    laisse le caractère "\n" (qui est la touche retour à la ligne) dans le buffer
    de stdin et cela peut causer des problème de lecture :

    printf("Entrez une lettre : ");
    scanf("%c", &lettre_saisie_par_utilisateur_1);
    printf("Entrez une autre lettre : ");
    scanf("%c", &lettre_saisie_par_utilisateur_2);

    printf("Première lettre : %c\n", lettre_saisie_par_utilisateur_1);
    printf("Deuxieme lettre : %c\n", lettre_saisie_par_utilisateur_2);

    dans le terminal :

    Entrez une lettre : d
    Entrez une autre lettre : Première lettre : d
    Deuxieme lettre :

    /* Comme on peut le voir, le programme n'a pas laisser le temps à l'utilisateur
    d'entrer la deuxième lettre. Ce qu'il s'est vraiment passé c'est que la première
    utilisation de scanf a laissé dans la mémoire de stdin le caractère de nouvelle ligne
    et la deuxième utilisation de scanf l'a stocké dans lettre_saisie_par_utilisateur_2.
    Pour remédier à ce problème on peut utiliser la fonction (faite par moi-même)
    nettoyage_buffer_input(); : */

    printf("\nNETTOYAGE BUFFER TERMINAL\n");

    char lettre_saisie_par_utilisateur_1 = 0;
    char lettre_saisie_par_utilisateur_2 = 0;

    printf("Entrez une lettre : ");
    scanf("%c", &lettre_saisie_par_utilisateur_1);

    nettoyage_buffer_input();
    // (La fonction est expliquée tout en bas du programme)

    printf("Entrez une autre lettre : ");
    scanf("%c", &lettre_saisie_par_utilisateur_2);

    nettoyage_buffer_input();

    printf("Première lettre : %c\n", lettre_saisie_par_utilisateur_1);
    printf("Deuxieme lettre : %c\n", lettre_saisie_par_utilisateur_2);

    /*On peut commencer par utiliser les valeurs de retour de la fonction
    (int scanf ( const char * format, ... );). En effet, scanf retourne
    le nombre d'éléments qu'elle a pu lire et enregistrer et on
    peut prendre des mesures concernant ça : */

    printf("\nVERIFICATION REUSSITE SAISIE SCANF\n");

    int nombre_saisie_par_utilisateur_2 = 0;
    int valeur_retour_scanf = 0;

    printf("Veuillez entrer un nombre : ");

    /* Comme on sait que le nombre d'éléments que l'on veut scanner est de 1,
    on va faire en sorte que l'affichage de la variable ne se fait que si
    l'affectation avec scanf s'est bien passée. */

    valeur_retour_scanf = scanf("%d", &nombre_saisie_par_utilisateur_2);

    /* Je met cette partie en commentaire car elle dans notre cas on ne veut pas quitter 
    le programme :

    if(valeur_retour_scanf == 1)
    // Si on réussi à scanner 1 éléments, on continu la suite du programme
        printf("Nombre choisi : %d\n", nombre_saisie_par_utilisateur_2);
    else
    {
        printf("Erreur de saisie.\n");
        exit(EXIT_FAILURE);
        // Si on n'arrive pas à faire l'affectation, il faut impérativement
        arrêter le programme.
    }
    */

    /* Pour les erreurs de saisie, on peut faire une boucle while pour que l'utilisateur fasse sa saisie jusqu'à ce que 
     * l'affectation de valeur réuississe : */

    while(valeur_retour_scanf != 1)
    {
        printf("Erreur de saisie. Veuillez recommencer : ");
        nettoyage_buffer_input();
        // On fait un nettoyage de buffer pour éviter que scanf prenne le retour à la ligne 
        // et c'est une mesure à prendre peut importe la valeur lue avant car cela peut 
        // causer une boucle infinie et faire planter le programme.
        valeur_retour_scanf = scanf("%d", &nombre_saisie_par_utilisateur);
    }

    printf("Nombre saisi : %d\n", nombre_saisie_par_utilisateur);

    /* Dans le cas de la lecture de chaîne de caractère, on peut 
     * choisir quel caractère sera lu : */

    printf("\nLECTURE DE CARACTERE SPECIFIQUES\n");
    // On peut choisir de lire certains caractères 
    // spécifiquement. Cela est utile pour augmenter la 
    // sécurité si on sait quelle données on veut lire.

    char choix_ordre_lettres_utilisateur[4];
    valeur_retour_scanf = 0;
    nettoyage_buffer_input();

    printf("Veuillez choisir un ordre avec a, b, et c : ");

    valeur_retour_scanf = scanf("%3[abc]", choix_ordre_lettres_utilisateur);

    while(valeur_retour_scanf != 1)
    {
        printf("Erreur de saisie. Veuillez seulement saisir les lettres a,b et c : ");
        nettoyage_buffer_input();
        valeur_retour_scanf = scanf("%3[abc]", choix_ordre_lettres_utilisateur);
    }

    printf("Ordre choisi : %s\n", choix_ordre_lettres_utilisateur);

    return 0;
}

/* Cette fonction va "nettoyer" le buffer de du canal de communication "stdin" qui est le
canal d'entrer : */
void nettoyage_buffer_input(void)
{
    fscanf(stdin, "%*[^\n]");,
    fgetc(stdin);
}
