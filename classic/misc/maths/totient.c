#include <stdio.h>
#define MAXNUM 100005
long long phi[MAXNUM + 1], prime[10000], psz;
long long phi_sum[MAXNUM + 1];
char mark[MAXNUM + 1];


/* Euler totient function
 * phi(n) = n - 1, if n is prime
 * phi(i * n) = phi(i) * n (1-1/n) = phi(i) * (n-1)
 */
void generate_primes()
{
    long long  i, j;
    psz = 0;
    phi[1] = 1;
    for (i = 2; i <= MAXNUM; i++){
        if(!mark[i]) {
            phi[i] = i-1;
            prime[psz++]= i;
        }
        for (j = 0; j < psz && prime[j] * i <= MAXNUM; j++) {
            mark[prime[j] * i] = 1;
            if(i % prime[j] == 0) { // we reached the end of our prime 
                phi[prime[j] * i] = prime[j] * phi[i]; 
                break;
            }
            phi[prime[j] * i] = (prime[j]-1) * phi[i];
        }
    }

    phi_sum[0] = 0;
    for (i = 1; i <= MAXNUM; i++) 
        phi_sum[i] = phi[i] + phi_sum[i-1];
}

int main()
{
    int t;
    int id;
    long long res, N;

    generate_primes();
    
    id = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &N);
        res = (N*(N+1))/2 - phi_sum[N];
        printf("Case %d: %lld\n", id, res);
        id++;
    }
    return 0;
}
