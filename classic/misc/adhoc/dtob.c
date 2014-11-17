#include <stdio.h>
const char* byte_to_binary( int x )
{
    static char b[sizeof(int)*8+1] = {0};
    int y;
    long long z;
    for (z=1LL<<sizeof(int)*8-1,y=0; z>0; z>>=1,y++)
    {
        b[y] = ( ((x & z) == z) ? '1' : '0');
    }

    b[y] = 0;

    return b;
}

int find_ones(const char *s)
{
    int k, m = 0;
    while (*s) {
        k = 0;
        while (*s && *s++ == '1')
            k++;
        if (k > m)
            m = k;
    }
    return m;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    printf("%s\n", byte_to_binary(n));
}
