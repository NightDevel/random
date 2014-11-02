#include <stdio.h>
#define MAX_N 100
long long s[MAX_N][MAX_N];

void generate_stirling(int N)
{
    int i, k, n;
    for (i = 0; i < MAX_N; i++) {
        s[i][0] = 0;
        s[0][i] = 0;
    }
    s[0][0] = 1;

    for (n = 1; n < N; n++) {
        printf("%d:  ", n);
        for (k = 1; k <= n; k++) {
            s[n][k] = s[n-1][k-1] - (n-1) * s[n-1][k];
            printf("%lld ", s[n][k]);
        }
        printf("\n");
    }


}

int main()
{
    generate_stirling(26);
}
