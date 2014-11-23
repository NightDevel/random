
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
#define MAX_LEN 100000
int arr[MAX_LEN];
int seq[MAX_LEN];

/*find pos on elem m such that a[i] < m <= a[i+1] 
 * return i */
int find_position(int seq[], int n, int e)
{
    int low, mid, high;

    low = 1;
    high = n;

    while (low < high) {
        mid = (low + high)/2;
        dprintf("%d %d %d %d\n", low, mid, high, e);
        if (e <= seq[mid]) 
            high = mid;
        else  
            low = mid+1;
    }
    dprintf("high = %d\n", high);
    return high;
}

int find_position(int seq[], int n, int e)
{
    int low, mid, high;

    low = 1;
    high = n;

    while (low < high) {
        mid = (low + high)/2;
        dprintf("%d %d %d %d\n", low, mid, high, e);
        if (e <= seq[mid]) 
            high = mid;
        else  
            low = mid+1;
    }
    dprintf("high = %d\n", high);
    return high;
}


int print_seq(int seq[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
        printf("%d ", seq[i]);
    printf("\n");
}
int lis1(int arr[], int n)
{
    int i, j, k, e;
    seq[1] = arr[0];
    k = 1;
    for (i = 2; i <= n; i++) {
        e = arr[i-1];
        if (e > seq[k]) {
            dprintf("Increasing k, %d: %d\n", e, seq[k]);
            k++;
            seq[k] = e;
        }
        else 
        if (e <= seq[1]) {
            if (e != seq[1])
                seq[1] = e;
        }

        j = find_position(seq, k, arr[i-1]); 
        seq[j] = arr[i-1];

        print_seq(seq, k);
    }
    return j; 
}

int lis(int arr[], int n)
{
    int i, j, k, e;
    seq[1] = arr[0];
    k = 1;
    for (i = 2; i <= n; i++) {
        e = arr[i-1];
        if (e > seq[k]) {
            dprintf("Increasing k, %d: %d\n", e, seq[k]);
            k++;
            seq[k] = e;
        }
        else 
        if (e <= seq[1]) {
            if (e != seq[1])
                seq[1] = e;
        }

        j = find_position(seq, k, arr[i-1]); 
        seq[j] = arr[i-1];

        print_seq(seq, k);
    }
    return j; 
}


int main()
{
    int t;
    int n;
    int i;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) 
            scanf("%d", &arr[i]);
        printf("%d\n" ,lis(arr, n));
    }
    return 0;
}

