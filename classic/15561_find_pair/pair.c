#include <stdio.h>
#include <string.h>
#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif
#define NELEM 1024
int arr[NELEM];
int count[NELEM];
int v[NELEM][NELEM];

int main()
{
    int t, N;
    int i, j;
    int bin;
    long long num, cnt;

    for (i = 0; i < NELEM; i++)
        for (j = i+1; j < NELEM; j++)
            v[i][j] = ((i & j) > 0);

    scanf("%d", &t);
    while (t--){
        scanf("%d", &N);
        memset(arr, 0, sizeof(arr));
        memset(count, 0, sizeof(count));
        for (i = 0; i < N; i++) {
            scanf("%lld", &num);
            bin = 0;
            while (num) {
                bin |= (1<<(num%10));
                num = num/10;
            }
            arr[bin] = 1;
            count[bin]++;
        }
        int tcnt, p;
        cnt = 0;
        for (i = 0; i < NELEM; i++) {
            tcnt = 0;
            p = count[i];
            if (p) {
                for (j = i+1; j < NELEM; j++) {
                    if (v[i][j])
                        tcnt += count[j];
                }
            }
            if (p > 1) 
                tcnt = (p * (p-1))/2 + p * tcnt;
            cnt += tcnt;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}

