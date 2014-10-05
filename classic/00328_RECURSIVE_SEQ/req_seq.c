/* T matrix = kxk dimension
 * -------------------------
 * 0  1  0  0  ...0  0 0
 * 0  0  1  0  ...0  0 0
 * 0  0  0  1  ...0  0 0
 * .
 * .
 * .
 * .
 * 0  0  0  0  ...0  1 0
 * 0  0  0  0  ...0  0 1
 * ck ...........c3 c2 c1
 * ---------------------------
 * A(i+1) = T * A(i)
 * A(i+1), A(i) are  kx1 dimensions matrices
 *
 * A(k+1) = [A2 A3 A4 ..... A(k+1)]'  = transpose
 * A(P)   = [A1 A2 A3 A4 .. A(k)]'
 * we are given first A(k) values
 *======================================
 * A(P+2) = T*A(P+1) = pow(T,2) * A(P)
 * last row of A(P+2) will give A(k+2) value 
 *======================================
 */

//ignore 0, starting from offset 1
//10 for b, 
// 1 for c

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_COEFFICIENTS (1+10+1)

typedef struct { 
    long long e[MAX_COEFFICIENTS][MAX_COEFFICIENTS];
}matrix;

matrix T, F;
long long mod = 1000000000;

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
    for (i = 0; i < m; i++) {     //final row value (m)
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

long long get_sequence(int n, int k)
{ 
    matrix D = power(T, k, n-k);
    D = multiply(D, k, k, F, k, 1);
    return D.e[k-1][0];
}


void create_sequence(long long B[], long long C[], int k)
{
    int i, j;
    memset(&T, 0, sizeof(T));
    /* fill from column 2 upto k onwards
     * Along k-1 rows*/
    /* 1 to k-1 */
    /* F is column(supposed) vector, containing the k initializers */
    for (i = 0; i <= (k-2); i++) 
        T.e[i][i+1] = 1;

    for (i = 0; i <= (k-1); i++) 
        F.e[i][0] = B[i];
    
    for (j = 0; j <= (k-1); j++)
        T.e[k-1][j] = C[k-1-j]; 
}


int main()
{
    int t;
    int k, n;
    int i;
    long long B[MAX_COEFFICIENTS], C[MAX_COEFFICIENTS];

    scanf("%d", &t);
    while (t--){
        scanf("%d", &k);
        for (i = 0; i < k; i++)
            scanf("%lld", &B[i]);

        for (i = 0; i < k; i++)
            scanf("%lld", &C[i]);

        scanf("%d", &n);

        create_sequence(B, C, k);
        if (n <= k) 
            printf("%lld\n", B[n-1]);
        else
            printf("%lld\n", get_sequence(n, k));
    }
    return 0;
}

