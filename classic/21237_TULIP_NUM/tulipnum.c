
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
int arr[100000+10];
int dsum[100000+10];
int main()
{
    int t;
    int n;
    int p;
    int q;
    int l, m;
    int i;
    int ind;
    scanf("%d", &t);
    ind = 1;
    while (t--){
        scanf("%d %d", &n, &q);
        scanf("%d", &arr[1]);
        p = arr[1];
        dsum[1] = 1;
        for (i = 2; i <= n; i++) {
            scanf("%d", &arr[i]);
            dsum[i] = dsum[i-1];
            if (arr[i] != p) {
                dsum[i]++;
                p = arr[i];
            }
        }
        printf("Case %d:\n", ind++);
        for (i = 0; i < q; i++) {
            scanf("%d %d", &l, &m);
            printf("%d\n", dsum[m] - dsum[l] + 1);
        }
    }
    return 0;
}

