
#include <stdio.h>
#include <math.h>
#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
char seq[1000000+100];
char a[1000000+100];
int k, n, m;
int power[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
void debrujin(int t, int p)
{
    int j;
    if (t > n) {
        if (n % p == 0) {
            for (j = 1; j <= p; j++)
                seq[m++] = a[j];
        }
    }    
    else {
        a[t] = a[t-p];
        debrujin(t+1, p);
        for (j = a[t-p]+1; j < k; j++) {
            a[t] = j;
            debrujin(t+1, t);
        }
    }
}
int main()
{
    int t, i, l;
    while (1){
        scanf("%d", &n);
        if (n == 0)
            break;
        k = 10;
        m = 0;
        seq[0] = 0; //first character
        debrujin(1, 1);
//        int l = pow(10, n); 
        l = power[n];
        for (i = 0; i < l; i++)
            printf("%d", seq[i]);
        for (i = 1; i <= (n-1); i++)
            printf("0"); //first character
        printf("\n"); 
    }
    return 0;
}

