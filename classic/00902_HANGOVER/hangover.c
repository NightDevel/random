#include <stdio.h>
double arr[1000];
int min_len = 0;
int max_len = 1000;
void precompute_n()
{
    int i;
    arr[0] = 0.0;
    for(i = 1; i <= 999; i++)  {
        arr[i] = arr[i-1] + 1.0/(i+1);
        //printf("%d : %f\n", i, arr[i]); 
        if (arr[i] >= 5.22) {
            max_len = i;
            break;
        }
    }
}
void find_n(double f)
{
    int l = min_len;
    int h = max_len;
    int m = (l+h)/2;
    /*binary search*/
    while (1) {
        if (arr[m] > f) {
           if (arr[m-1] < f)
                break;
           h = m - 1;
        }
        else if (arr[m] < f) {
            l = m + 1;
        }
        else 
            break;
        m = (l+h)/2;
    }
    printf("%d card(s)\n", m);
}
int main()
{
    double f;
    precompute_n();
    while (1) {
        scanf("%lf", &f);
        if (f == 0.00)
            break;
        find_n(f);
    }
    return 0;
}

