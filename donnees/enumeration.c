// Programme introduisant les énumérations (avec les fichier struct).

/*
    Une énumération permet d'énumérer une liste de 
    valeurs possibles pour une étiquette.
    Ca sert surtout à facilité le dévloppement.

    étiquette : le mot après "enum" ou "struct".
    "L'étiquette de l'énumération... L'étiquette de la structure..."
*/


#include <stdio.h>

typedef enum Boleen
{
    // La liste des valeurs possible pour "Boleen".
    
    FALSE,// 0
    TRUE  // 1
    // On sépare les valeurs par des virgules.

    /*
        Par convention, la première valeur signifie "faux" (0)
        et la deuxième "vrai" (1).
        Aussi par convention, les valeurs sont en majuscules.
    */
} Boleen;

// Création d'un énumération de marque de voiture.

typedef enum marque_de_voiture
{
    PEUGEOT,
    RENAULT,
    TOYOTA,
    MAZDA
} marque;
// On nomme l'énumération "marque".


int main (void)
{
    Boleen b1 = FALSE;
    
    marque voiture1 = TOYOTA;

    return 0;
}