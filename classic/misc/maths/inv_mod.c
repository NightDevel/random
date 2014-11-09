
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif

int main()
{
    int n;
    int m;
    int i;
    scanf("%d %d", &n, &m);
    i = m/n+1;
    while ((i*n)%m != 1)
        i++;
    printf("%d\n", i);
    return 0;
}

