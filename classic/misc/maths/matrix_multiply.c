#include <stdio.h>
#include <stdlib.h>
#define MAX_VAR 100
typedef struct {
	long long e[MAX_VAR][MAX_VAR];
}matrix;
#define mod 10007
matrix multiply(matrix P, int m, int n, matrix Q, int r, int s)
{
	int i, j, l;
	long long sum;
	matrix D;
	/* mxn * rxs = mxs */
	if (n != r) {
		printf("Invalid arguments\n");
		exit(-2);
	}	
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
/* only square matrices can be powered */
/* A : matrix to be powered
 * k : dimension of A i.e kxk
 * p : power of the matrix needed
 */
matrix power(matrix A, int k, int p)
{
	if (p == 1)
		return A;

	if (p%2 == 0)
		return power(multiply(A, k, k, A, k, k), k, p/2);	 
	else
		return multiply(A, k, k, power(A, k, p-1), k, k);

}
#include <string.h>
matrix power_1(matrix A, int k, int p)
{
	int i;
	matrix B;
	memset(&B, 0, sizeof(matrix));
	for (i = 0; i < k; i++)
		B.e[i][i] = 1;

	while (p > 1) {
		if (p % 2 == 0) {
			A = multiply(A, k, k, A, k, k);	 
			p = p/2;
		} else {
			B = multiply(B, k, k, A, k, k); 
			p--;
		}
	}
	B = multiply(B, k, k, A, k, k); 
	return B;
}

int main(int argc, char *argv[])
{
	matrix C;
	int mat[7][7] = 
	{{1,1,1,1,1,0,0},
	 {1,1,1,0,1,1,0},
	 {1,1,0,1,0,1,1},
	 {1,0,1,1,1,1,0},
	 {0,1,1,0,1,1,1},
	 {1,0,1,0,1,1,1},
	 {0,1,0,1,1,1,1},
	};
	int N;
	int r ;
	int c ;
	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			C.e[r][c] = 0;
			if (c == r)
				C.e[r][c] = 1;//mat[r][c];

		}
	}
	matrix D = power_1(C, r, atoi(argv[1]));//800000);
			//2147483647);
#if 1
	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			printf("%d ", D.e[r][c]);
		}
		printf("\n");
	}
#endif
#ifdef CHECK
	matrix E;
	E = power(C, r, atoi(argv[1]));//800000);
			//2147483647);
#if 0
	for (r = 0; r < 6; r++) {
		for (c = 0; c < 6; c++) {
			printf("%d ", D.e[r][c]);
		}
		printf("\n");
	}
#endif


	for (r = 0; r < N; r++) {
		for (c = 0; c < N; c++) {
			if (D.e[r][c] != E.e[r][c]) {
				printf("0\n");
				return 0;
			}
		}
	}
#endif
	printf("1\n");

}

