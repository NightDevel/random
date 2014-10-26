#include <stdio.h>
int main()
{
    int t;
    unsigned long long n, p, d;
    int r;
    scanf("%d", &t);
    while (t--){
        scanf("%lld", &n);
        if (n % 2 == 0) 
            p = (n*n);
        else 
            p = (n+3)*(n+3);
      
        d = p/48;  
        r = p%48; 
        /* due to overflows answer will be wrong, so handle the fraction carefully */
        double r1 = (double)r/48 + 0.5;
        if (r1 >= 1)
            d++;
        printf("%llu\n", d);
    }
    return 0;
}

