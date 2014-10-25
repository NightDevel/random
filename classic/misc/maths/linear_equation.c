#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VAR  110
int MODULUS = 10007;

int mat1[MAX_VAR][MAX_VAR];
int B[MAX_VAR];

typedef struct {
	int e[MAX_VAR][MAX_VAR];
}matrix;


int find_mod_mul(int a, int b)
{
	int i;
	if (b == 0)
		return 0;

	a = a % MODULUS;
	b = b % MODULUS;

	if (a < 0)
		a += MODULUS;

	if (b < 0)
		b += MODULUS;

	for (i = 1; (a*i) % MODULUS != b; i++);

	return i;
}

void gauss_elimination(int (*mat)[MAX_VAR], int *B, int N)
{
	int r, c, i;
	int mrow;
	int tr, tc, tvar;
	int max, fmax;

	for (r = 1; r <= N; r++) {
		/*find the max pivot in the r column */
		mrow = r;
		c	 = r;
		max = abs(mat[r][c]);
		for (tr = r + 1; tr <= N; tr++) {
			if ((fmax = abs(mat[tr][c])) > max) {
				mrow = tr;
				max = fmax;
				break;
			}
		}

		if (mrow != r) {
			/* found a better pivot
			 * swap current r and 
			 * the pivot row
			 * */
			for (tc = 1; tc <= N; tc++) {
				tvar = mat[r][tc];
				mat[r][tc] = mat[mrow][tc];
				mat[mrow][tc] = tvar;
			}
			tvar = B[r];
			B[r] = B[mrow];
			B[mrow] = tvar;
		}
		/* Should never happen. Problem with the input or implementation*/
		if (mat[r][r] == 0)
			exit(-1);

		/* transform the rest of below columns to zero */
		c = r;
		for (tr = r+1; tr <= N; tr++) {
			for (tc = c+1; tc <= N; tc++)  
				mat[tr][tc] = ((mat[tr][tc]*mat[r][r]) - mat[tr][c] * mat[r][tc])%MODULUS; 
			
			int p; 
			if ((p =(B[tr] * mat[r][r] - B[r] * mat[tr][c])%MODULUS) != B[tr]) {
				B[tr] = p;
			}
			mat[tr][c] = 0;
		}
	}
	/* Back substitution */
	int psum;
	for (r = N; r >= 1; r--) {
		psum = B[r];
		for (c = N; c > r; c--) 
			psum = (psum - B[c] * mat[r][c])%MODULUS;
	
		/* m * x = b(MOD P), find x*/
		B[r] = find_mod_mul(mat[r][r], psum); 
	}

	for (i = 1; i <= N; i++)  {
		printf("%d ", B[i]%MODULUS);
	}
	printf("\n");
}

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
	for (i = 1; i <= m; i++) {	  
		for (j = 1; j <= s; j++) { 
			D.e[i][j] = 0;
			sum = 0;
			for (l = 1; l <= n; l++)  
				sum = (sum + P.e[i][l] * Q.e[l][j])%MODULUS;
			D.e[i][j] = sum;
		}
	}	
	return D;
}
matrix power(matrix A, int k, int p)
{
	int i;
	matrix B;
	memset(&B, 0, sizeof(matrix));
	for (i = 1; i <= k; i++)
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



void solve(matrix A, int N, int M, int *B)
{
	int r,c;
	int (*m1)[MAX_VAR] = mat1;
	matrix Aout;

	Aout = power(A, N, M);
	for (r = 1; r <= N; r++) 
		for (c = 1; c <= N; c++) 
			m1[r][c] = Aout.e[r][c];

	gauss_elimination(m1, B, N);
}

int main()
{
	int N, M;
	int i, j;
	int pos;
	int item;
	matrix A;
#if 0
	scanf("%d %d", &N, &M);

	memset(&A, 0, sizeof(matrix));
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= 5; j++) { 
			scanf("%d", &item);
			A.e[i][item] = 1;
		}
	}
	for (i = 1; i <= N; i++) 
		scanf("%d", &B[i]);

	M -= 1;
	if (M == 0) {
		for (i = 1; i <= N; i++)  {
			printf("%d ", B[i]%MODULUS);
		}
		printf("\n");
	}
	else {
		solve(A, N, M, B);
	}
#else
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) 
			scanf("%d", &mat1[i][j]);
		scanf("%d", &B[i]);
	}
	gauss_elimination(mat1, B, N);
#endif

	return 0;
}

