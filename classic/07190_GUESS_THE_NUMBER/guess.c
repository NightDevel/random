#include <stdio.h>
#include <string.h>
long long gcd(long long a, long long b)
{
    while (1) {
        if (a == b)
            return a;
        if (a < b)
            a^=b^=a^=b;
        a = a - b;
    }
    return 0;
}
long long lcm(long long  a, long long  b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int t;
    char str[25];
    int ndigits[20];
    char *p;
    long long m;
    int l;
    int i;
    int k;
   
    while (1) { 
        scanf("%s",str+1);
        memset(ndigits, 0, sizeof(ndigits));
        if (str[1] == '*')
            break;
        l = strlen(str+1);
        m = 1;
        k = 0;
        for (i = 1; i <= l; i++) {
            if (str[i] == 'Y') {
                m = lcm(m, i);
            }
            else
                ndigits[k++] = i;
        }
        for (i = 0; i < k; i++) {
            if (m%ndigits[i] == 0) {
                m = -1;
                break;
            }
        }
        printf("%lld\n", m);
    }
    return 0;
}

