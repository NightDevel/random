
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
#define MAX_N 100000+5
/*0-9 for digits and 10 is for sum for particular digit length */
int arr[MAX_N][11];
/*
0  :0 0 0 0 0 0 0 1 0 0: 7   
1  :0 0 1 0 1 0 0 0 0 0: 2, 4
2  :0 1 0 1 0 1 0 0 0 0: 1, 3, 5
3  :0 0 1 0 0 0 1 0 0 0: 2, 6
4  :0 1 0 0 0 1 0 1 0 0: 1, 5, 7
5  :0 0 1 0 1 0 1 0 1 0: 2, 4, 6, 8
6  :0 0 0 1 0 1 0 0 0 1: 3, 5, 9
7  :1 0 0 0 1 0 0 0 1 0: 0, 4, 8
8  :0 0 0 0 0 1 0 1 0 1: 5, 7, 9
9  :0 0 0 0 0 0 1 0 1 0: 6, 8
*/
#define MAX_DIGITS 10
int nb[MAX_DIGITS][5] = {{1, 7},
                 {2, 2, 4},
                 {3, 1, 3, 5},
                 {2, 2, 6},
                 {3, 1, 5, 7},
                 {4, 2, 4, 6, 8},
                 {3, 3, 5, 9},
                 {3, 0, 4, 8},
                 {3, 5, 7, 9},
                 {2, 6, 8},
};

void print_arr(int p)
{
    int i;
    for (i = 0; i < MAX_DIGITS; i++)
        printf("%d ", arr[p][i]);
    printf("%d\n", arr[p][i]);
}
void create_data()
{
    int i, j, k;
    long long sum, gsum;
    int mod = 1000000007;
    for (i = 0; i < MAX_DIGITS; i++)
        arr[0][i] = 0;
    for (i = 0; i < MAX_DIGITS; i++)
        arr[1][i] = 1;

    arr[1][MAX_DIGITS] = 10;
    for (i = 2; i < MAX_N; i++) {
        gsum = 0;
        for (j = 0; j < MAX_DIGITS; j++) {
            sum = 0;
            for (k = 1; k <= nb[j][0]; k++) {
                sum += arr[i-1][nb[j][k]];
                if (sum >= mod)
                    sum = sum % mod;
            }
            arr[i][j] = sum;
            gsum += sum;
            if (gsum >= mod)
                gsum = gsum % mod;
        }
        arr[i][j] = gsum;
    }
}

int main()
{
    int t, n;
    create_data();
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        printf("%d\n", arr[n][MAX_DIGITS]);
    }
    return 0;
}

