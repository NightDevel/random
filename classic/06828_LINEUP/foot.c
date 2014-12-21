#include <stdio.h>
#include <string.h>
#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif
#define MAX_N 12

int  INP[MAX_N][MAX_N];
int  D[(1<<(MAX_N-1))+20];

int maximum(int a, int b)
{
    return (a > b ? a: b);
}
int main()
{
    int t;
    int N;
    int i, j;
    scanf("%d", &t);
    while (t--) {
        N = 11;
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                scanf("%d", &INP[i][j]);

        int mask, bit, bcount;
        int max = (1<<N) - 1;
        memset(D, 0, sizeof(D));
        /* we should set it to zero */
        D[max] = 0;
        for (mask = max-1; mask >= 0; mask--) {
            bcount = __builtin_popcount(mask);
            dprintf("D[%02d: %d] = ", mask, bcount);
            /* This is important remember that we are no supposed to pick any player with zero skill in a position
             * With this technique of generation, we cannot directly check that, 
             * so we set the default value of a configuration to be 
             * such that its greater than >  10 (players) * 100 (maximum value)  = 1000
             */
            int mvalue = -1000000;     
            for (bit = 0; bit < N; bit++) {
#if 0
                if (!(mask & (1 << bit)))
                    dprintf("D[%02d: %d: %d] + ", mask|(1<<bit), bcount, bit); 
#endif
                if (INP[bcount][bit] && (!(mask & (1 << bit)))) // && (D[mask| (1<<bit)] > 0))
                    mvalue = maximum(mvalue, INP[bcount][bit] + D[mask| (1<<bit)]);
            }
            D[mask] = mvalue;
            dprintf(" = %d \n", D[mask]);
        }
        printf("%d\n", D[0]);
    }

    return 0;
}
