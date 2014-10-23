#include <stdio.h>
#include <math.h>
void find(int N)
{
    long long i;
    long long s;
    long long p;
    long long q;
    int k = 0;
    //for (i = -N; i <= N; i++) {
    for (i = 1; i <= N; i++) {
        q = 2 * i;
        p = ((q-1)*(q-1) + 8 * N);
        s = sqrt(p);
        if (s*s == p) {
            k++;
          //  printf("%lld: %lld\n", i, (s-(q+1))/2);

        }
    }
    printf("%d\n", 2*k);
}

#include <stdlib.h>

int primes[32000];
int min_pos  = 0;
int max_pos = 0;
void generate_primes()
{
    int i, l, s, n;
    int max_primes;
    max_primes = sizeof(primes)/sizeof(primes[0]);
    /* two is prime */
    l = 0;
    primes[l++] = 2;
    primes[l++] = 3;
    primes[l++] = 5;
    primes[l++] = 7;
    /* skip even numbers */
    for (n = 11; n < max_primes; n += 2) {
        s = sqrt(n) + 1;
        for (i = 3; i <= s; i += 2) {
            if ((n%i) == 0) {
                break;
            }
        }
        if (n%i != 0)
            primes[l++] = n;
    }
    max_pos = l-1;
}

void factor(int n)
{
	int p, l;
	int f;
    int i;
    int tways = 1;
    
    while (n % 2 == 0) {
        n = n / 2;
    }

	for (l = min_pos+1, p = primes[l]; (p*p) <= n && l <= max_pos; p = primes[++l]) {
        f = 0;
		while (n%p == 0) {
			f++;
            n = n/p;
        }
        //printf("%d:%d:%d\n", p, f+1, n);
        tways = tways * (f+1);
    }
	if (n > 1) { 
        tways = tways * 2;
        //printf("%d\n", n);
    }

    printf("%d\n", 2*tways);
}

int main()
{
    int t;
    int N;
    generate_primes();
    while (1) {
        scanf("%d", &N);
        if (N == 0)
            break;
        factor(N);
//        find(N);
    }
}
