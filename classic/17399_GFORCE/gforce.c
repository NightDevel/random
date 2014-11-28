#include <stdio.h>
#define MAXNUM 10000000
int  phi[MAXNUM + 1], prime[MAXNUM+1], psz;
char mark[MAXNUM + 1];
int  prime_diff[MAXNUM + 1];

long long power_mod(long long a,  long long p, int mod)
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



/* Euler totient function
 * phi(n) = n - 1, if n is prime
 * phi(i * n) = phi(i) * n (1-1/n) = phi(i) * (n-1)
 */
void generate_primes()
{
    int max_diff = 0;
    int i, j;
    int s;
    psz = 0;
    phi[1] = 1;
    for (i = 2; i <= MAXNUM; i++) {
        if(!mark[i]) {
            phi[i] = i-1;
            prime[++psz] = i;
        }
        for (j = 1; j <= psz && prime[j] * i <= MAXNUM; j++) {
            mark[prime[j] * i] = 1;
            if(i % prime[j] == 0) { // we reached the end of our prime 
                phi[prime[j] * i] = prime[j] * phi[i]; 
                break;
            }
            phi[prime[j] * i] = (prime[j]-1) * phi[i];
        }
        s = psz - phi[i];
        if (s <= 0) // max diff is 2 for which factorial is 2
            s = 1;  // for 1 is 1 and for 0 is 1, so handle this situation
        prime_diff[i] = s; 
    }
}

int main()
{
    int t;
    int id;
    long long res, N;

    generate_primes();
    
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &N);
        printf("%lld\n", power_mod(phi[N], prime_diff[N], 1000000007));
    }
    return 0;
}
