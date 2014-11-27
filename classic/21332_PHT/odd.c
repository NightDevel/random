#include <stdio.h>
#include <math.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif

int main()
{
    int t;
    long long s;
    int c;
    scanf("%d", &t);
    c = 1;
    while (t--){
        scanf("%lld", &s);
        printf("Case %d: %lld\n", c++, (long long)sqrt((s+1)*1.0)-1);
    }
    return 0;
}

