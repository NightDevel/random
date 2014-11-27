
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
unsigned long long arr[100][100];
void create_sequence(int N)
{
    int k, n;
    int i, j, r;
    unsigned long long sum;
    for (n = 0; n <= 100; n++) 
        arr[n][0] = 1;
    
    for (n = 1; n <= 100; n++) 
        arr[n][n] = 1;
    
    for (n = 2; n <= N; n++) {
        for (r = 1; r < n; r++) {
            sum = 0;
            for (k = n-1; k >= (n-r); k--)
                sum += arr[k][r]; 

            for (i = 0; i <= k && i <= r; i++)
                sum += arr[k][i];

            dprintf("%d:%d: %llu\n", n, r, sum);
            arr[n][r] = sum;
        }
    }
}

int main()
{
    int n, i;
    create_sequence(64);
//    scanf("%d", &n);
    for (n = 1; n <= 63; n++) {
        for (i = 0; i <= n; i++)
            printf("%llu ", arr[n][i]);
        printf("\n");
    }
    return 0;
}

