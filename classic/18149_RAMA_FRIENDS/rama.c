#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	    return (*(int *)a > *(int *)b);
}

int main()
{
    int nT;
    int nelem;
    int k;
    int si;
    long long sum;
    int i;
    int arr[1000];

    scanf("%d", &nT);
    while (nT--) {
        scanf("%d %d", &nelem, &k);
        for (i = 0; i < nelem; i++)
            scanf("%d", &arr[i]);

		
        //qsort(arr, nelem, sizeof(int), compare);
        /* set the possible lowest -ve numbers to positive 
         * if k is exhausted nothing needs to be
         * done more*/
        i = 0;
        while (k && arr[i] <= 0 && i < nelem) {
            arr[i] = -arr[i];
            k--;
            i++;
        }
        /* if k is not exhausted, then 
         * find the smallest abs element
         */
        if (k != 0) {
#if 1
            /* All positive integers */
            if (i == 0) {
                si = 0;
            }
            else if (i == nelem) { //all negative numbers or k >= n
				si = i - 1;
			}
			else {
                /* i is at the boundary of -ve and +ve numbers */
                si = i-1;
                if (arr[i-1] > arr[i])
                    si = i;
            }

            if (k%2 != 0)
                arr[si] = -arr[si];
#else
            if (k%2 != 0) {
                qsort(arr, nelem, sizeof(int), compare);
                arr[0] = -arr[0];
            }
#endif
        }
        sum = 0;
        for (i = 0; i < nelem; i++)
            sum += arr[i];
       
        printf("%lld\n", sum); 
    }
    return 0;
}
