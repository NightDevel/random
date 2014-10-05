/* T matrix = kxk dimension
 * -------------------------
 *a2        0  1  0  0  ...0  0  0   a1
 *a3        0  0  1  0  ...0  0  0   a2
 *a4        0  0  0  1  ...0  0  0   a3
 *          .
 *          .
 *          .                            
 *          .
 *          0  0  0  0  ...0  1  0
 *A(k)      0  0  0  0  ...0  0  1   A(k-1)
 *A(k+1)   ck ck-1........c3 c2 c1   A(k)
 *A(k+1) = c1*A(K) + c2 * A(k-1) + ..... + ck*a1
 *
 *========================================================
 *Imagine this S(i) = S(i-1) + ai
 *then S(n) - S(m-1) = sum of series of terms from m to n
 *========================================================
 *S(i)   1   1  0  0  0  ...0  0  0   S(i-1)
 *a2     0   0  1  0  0  ...0  0  0   a1
 *a3     0   0  0  1  0  ...0  0  0   a2
 *a4     0   0  0  0  1  ...0  0  0   a3
 *       .   .
 *       .   .
 *       .   .                            
 *       .   .
 *       0   0  0  0  0  ...0  1  0
 *A(k)   0   0  0  0  0  ...0  0  1   A(k-1)
 *A(k+1) 0  ck ck-1........c3 c2 c1   A(k)
 *A(k+1) = c1*A(K) + c2 * A(k-1) + ..... + ck*a1
 *
 * T matrix is (k+1)x(k+1) 
 *
 *
 * A(i+1) = T * A(i)
 * A(i+1), A(i) are  (k+1)x1 dimensions matrices
 *
 * A(k+1) = [A2 A3 A4 ..... A(k+1)]'  = transpose
 * A(P)   = [A1 A2 A3 A4 .. A(k)]'
 * we are given first A(k) values
 *======================================
 * A(P+2) = T*A(P+1) = pow(T,2) * A(P)
 * last row of A(P+2) will give A(k+2) value 
 *======================================
 */

//1 fo sum
//15 for b 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_COEFFICIENTS (1+15+1)

typedef struct { 
    long long e[MAX_COEFFICIENTS][MAX_COEFFICIENTS];
}matrix;

matrix T, F;
long long sub_sum[MAX_COEFFICIENTS];
long long mod;// = 1000000000;

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
matrix power(matrix A, int k, long long p)
{
    if (p == 1)
        return A;

    if (p%2 == 0)
        return power(multiply(A, k, k, A, k, k), k, p/2);        
    else
        return multiply(A, k, k, power(A, k, p-1), k, k);

}
#if 0
long long get_sequence_sum(long long m, long long n, int k)
{ 
    int i;
    matrix D = T;
    matrix Z;
    long long sum = 0;

    /*adjust m*/
    if (m <= k) {
        for (i = m; i <= k; i++)
           sum = (sum + b[i-1])%mod;
        m = k+1;
    }
    D = power(D, k, m-k);
    for (i = m; i <= n; i++) {
        Z = multiply(D, k, k, F, k, 1);
        sum = (sum + Z.e[k-1][0])%mod;
        D = power(D, k, 1);
    }
    return sum;
}
#endif

long long get_sequence(long long n, int k)
{ 
    if (n <= k)
        return sub_sum[n];
/* the way matrix is used, answer is power(T,n)*/
    matrix D = power(T, k+1, n);
    D = multiply(D, k+1, k+1, F, k+1, 1);
    //printf("term %lld:%lld\n", n, D.e[k][0]);
    //printf("sum upto %lld: %lld\n", n, D.e[0][0]);
    return D.e[0][0];
}


void create_sequence(long long B[], long long C[], int k)
{
    int i, j;
    memset(&T, 0, sizeof(T));
    /* T is (k+1)  square matrix
     */
    T.e[0][0] = T.e[0][1] = 1;
    for (i = 1; i <= k-1; i++) 
        T.e[i][i+1] = 1;

    sub_sum[0] = 0;
    for (i = 1; i <= k; i++) { 
        F.e[i][0] = B[i-1];
        sub_sum[i] = sub_sum[i-1] + B[i-1];
    }
    F.e[0][0] = 0;//sub_sum[k]; 
    
    T.e[k][0] = 0;
    for (j = 1; j <= k; j++)
        T.e[k][j] = C[k-j]; 
}


int main()
{
    int t;
    int k; 
    long long m, n;
    int i;
    long long B[MAX_COEFFICIENTS], C[MAX_COEFFICIENTS];

    scanf("%d", &t);
    while (t--){
        scanf("%d", &k);
        for (i = 0; i < k; i++)
            scanf("%lld", &B[i]);

        for (i = 0; i < k; i++)
            scanf("%lld", &C[i]);

        scanf("%lld %lld %lld", &m, &n, &mod);

        create_sequence(B, C, k);
        long long a = get_sequence(n, k)-get_sequence(m-1, k);
        if (a < 0)
            a += mod;
        printf("%lld\n", a);
    }
    return 0;
}

