#include <stdio.h>
#include <math.h>
#define MAX_VAR    100+10
long double mat1[MAX_VAR][MAX_VAR];
long double mat2[MAX_VAR][MAX_VAR];

long double inp[MAX_VAR][MAX_VAR];

long double B[MAX_VAR];

void gauss_elimination(long double (*mat)[MAX_VAR], long double *B, int N)
{
    int r;
    int c;
    int t;
    int i;
    int mrow;
    int tr, tc, tvar;
    long double max, fmax;
    long double tmp;

#if 0
    printf("====================\n");
#endif
    for (r = 1; r <= N; r++) {
        /*find the max pivot in the first column */
        mrow = r;
        c    = r;
        max = fabs(mat[r][c]);
        for (tr = r + 1; tr <= N; tr++) {
            if ((fmax = fabs(mat[tr][c])) > max) {
                mrow = tr;
                max = fmax;
            }
        }

        if (mrow != r) {
            /* found a better pivot
             * swap current r and 
             * the pivot row
             * */
#ifdef DEBUG
            printf("swapping %d %d\n", r, mrow);
#endif
            for (tc = 1; tc <= N; tc++) {
                tvar = mat[r][tc];
                mat[r][tc] = mat[mrow][tc];
                mat[mrow][tc] = tvar;
            }
            var_pos[r] = mrow;
            var_pos[mrow] = r;
            tmp = B[r];
            B[r] = B[mrow];
            B[mrow] = tmp;
        }
#ifdef DEBUG
        if (mat[r][r] == 0) {
            printf("screwed up\n");
        }
#endif
        /* now do the reduction 
         * We are not going to 
         * divide reduce the diagnol
         * to 1, as it creates nuisance
         * fractions, so we are going to pretend we did
         */
        long double ratio = mat[r][r];
        c = r;
        for (tr = r+1; tr <= N; tr++) {
            /* lets say we have like this 
             * 5 1 2 3
             * 4 7 4 1
             * .......
             * assume row 1, r = 1
             *               c = 1
             *              trow = 2
             * ratio = a[trow][c]/a[r][r]= 4/5
             * row = 2 modifications
             * 4 = 4 - (4/5) * 5 = 0
             * 7 = 7 - (4/5) * 1 = 6.2
             * 4 = 4 - (4/5) * 2 = 2.4
             * 1 = 1 - (4/5) * 3 = -1.4
             */
            ratio = mat[tr][c]/mat[r][r];
            for (tc = c+1; tc <= N; tc++)
                mat[tr][tc] -= ratio * mat[r][tc]; 
            mat[tr][c] = 0;
            B[tr] -= ratio * B[r];
        }
#ifdef DEBUG
        int p, q;
        for (p = 1; p <= N; p++) {
            for (q = 1; q <= N; q++)
                printf("%5.2llf ", mat[p][q]);
            printf("%5.2llf\n", B[p]);
        }
        printf("====================\n");
#endif
    }
    /* back substitution */
    long double psum;

    B[N] /= mat[N][N];
    for (r = N-1; r >= 1; r--) {
        psum = B[r];
        for (c = N; c > r; c--) 
            psum -= B[c] * mat[r][c];
        B[r] = psum/mat[r][r];
    }

    for (i = 1; i <= N; i++)  {
//        printf("%llf ", B[i]);
        printf("%lld ", llrint(B[i])%10007);
    }
    printf("\n");
}


void init_matrix(int N, int M, long double *B)
{
    int R, C, r,c;
    int item;
    int s, i;
    long double (*m1)[MAX_VAR] = mat1;
    long double (*m2)[MAX_VAR] = mat2;
    long double (*t)[MAX_VAR];
    while (M--) {
        for (R = 1; R <= N; R++) {
            for (C = 1; C <= N; C++) {
                s = 0;
                for (i = 1; i <= 5; i++)  {
                    r = inp[R][i];
                    s += m1[r][C];
                    if (s >= 10007)
                        s = s % 10007;
                }
                m2[R][C] = s;
            }
        }
        t = m1;
        m1 = m2;
        m2 = t;
    }
#if DEBUG
    for (r = 1; r <= N; r++) {
        for (c = 1; c <= N; c++)
            printf("%llf ", m1[r][c]);
        printf("\n");
    }
#endif
    int tvar;
    for (r = 1; r <= N; r++) {
        for (c = 1; c < r; c++) {
            tvar = m1[r][c];
            m1[r][c] = m1[c][r];
            m1[c][r] = tvar;
        }
    }
    gauss_elimination(m1, B, N);
}

int main()
{
    int N, M;
    int i, j;
    int pos;
    int item;
    scanf("%d %d", &N, &M);

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= 5; j++) { 
            scanf("%d", &item);
            inp[i][j] = item;
            mat1[i][item] = 1;
        }
    }
    for (i = 1; i <= N; i++) {
        scanf("%llf", &B[i]);
    }

    M -= 2;
    init_matrix(N, M, B);
    return 0;
}

