#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif

long long power_mod(long long a,  long long p, int mod)
{
    /*while shifting the last bit is always 1, so the result will be in c */
    long long c = 1;
    while (p) {
        if (p&1) 
            c = (c * a)%mod;
        a = (a*a)%mod;
        p = p>>1;
    }
    return c;
}


int main()
{
    long long modulus = 1000000007;
    long long inverse_mod_3 = 333333336; /*Inverse modulus of 3 w.r.t modulus
                                          *i.e (3 * inverse_mod_3) % modulus = 1 % modulus
                                          */
    
    long long n;
    long long r;


    while (scanf("%llu", &n) != EOF) {
        if (n == 0)
            r = 1;
        else
            r = power_mod(2, n%(modulus-1));

        if (n&1) 
            r = r + 1;
        else 
            r = r + 2;
        printf("%llu\n", (r*inverse_mod_3)%modulus);
    }
    return 0;
}

