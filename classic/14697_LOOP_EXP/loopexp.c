#include <stdio.h>
#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif

float calculate(int n)
{
    int i;
    double s = 1;
    for (i = 2; i <= n; i++)
        s += 1.0/i;
    return s;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        printf("%f\n", calculate(n));
    }
    return 0;
}

