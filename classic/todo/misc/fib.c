#include <stdio.h>
#include <math.h>

int fib[]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,
			6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,
			832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,
			39088169,63245986,102334155,165580141
		  };


	
int is_fib(int n)
{
	int s = 0;
	int e = sizeof(fib)/sizeof(fib[0])-1;
	int m;

	while (s <= e) {
		m = (s+e)/2;
		if (fib[m] == n) {
			printf("%d:%d\n", n, m);
			return 1; 
		}
		if (fib[m] < n)
			s = m+1;
		else
			e = m-1;
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", is_fib(n));
}
