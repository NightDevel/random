
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
#define modulus        1000000007
#define inverse_mod_3  333333336
unsigned long long power_mod(unsigned long long a, unsigned long long p)
{
    unsigned long long c = 1;
    while (p > 1) {
        if (p%2 == 0) {
            a = (a*a)%modulus;
            p = p/2;
        }
        else {
            c = (c * a)%modulus;
            p--;
        }
    }
    return (c*a)%modulus;
}


int main()
{
//    long long modulus = 1000000007;
//    long long inverse_mod_3 = 333333336;
    unsigned long long n;
    unsigned long long r;


    while (scanf("%llu", &n) != EOF) {
        if (n == 0)
            r = 1;
        else
            r = power_mod(2, n);//%(modulus-1));

        if (n&1) 
            r = r + 1;
        else 
            r = r + 2;
        printf("%llu\n", (r*inverse_mod_3)%modulus);
    }
    return 0;
}

