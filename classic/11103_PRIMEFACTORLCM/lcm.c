#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif
#define MAX_MARK 1000010
#define TPRIMES    78600

long long primes[TPRIMES];
char mark[MAX_MARK]; 
int last_prime_index;

#define MAX_N_FACTOR 4000
long long factor[MAX_N_FACTOR];
long long ff[MAX_N_FACTOR];

void gen_primes() 
{ 
    long long i, j, k; 

    for (i = 1; i <= MAX_MARK; i++) 
        mark[i] = 1; 

    for(i = 2, k = 0; i <= MAX_MARK; i++) {
        if (mark[i]) {
            primes[k++] = i;
            for(j = i; j*i <= MAX_MARK; j++) 
                mark[i*j] = 0; 
        }
    }
    last_prime_index = k;
} 
#include <stdlib.h>
int compare(const void *a, const void *b)
{
    return ((*(long long *)a) > (*(long long *)b));
}

void find_factors(long long list[], int N, long long fac[], int c)
{
    int i, j, k, l;
    int p;
    long long num;
    int flag;


    k = 0;
    i = 0;
    for (p = primes[k]; k < last_prime_index; p = primes[++k]) {
        flag = 0;
        for (j = 0; j < N; j++) {
            num = list[j];
            if ((p*p <= num) && (num % p == 0)) {
                do {
                    flag = 1;
                    num /= p;
                } while (num % p == 0);
                dprintf("j = %lld, bf = %lld, af = %lld, p = %lld \n", j, list[j], num, p);
                list[j] = num;
            }
        }
        if (flag)
            fac[i++] = p;
    }
    for (j = 0; j < N; j++) {
        if (list[j] > 1) 
            fac[i++] = list[j];
    }

    long long prev;
    qsort(fac, i, sizeof(fac[0]), compare);

    j = 0;
    k = 0;
    while (j < i) {
        prev = ff[k++] = fac[j];
        while (fac[j] == prev && j < i)
            j++;
    }
    printf("Case #%d: %d\n", c, k); 
    for (i = 0; i < k; i++)
        printf("%lld\n", ff[i]);

    return;
}

int main()
{
    int t, i, N, c;
    long long arr[110];

    gen_primes();
    
    dprintf("Last prime = %d\n", primes[last_prime_index-1]);
    c = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (i = 0; i < N; i++) 
            scanf("%lld", &arr[i]);
        memset(factor, 0, sizeof(factor));
        find_factors(arr, N, factor, c);
        c++;
    }
    return 0;
}

