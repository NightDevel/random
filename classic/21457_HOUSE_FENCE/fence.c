
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif

#define MAX_ELEM 5010
int arr[MAX_ELEM];
int min(int a, int b)
{
    return (a < b? a: b);
}
/* Could have implemented segment tree but the input size is less */
int min_value(int a[], int s, int e)
{
    int min = a[s];
    int i = s;
    while (++s <= e) {
        if (min > a[s]) {
            min = a[s];
            i = s;
        }
    }
    return i;
}
/* Divide and conquer */
int brush(int len[], int sub, int s, int e)
{
    if (e < s)
        return 0;

    if (s == e) 
        return ((len[s] - sub) != 0);

    int i, l, r, v;
    i = min_value(len, s, e);
    v = arr[i];
    l = brush(len, v, s, i-1);
    r = brush(len, v, i+1, e);
    return min((v + r + l - sub), e-s+1);

}


int main()
{
    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", brush(arr, 0, 0, n-1));
    return 0;
}
