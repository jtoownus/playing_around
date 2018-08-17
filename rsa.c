#include <cs50.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

// primes as of ./primes = 101 and 131
//https://medium.com/asecuritysite-when-bob-met-alice/how-do-you-make-a-bet-so-that-the-bookie-cant-tell-how-much-you-have-won-c573528d87d4
int gcd(int, int);

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./rsa int(a) int(b)");
        return 1;
    }

    //initialize 2 integers to multiply from user input
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    //randomly chose prime numbers
    int p = 5;
    int q = 7;

    //random encryption key
    unsigned long long e = 11;

    //calculated N
    unsigned long long n = p * q;

    //calculating phi
    unsigned long long PHI = (p - 1) * (q - 1);
    unsigned long long d = 1; //modular multiplicative inverse initialising

    //calculate cipher of a, b and their product
    unsigned long long cipher_a = ((unsigned long long) (pow(a, e)) % n);
    unsigned long long cipher_b = ((unsigned long long) (pow(b, e)) % n);
    unsigned long long cipher_c = ((cipher_a * cipher_b) % n);


    //check greates common divisor (not sure how, what???)
    if (gcd(e, PHI) != 1)
    {
        printf("Choose differend encryption key!");
        return 1;
    }

    //primitive calculation of mod._multi._inverse (inverse_of)
    while (((e * d) % PHI) != 1)
    {
        d++;
    }

    //decrypt cipher(c) using d and n
    unsigned long long c = ((unsigned long long) pow(cipher_c, d) % n);

    //print a bunch of stuff
    printf("prime p is: \t %i\n", p);
    printf("prime q is: \t %i\n", q);
    printf("key e =\t \t %lld \n", e);
    printf("phi =\t\t %lld \n \n", PHI);


    printf("Cipher(a) =\t %lld \n", cipher_a);
    printf("Cipher(b) =\t %lld \n", cipher_b);
    printf("Cipher(c) =\t %lld \n \n", cipher_c);



    printf("decrypt. key d =\t %lld\n", d);


    printf("\nDecrypting Cipher(c) yields: %lld\n", c);

    return 0;
}

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            return gcd(a - b, b);
        }
        else
        {
            return gcd(a, b - a);
        }
    }
    return a;
}