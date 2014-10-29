#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif

#define MAX_VAR 4

typedef struct {
	long long e[MAX_VAR][MAX_VAR];
}matrix;

matrix multiply(matrix P, int m, int n, matrix Q, int r, int s, int mod)
{
	int i, j, l;
	long long sum;
	matrix D;
	/* mxn * rxs = mxs */
	for (i = 0; i < m; i++) {	  //final row value (m)
		for (j = 0; j < s; j++) { //final column value (p)
			D.e[i][j] = 0;
			sum = 0;
			for (l = 0; l < n; l++)  //n 
				sum = (sum + P.e[i][l] * Q.e[l][j])%mod;
			D.e[i][j] = sum;
		}
	}	
	return D;
}
matrix power(matrix A, int k, int p, int mod)
{
	int i;
	matrix B;
	memset(&B, 0, sizeof(matrix));
	for (i = 0; i < k; i++)
		B.e[i][i] = 1;

	while (p > 1) {
		if (p % 2 == 0) {
			A = multiply(A, k, k, A, k, k, mod);	 
			p = p/2;
		} else {
			B = multiply(B, k, k, A, k, k, mod); 
			p--;
		}
	}
	B = multiply(B, k, k, A, k, k, mod); 
	return B;
}

void calculate_fib(int n, int mod)
{
    matrix F, C;
    F.e[0][0] = 1;
    F.e[0][1] = 1;
    F.e[1][0] = 1;
    F.e[1][1] = 0;
    C = power(F, 2, 2*n-1, mod) ;

    printf("%lld/%lld\n", C.e[0][1], C.e[0][0]);

}



int main()
{
    int t;
    int N, M;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &N, &M);
        calculate_fib(N, M);
    }
    return 0;
}

