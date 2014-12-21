#include <stdio.h>
#include <string.h>
#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif
#define MAX_N 21

char INP[MAX_N][MAX_N];
long long  D[(1<<(MAX_N-1))+20];

int main()
{
    int t;
    int N;
    int i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                scanf("%d", &INP[i][j]);

        int mask, bit, bcount;
        int max = (1<<N) - 1;
        memset(D, 0, sizeof(D));
        D[max] = 1;
        for (mask = max-1; mask >= 0; mask--) {
            bcount = __builtin_popcount(mask);
            dprintf("D[%02d: %d] = ", mask, bcount);
            for (bit = 0; bit < N; bit++) {
#if 0
                if (!(mask & (1 << bit)))
                    dprintf("D[%02d: %d: %d] + ", mask|(1<<bit), bcount, bit); 
#endif
                if (INP[bcount][bit] && !(mask & (1 << bit)))
                    D[mask] += D[mask| (1<<bit)];
            }
            dprintf(" = %d \n", D[mask]);
        }
        printf("%lld\n", D[0]);
    }

    return 0;
}
