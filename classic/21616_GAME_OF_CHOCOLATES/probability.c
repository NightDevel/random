#include <stdio.h>
#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...) 
#endif

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
int main()
{
    int t, cs;
    long long a, b, c, d;
    long long TA_N, TA_D, TB_N, TB_D, T_N, T_D, C;
    scanf("%d", &t);
    cs = 0;
    while (t--){
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        cs++;
        if (a == 0 && b == 0) {
            printf("Case %d: 0\n", cs);
            continue;
        }
        TA_N = (c+1) * (a);
        TA_D = (c+d+1) * (a+b);
        C = gcd(TA_N, TA_D);
        TA_N /= C;
        TA_D /= C;
    
        TB_N = (d+1) * (b);
        TB_D = (c+d+1) * (a+b);
        C = gcd(TB_N, TB_D);
        TB_N /= C;
        TB_D /= C;
   
        T_N = (TA_N * TB_D + TB_N * TA_D);
        T_D = TA_D * TB_D;
        C = gcd(T_N, T_D);
        printf("Case %d: %lld/%lld\n", cs, T_N/C, T_D/C);
    }
    return 0;
}

