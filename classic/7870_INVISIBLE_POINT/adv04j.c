#include <stdio.h>
int get_max_qns(int n)
{
    int qns = 0;
    int bn  = n;
    while (n > 4) {
        qns++;
        n = (n+1)/2;
    } 
    if (bn == 4 || bn == 3)
        qns += 3;
    return qns;
}

int main()
{
    int t;
    int sides;
    scanf("%d", &t);
    while (t--){
        scanf("%d", &sides);
        printf("%d\n", get_max_qns(sides));
    }
    return 0;
}

