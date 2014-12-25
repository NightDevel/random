
#include <stdio.h>
#if 0
#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
#endif
#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif
#define NELEM 1000010
int arr[NELEM];

int main()
{
    int t, N;
    int i, j;
    int bin;
    long long num, count;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            scanf("%lld", &num);
            bin = 0;
            while (num) {
                bin |= (1<<(num%10));
                num = num/10;
            }
            arr[i] = bin;
        }
        count = 0;
        for (i = 0; i < N; i++) 
            for (j = i+1; j < N; j++) 
                count += ((arr[i] & arr[j]) > 0);
        printf("%lld\n", count);

    }
    return 0;
}

