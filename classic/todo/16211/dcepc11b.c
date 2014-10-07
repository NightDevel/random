#include <stdio.h>
int factorial_mod(int N, int P)
{
	if (N >= P)
		return 0;
	/* Wilsons theorem 
	 * (P-1)! % P = -1 % P
	 * ---------------------
	 * (P+1)%P = 1 % P
	 * (P+2)%p = 2 % P
	 * ...
	 */
	
	/* N < P */
	if (N == (P-1))
		return P-1;

	/* Remaining case N <= P-2 */
	/* Lets use Wilson's theorem */

		long long mul = 1;
		for (i = 1; (P+i) <= N; i++) {
			mul *= mul * i;
			if (mul > P)
				mul = mul % P;
		}
		mul = mul * (P-1);
		return (mul*(P-1))%P)
}
int main()
{
    int t;
	int N, P;
    scanf("%d", &t);
    while (t--){
		scanf("%d %d", N, P);
		printf("%d\n", factorial_mod(N, P));
    }
    return 0;
}

