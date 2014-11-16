#include <stdio.h>
const char* byte_to_binary(int x)
{
    static char b[100]={0};//sizeof(long long)*8+1] = {0};
    int y;
    long long z;
    for (z=1LL<<sizeof(int)*8-1,y=0; z>0; z>>=1,y++)
    {
        b[y] = (((x & z) == z) ? '1' : '0');
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
    int c = atoi(argv[2]);
    long long l = 1ULL<< n;
    int i;
    long long cnt = 0;
    for (i = 0; i < l; i++) {
        //printf("%s", byte_to_binary(i));
        if (find_ones(byte_to_binary(i)) == c) {
    //        printf("%s:%d\n", byte_to_binary(i), i);
            cnt++;
        }
//        printf("\n");
    }
    printf("%d:%d: %lld\n", n, c, cnt);
}
