
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { printf(fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
#define MAX_LEN (100000+1)
int arr[MAX_LEN];
int seq[MAX_LEN];

/*find pos on elem m such that a[i] >= m > a[i+1] 
 * return i+1 */

int find_position(int s[], int l, int h, int e)
{
    int m;
    while (l < h) {
        m = (l+h)/2;
        if (e < s[m]) 
            l = m+1; 
        else
            h = m;
    }
    dprintf("l: %d, h = %d\n", l, h);
    return l;
}

#if 0
int print_seq(int seq[], int n)
{
    int i;
    dprintf("%s", "printing--seq\n");
    for (i = 1; i <= n; i++)
        dprintf("%d ", seq[i]);
    dprintf("%s", "\n");
}
#endif
int lis(int A[], int S[], int n)
{
    int i, j, k, e;
    S[1] = A[0];
    k = 1;
    for (i = 2; i <= n; i++) {
        e = A[i-1];
        if (S[k] > e) {
            dprintf("Increasing k, %d: %d\n", e, S[k]);
            j = ++k;
        }
        else if (e >= S[1]) {
            j = 1;
        }
        else {
            j = find_position(S, 1, k, e); 
        }

        S[j] = e;
        dprintf("Element = %d: pos = %d\n", e, j);
        //print_seq(S, k);
    }
    return k; 
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
        printf("%d\n" ,lis(arr, seq, n));
    }
    return 0;
}

