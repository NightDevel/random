#include <stdio.h>
int factorial_mod(int N, int P)
{
	if (N >= P)
		return 0;
	/* Wilsons theorem 
	 * (P-1)! % P = -1 % P
	 * when P is prime
	 * ---------------------
	 * (P+1)%P = 1 % P
	 * (P+2)%p = 2 % P
	 * ...
	 */
	
	/* N < P */
	if (N == (P-1))
		return P-1;

	/* Remaining case N <= P-2 
	   Lets use Wilson's theorem 
	   1.2.3.4.....N % P
	   1 - N = N terms
	   
	   if P is large, then 
	   procedure 1: we have to check whether the straight approach
	   ie. 1.2.3.4.5.6.7.8.9.... N (MOD P)

	   or this
	   procedure 2:
	   let's assume 
	   k(MOD P) = N!(mod P)
	   k.(N+1)  . (N+2). (N+3) . (N+4)....(P-1)(MOD P) = N(N+1)(N+2)(N+3)...(P-1)(MOD P)
										               = (P-1)!(MOD P)
										               = -1(MOD P)
	   k.(N+1-P) (N+2-P)                   (-2).(-1)   = -1(MOD P)
	
	   is better

	   (P-(N+1)) < N => (P-1 < 2*N)
	   
	   If we choose procedure two then few more steps are required.
	   Remeber we do not know what k is, which is what we have to find.


	   Finding k:
		fermat's theorem power(a, P-1) = 1(mod P), if a and P are relatively prime
		let's assume that (N+1-P) (N+2-P) ...... -3 -2 -1 is a
		then 
		ka(MOD P)      = -1(MOD P)
		-k.a(MOD P)    =  1(MOD P)
		k.(-a)(MOD P)  =  1(MOD P)
		k.(P-a)(MOD P) =  1(MOD P)   => (A)

		set k = (P-a)^(P-2)
		then (A) becomes (P-a)^(P-1)(MOD P) = 1(MOD P)
						
		due to fermats little theorem

		finally find (P-a)^(P-2)(MOD P)

		do repeated exponentiation and find the result.
		*/
		
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

