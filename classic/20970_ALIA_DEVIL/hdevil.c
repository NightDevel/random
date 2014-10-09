#include <stdio.h>
#include <math.h>

int fib[]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,
			6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,
			832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,
			39088169,63245986,102334155,165580141
		  };

/* Generate all fibs and do a binary search */
int is_fib(int n)
{
	int s = 0;
	int e = sizeof(fib)/sizeof(fib[0])-1;
	int m;

	while (s <= e) {
		m = (s+e)/2;
		if (fib[m] == n) {
			return 1; 
		}
		if (fib[m] < n)
			s = m+1;
		else
			e = m-1;
	}
	return 0;
}



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

int find_factor_sum(int n, int mod)
{
	int s;
	int p, c, l;
	int i, j, k, f, product;
	long long sum;

    p = sqrt(n)+1;
    c = 1;
	f = 0;
	sum = 0;
	for (l = min_pos; n > 1 && primes[l] <= p && l <= max_pos; l++) {
        s = 0;
		product = 1;
		if (n%primes[l] == 0) {
            do {
				product = product * primes[l];
                n = n/primes[l];
				factors[s+f] = product;
                s++;
            } while(n%primes[l] == 0);
            p = sqrt(n)+1;
        }
		k = s+f;
		for (j = f; j < s+f; j++) 
			for (i = 0; i < f; i++, k++) 
				factors[k] = factors[j] * factors[i]; 
		f = k;
    }
	/* end summing */
	if (n > 1) {
		s = 0;
		factors[s+f] = n;
		s++;
		k = s+f;
		for (j = f; j < s+f; j++) 
			for (i = 0; i < f; i++, k++) 
				factors[k] = factors[j] * factors[i]; 
		f = k;
	}
	/*Remove the number n*/
	factors[f-1];
	/* Add the 1 */
	factors[f-1] = 1;
	sum = 0;
	for (i = 0; i < f; i++) {
		sum += factors[i];
		if (sum > mod)
			sum = sum % mod;
	}
	return sum;
}

int divisors_count(int n)
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
        }
    }
    if (n > 1)
        c = c*2;
    return c-1;
}

int main()
{
	int n, m, t;
	int c;
	int res1, res2;;
	generate_primes();
	scanf("%d", &t);
	c = 1;
	while (t--) {
		scanf("%d %d", &n, &m);
		res1 = find_factor_sum(n, m);
		res2 = divisors_count(res1);
		if (is_fib(res2)) 
			printf("Case #%d : YES.\n", c); 
		else
			printf("Case #%d : NO.\n", c); 
		c++;
	}
	return 0;
}

