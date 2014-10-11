#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int factors[32000];
/* 
 * factors are generated this way:
 * 1. if a prime divides n then if it can repeatedly then do it
 * 
 * ARR: 0 0 0 0 0 0 0 0 0 ....
 * say number 360.
 * Run1: 2 divides 360, 3 times continously
 * So 
 * ARR: 2 4 8 //check for product 
 * 
 * come out of loop, check for previous divisors, 0 as of now
 * so no need of multiply previous divisors
 *
 * current divisors = 3 (2, 4, 8)
 * Run2: 45 will remain and now 3 divides it two times continously
 * ARR: 2 4 8 3 9
 *
 * out of loop
 * now multiply 3 9 with 2 4 8 in a loop
 * to get
 * ARR: 2 4 8 3 9 6 12 24 18 26 72
 * current divisors = 11
 *
 * Run3: 5
 * ARR: 2 4 8 3 9 6 12 24 18 26 72 5 
 * out of loop
 * ARR: 2 4 8 3 9 6 12 24 18 26 72 5 10 20 40 15 45 30 60 120 240 360 
 * 
 * Last number for sure is the given N.
 * 1 is missing too
 * so replace 360 with 1 and we shall have all the required divisors
 */

int factor(int n)
{
	int p, l;
	int f;
    int i;

    f = 0;
	for (l = min_pos, p = primes[l]; (p*p) <= n && l <= max_pos; p = primes[++l]) {
		if (n%p == 0) {
			factors[f++] = p;
            do {
                n = n/p;
            } while(n%p == 0);
        }
    }
	if (n > 1) 
		factors[f++] = n;

	for (i = 0; i < f; i++) {
        printf("%d ", factors[i]);
	}
    printf("\n");
    return f;
}
void euler_phi(int n)
{
    int i;
    int maxf = factor(n);
    int res = n;
    for (i = 0; i < maxf; i++)
        res = res - res/factors[i];
    printf("%d\n", res);
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
    factor(n);
//    euler_phi(n);
	return 0;
}

