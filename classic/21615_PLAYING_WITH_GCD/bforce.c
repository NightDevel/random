#include <stdio.h>

int gcd(int m, int n)
{
    int t;
    while (m != n) {
        if (m > n) 
            m  = m - n;
        else 
            n = n - m;
    }
    return m;
}


int main()
{
    int m, n;
    int i, j;
    int N;
    int c = 0;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
        for (j = 1; j <= i; j++)
            if (gcd(i, j) > 1)
                c++;
    printf("%d\n", c);
}


