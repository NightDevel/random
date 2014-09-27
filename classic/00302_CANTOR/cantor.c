#include <stdio.h>
#include <math.h>
void print(int n)
{
    int b, bsum, c, s, l;
    
    if (n == 1)
        b = 1;
    else {
        b = floor(sqrt(1+8.0*(n))/2);
    //    printf("first b: %d\n", b);
        c = 0;
        while (1) {
            c = (b * (b+1))/2;
            if (c < n)
                b++;
            else {
                break;
            }
        }
    }
    b--;
    //printf("%d\n", b);
    bsum = (b*(b+1))/2;
    
    s = b+1;
    l = n-(bsum+1);
    if (b%2 != 0) 
        printf("TERM %d IS %d/%d\n", n, (l+1), (s-l));    
    else
        printf("TERM %d IS %d/%d\n", n, (s-l), (1+l));    
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        print(n);
    }
    return 0;
}

