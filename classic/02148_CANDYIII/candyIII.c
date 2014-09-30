#include <stdio.h>
int main()
{
    long long t, n, s, e, i;
    scanf("%lld", &t);
    while (t--){
        scanf("%lld", &n);
        s = 0;
        for (i = 0; i < n; i++){
            scanf("%lld", &e);
            s = s+e;
            if (s >= n)
                s = s%n;
        }
        s = s % n;
        if (s == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

