#include <stdio.h>
#include <stdlib.h>
#define MAX_VAR 100
typedef struct {
	long long e[MAX_VAR][MAX_VAR];
}matrix;
#define mod 1000000007

matrix pow_mat_2[20];
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
			for (l = 0; l < n; l++) { //n 
				sum += (P.e[i][l] * Q.e[l][j]);
				if (sum >= mod)
					sum = sum % mod;
				//sum  = (sum + (P.e[i][l] * Q.e[l][j])) % mod;
			}
			D.e[i][j] = sum;
		}
	}	
	return D;
}

#include <string.h>
#if 0
matrix power(matrix A, int k, int p)
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
#endif

matrix I;
matrix power_1(matrix A, int k, int p)
{
	int i;
	matrix B = I;
	while (p) {
		if (p & 1) 
			B = multiply(B, k, k, A, k, k); 
		A = multiply(A, k, k, A, k, k);	 
		printf("%d\n", p);
		p = p >> 1;
	}
	return B;
}

unsigned int v;  // find the number of trailing zeros in 32-bit v 
int r;           // result goes here
static const int bitset[32] = 
{
      0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8, 
        31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
};
int get_low_bit(int n) 
{
    return bitset[((unsigned int)((v & -v) * 0x077CB531U)) >> 27];
}

matrix power(matrix A, int k, int p)
{
	int i;
	matrix B;
#if 1
	for (i = 0; p; p = p >> 1, i++) {
		if (p & 1) {
			B = pow_mat_2[i];
			i++;
			p = p >> 1;
		    break;
		}
	}
#endif
//    i = get_low_bit(p);
//    B = pow_mat_2[i];
//    i++;
//    p = p >> i;
	for (; p; p = p >> 1, i++) {
		if (p & 1) 
	        B = multiply(B, k, k, pow_mat_2[i], k, k); 
	}
	return B;
}
int main()
{
	matrix C;
	int mat[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
	};

	int N;
	int t;
	int r, c;
	long long sum;

	for (r = 0; r < 10; r++) {
		for (c = 0; c < 10; c++) {
			C.e[r][c] = mat[r][c];
			if (r == c)
				I.e[r][c] = 1;
		}
	}

    /* Generate pow of 2 matrices upto 2^16 */
    int k;
    matrix D;
    pow_mat_2[0] = C;
    for (k = 1; k <= 16; k++)
        pow_mat_2[k] =  multiply(pow_mat_2[k-1], 10, 10, pow_mat_2[k-1], 10, 10); 

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		if (N == 1)  {
		    printf("10\n");
		    continue;
		}
		else
		if (N == 2) {
		    D = C;
		}
        else
		    D = power(C, 10, N-1);
	
		sum = 0;
		for (r = 0; r < 10; r++) {
			for (c = 0; c < 10; c++) {
				sum += D.e[r][c];
				if (sum >= mod)
					sum = sum % mod;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
