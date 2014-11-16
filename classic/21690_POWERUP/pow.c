
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
long long power_mod(long long a,  long long p, long long mod)
{
    /*while shifting the last bit is always 1, so the result will be in c */
    long long c = 1;
    while (p) {
        if (p&1)
            c = (c * a) % mod;
        a = (a * a) % mod;
        p = p>>1;
    }
    return c;
}


int main()
{
    long long a, b, c, d;
    long long modulus = 1000000007;
    while (1){
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == -1)
            break;

        if (c == 0)
            d = 1;
        else
        if (b == 0)
            d = 0;
        else 
        if (a % modulus == 0)    
            d = 1;
        else
            d = power_mod(b, c, modulus-1); 
        printf("%lld\n", power_mod(a, d, modulus)); 
    }
    return 0;
}

