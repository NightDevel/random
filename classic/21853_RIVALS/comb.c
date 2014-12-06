#include <stdio.h>
#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif

#define MAX_ELEM 2000000+10
long long modulus=1000000007;
long long fact[MAX_ELEM];

long long  power_mod(long long a, long long p, int m)
{
    long long c = 1;
    while (p) {
        if (p&1) 
            c = (c * a) % m;
        a = (a * a) % m;
        p = p >> 1;
    }
    return c;
}

long long comb(int m, int n)
{
    long long a, b, c;
    a = fact[m+n];
    b = power_mod(fact[m], modulus-2, modulus);
    c = power_mod(fact[n], modulus-2, modulus);
    return (a * ((b * c) % modulus) % modulus);
}

int main()
{
    int i, T;
    long long p;
    long long m, n;

    fact[0] = 1;
    for (p = 1; p < MAX_ELEM; p++) 
        fact[p] = (p * fact[p-1]) % modulus;

    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &m, &n);
        printf("%lld\n", comb(m, n));
    }
    return 0;
}
