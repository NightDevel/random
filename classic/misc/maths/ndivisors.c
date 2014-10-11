#include <stdio.h>
#include <math.h>
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


int divisors_count(int n)
{
	int s;
	int p, cnt, l;

    cnt = 1;
	for (l = min_pos, p = primes[l]; (p*p) <= n && l <= max_pos; l++, p = primes[l]) {
        s = 0;
		if (n%p == 0) {
            do {
                n = n/p;
                s++;
            } while(n%p == 0);
            cnt = cnt * (s+1);
        }
    }
    if (n > 1)
        cnt = cnt * 2;

    return cnt-1;
}

int main(int argc, char *argv[])
{
	int n;
    if (argc != 2) {
        printf("Usage: %s number\n", argv[0]);
        exit(0);
    }
    n = atoi(argv[1]);
	generate_primes();
    printf("%d\n", divisors_count(n));
	return 0;
}

