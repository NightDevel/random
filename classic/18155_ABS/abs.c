#include <stdio.h>
int main()
{
    int i, j, T, N;
    int A[10002];
    long long abs;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (i = 0; i < N; i++) 
           scanf("%d", &A[i]);
        
        i = 0;
        j = N-1;
        N = N-1;
        abs = 0;
        while (i < j) { 
            abs += N * (A[j] - A[i]); 
            N = N - 2;
            i++; j--;
        }
#if 0
        sum = 0;
        for (i = N; i >= 1; i--) {
            abs += i * A[i-1] - sum;
            sum -= A[i-1];
        }
#endif
        printf("%lld\n", abs);
    }
    return 0;
}

