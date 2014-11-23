#include  <stdio.h>
/* returns index such that
 * a[i] > e > a[i+1]
 * return i+1;
 */
int binsearch_dec(int arr[], int l, int h, int e)
{
    int m;
    while (l < h) {
        m = (l+h)/2;
        if (e < arr[m]) 
            l = m+1; 
        else
            h = m;
    }
    printf("l: %d, h = %d\n", l, h);
    return 0;
}

/* returns index such that
 * a[i] < e <= a[i+1]
 * return i+1;
 */

int binsearch(int arr[], int l, int h, int e)
{
    int m;
    while (l < h) {
        m = (l+h)/2;
        if (e > arr[m]) 
            l = m+1; 
        else
            h = m;
    }
    printf("l: %d, h = %d\n", l, h);
    return 0;
}

int main()
{
    int arr[]= {0, 1, 3, 5, 7, 8, 10, 25, 40};
    //int darr[]= {0, 40, 25, 10, 8, 7, 5, 3, 1};
    int darr[]= {0, 9, 3};//40, 25, 10, 8, 7, 5, 3, 1};
    int s = sizeof(darr)/sizeof(darr[0]);

    int i;
    for (i = 1; i < s; i++) 
        printf("%3d ", i);
    printf("\n");
    for (i = 1; i < s; i++) {
        printf("%3d ", darr[i]);
    }
    printf("\n");
    while (1) {
        int e;
        scanf("%d", &e);
        binsearch_dec(darr, 1, s-1, e);
    }
}

