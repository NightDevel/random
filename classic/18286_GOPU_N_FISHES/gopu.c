#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif

#define MAX_N 16
float D[(1<<(MAX_N-1)) + 10];
float prb[MAX_N][MAX_N];
int main()
{
    int t;
    int N;
    int i, j, k;
    double fprb;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &N);
        memset(D, 0, sizeof(D));
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++) 
                scanf("%f", &prb[i][j]);
        }
        int max; 
        int mask, bitcount, bit;
        max = (1<<N)-1;
        D[max] = 1;
        for (mask = max-1; mask >= 0; mask--) {
            bitcount = __builtin_popcount(mask);
            for (bit = 0; bit < N; bit++) { 
                if (!(mask & (1 << bit))) //bit not set, we are good to go
                    D[mask] += prb[bitcount][bit] * D[mask | (1<<bit)] ;
            }
        }
        printf("%f\n", D[0]);
    }
    return 0;
}
