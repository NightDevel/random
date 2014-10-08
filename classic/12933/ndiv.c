#include <stdio.h>
#include <math.h>


/*max prime <= 32000; as max is 1000,000,000*/

int primes[32000];
int min_pos  = 0;
int max_pos = 0;

#define GET_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
static inline int isprime(int n)
{
    int i, c;
    c = sqrt(n);
    for (i = 2; i <= c; i++){
        if ((n%i) == 0) 
            return 0;
    }
    return 1;
}


void generate_primes()
{
    int i, l;
    for (i = 2, l = 0; i < GET_SIZE(primes); i++) {
        if (isprime(i))
            primes[l++] = i;
    }
    max_pos = l-1;
}

int calculate_factors(int n, int cnt)
{
	int s;
	int p, c, l;

    p = sqrt(n)+1;
    c = 1;
	for (l = min_pos; n > 1 && primes[l] <= p && l <= max_pos; l++) {
        s = 0;
		if (n%primes[l] == 0) {
            do {
                n = n/primes[l];
                s++;
            } while(n%primes[l] == 0);
            c = c * (s+1);
            /* update p as n is reduced, as required max prime will reduce */
            p = sqrt(n)+1;
            /*If we get more than what we require then bail out */
            if (c > cnt)
                return c;
        }
    }
    if (n > 1)
        c = c*2;
    return c;
}

int main()
{
    int tn;
    int a, b, c;
    int i, k;
	generate_primes();
	scanf("%d %d %d", &a, &b, &c);
    k = 0;
	for (i = a; i <= b; i++){
		if (calculate_factors(i, c) == c)
			k++;
	}
	printf("%d\n", k);
    return 0;
}
