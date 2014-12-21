#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif

#define MAX_ELEM 17
const int arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};
double D[32768+3];
double prb[MAX_ELEM][MAX_ELEM];
double enumerate(unsigned int mask, int pos)
{
	unsigned int tmask = mask;
	int bitset;
	int v;
	int tmpmask;

	//if (D[mask])
	//    return D[mask];

	while (tmask) {
		bitset = 31 - __builtin_clz(tmask);
		tmask = tmask & ~arr[bitset];
		dprintf("mask = %d, pos = %d, bitset = %d\n", mask, pos, bitset);
		tmpmask = mask & ~arr[bitset];
		if (D[tmpmask])
    		D[mask] += prb[pos][bitset] * D[tmpmask];
        else
            D[mask] += prb[pos][bitset] * enumerate(tmpmask, pos - 1);
	//	dprintf("mask = %d, pos = %d, bitset = %d\n", mask, pos, bitset);
	}
	return D[mask];
}

int main()
{
    int t;
    int n;
    int i, j, k;
    double fprb;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++) 
                scanf("%lf", &prb[i][j]);
        }
        D[0] = 1;
        fprb = enumerate((1<<n)-1, n-1);
        memset(D, 0, sizeof(D));
        printf("%lf\n", fprb);
    }
    return 0;
}
