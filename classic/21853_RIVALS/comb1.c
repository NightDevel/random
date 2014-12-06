#include <stdio.h>
#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif

#define MAX_ELEM 2000000+10
long long modulus=1000000007;
long long fact[MAX_ELEM];
long long ifact[MAX_ELEM];

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
long long factorial(int n)
{
    long long r = 1;
    while (n) 
        r = r * (n--);
    return r;
}

void calculate_factorials()
{
    long long  i;

    fact[0] = 1;
    for (i = 1; i < MAX_ELEM; i++) 
        fact[i] = (i * fact[i-1]) % modulus;
}


void c1alculate_factorials()
{
    long long  i;

    fact[0] = 1;
    for (i = 1; i < MAX_ELEM; i++) 
        fact[i] = (i * fact[i-1]) % modulus;

    ifact[0] = 1;
    ifact[1] = 1;
    for (i = 2; i < MAX_ELEM; i++) {
        if (!ifact[i]) {
            ifact[i] = (power_mod(i, modulus-2, modulus) * ifact[i-1]) % modulus;
            if (ifact[i] < MAX_ELEM)
                ifact[ifact[i]] = i;

            dprintf("ifact[%d] = %lld: %d\n", i, factorial(i), ifact[i]);
        }
    }
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
    int t;
    long long m, n;
    calculate_factorials();
    scanf("%lld %lld", &m, &n);
    printf("%lld\n", comb(m, n));
    return 0;
}

