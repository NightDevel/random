#include <stdio.h>
#define MAX_ITEMS (100+10)

int sub_arr[1000*MAX_ITEMS][MAX_ITEMS];
/* calcuate c(subset_sum, item) values*/
void subset_sum(int *arr, int *csum, int n)
{
    int elem;
    int sum, rem_sum;
    int max_sum;
    int t_psum;
    int possible;

    max_sum = csum[n];
    for (sum = 1; sum <= max_sum; sum++)
        sub_arr[sum][0] = 0;

    for (elem = 0; elem <= n; elem++)
        sub_arr[0][elem] = 1;

    t_psum = 0;
    for (sum = 1; sum <= max_sum; sum++) {
        possible = 0;
        for (elem = 1; elem <= n; elem++) {
            if (sum >= arr[elem]) { 
                rem_sum = sum - arr[elem];
                sub_arr[sum][elem] = sub_arr[rem_sum][elem-1] || sub_arr[sum][elem-1];
            }
            else {
                sub_arr[sum][elem] = sub_arr[sum][elem-1];
            }
            if (sub_arr[sum][elem])
                possible = 1;
        }
        if (possible) {
            t_psum += sum;
//            printf("possible: %d\n", sum);
        }
    }
    printf("%d\n", t_psum);
}

int main()
{
    int T;
    int n;
    int i;
    int arr[MAX_ITEMS];
    int csum[MAX_ITEMS];

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        csum[0] = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            csum[i] = csum[i-1] + arr[i];
        }
        subset_sum(arr, csum, n);
    }
    return 0;
}
