#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a < *(int *)b);
}

int main()
{
    int n;
    int i, j;
    int Q[100000+5];
    int N[100000+5];

    scanf("%d", &n);
    for (i = 0; i < n; i++) 
        scanf("%d", &Q[i]);

    for (i = 0; i < n; i++) 
        scanf("%d", &N[i]);
    
    qsort(Q, n, sizeof(int), compare);
    qsort(N, n, sizeof(int), compare);
   
    for (i = 0, j = 0; i < n && j < n; j++) {
        if (N[i] > Q[j])
            i++; 
    }
    printf("%d\n", i);
    return 0;
}

