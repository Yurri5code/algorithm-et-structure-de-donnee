#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
// Fonction pour effectuer la division `x/y` de deux nombres `x` et `y`
// sans utiliser l'opérateur de division dans le code
int divide(int x, int y)
{
    // gère la divisibilité par 0
    if (y == 0)
    {
        printf("Error!! Divisible by 0");
        exit(-1);
    }
 
    // stocke le signe du résultat
    int sign = 1;
    if (x * y < 0) {
        sign = -1;
    }
 
    // convertit à la fois le dividende et le diviseur en positif
    x = abs(x);
    y = abs(y);
 
    unsigned mask = 1;
    unsigned quotient = 0;
 
    while (y <= x)
    {
        y <<= 1;
        mask <<= 1;
    }
 
    while (mask > 1)
    {
        y >>= 1;
        mask >>= 1;
        if (x >= y)
        {
            x -= y;
            quotient |= mask;
        }
    }
 
    printf("The remainder is %d\n", x);
    return sign * quotient;
}
 
int main()
{
    int dividend = 22;
    int divisor = -7;
 
    printf("The quotient is %d\n", divide(dividend, divisor));
 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
 
// Fonction pour effectuer la division `x/y` de deux nombres `x` et `y`
// sans utiliser l'opérateur de division dans le code
int divide(int x, int y)
{
    // gère la divisibilité par 0
    if (y == 0)
    {
        printf("Error!! Divisible by 0");
        exit(-1);
    }
 
    // stocke le signe du résultat
    int sign = 1;
    if (x * y < 0) {
        sign = -1;
    }
 
    // convertit à la fois le dividende et le diviseur en positif
    x = abs(x), y = abs(y);
 
    // initialise le dénominateur par `y`
    int denominator = y;
 
    // initialise le quotient par 1
    int quotient = 1;
 
    // Double dénominateur et quotient jusqu'à ce que le dénominateur soit supérieur à
    // dividende `x`
    while (x > denominator)
    {
        denominator *= 2;
        quotient *= 2;
        // printf("%d %d\n", denominator, quotient);
    }
 
    // Soustraire le diviseur `y` du dénominateur et réduire le quotient de 1 jusqu'à
    // le dénominateur est inférieur au dividende `x`
    while (denominator > x)
    {
        denominator -= y;
        quotient -= 1;
        // printf("%d %d\n", denominator, quotient);
    }
 
    printf("The remainder is %d\n", x - denominator);
    return sign * quotient;
}
 
int main(void)
{
    int dividend = 22;
    int divisor = -7;
 
    printf("The quotient is %d\n", divide(dividend, divisor));
 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
 
// Fonction récursif pour effectuer la division `x/y` de deux nombres positifs
// `x` et `y` sans utiliser l'opérateur de division dans le code
unsigned division(unsigned x, unsigned y)
{
    if (x < y)
    {
        printf("The remainder is %d\n", x);
        return 0;
    }
 
    return 1 + division(x - y, y);
}
 
// Wrapper sur la fonction `division()` pour gérer le dividende négatif ou le diviseur
int divide(int x, int y)
{
    // gère la divisibilité par 0
    if (y == 0)
    {
        printf("Error!! Divisible by 0");
        exit(-1);
    }
 
    // stocke le signe du résultat
    int sign = 1;
    if (x * y < 0) {
        sign = -1;
    }
 
    return sign * division(abs(x), abs(y));
}
 
int main(void)
{
    int dividend = 22;
    int divisor = -7;
 
    printf("The quotient is %d\n", divide(dividend, divisor));
 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
// Fonction pour effectuer la division `x/y` de deux nombres `x` et `y` sans
// en utilisant l'opérateur de division dans le code
int divide(int x, int y)
{
    // gère la divisibilité par 0
    if (y == 0)
    {
        printf("Error!! Divisible by 0");
        exit(-1);
    }
 
    // stocke le signe du résultat
    int sign = 1;
    if (x * y < 0) {
        sign = -1;
    }
 
    // convertit à la fois le dividende et le diviseur en positif
    x = abs(x), y = abs(y);
 
    // initialise le quotient par 0
    int quotient = 0;
 
    // boucle jusqu'à ce que le dividende `x` devienne inférieur au diviseur `y`
    while (x >= y)
    {
        x = x - y;      // effectue une réduction sur le dividende
        quotient++;     // augmente le quotient de 1
    }
 
    printf("The remainder is %d\n", x);
 
    return sign * quotient;
}
 
int main(void)
{
    int dividend = 22;
    int divisor = -7;
 
    printf("The quotient is %d\n", divide(dividend, divisor));
 
    return 0;
}
