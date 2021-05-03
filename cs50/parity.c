// Vérifier qu'un un nombre est pair ou impair.
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("n: ");
    if (n % 2 == 0)
    // Permet de voir si le reste de la division euclidiènne est 0, ce qui prouverai qu'il est pair.
    {
        printf("n est pair.\n");
    }
    else
    {
        printf("n est impair.\n");
    }
}
