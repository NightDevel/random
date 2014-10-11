#include <stdio.h>
#include <string.h>
long long get_ones(int n)
{
    char dpos[32];
    int i, k, c;
    k = 31;
    /*find the digits position */
    memset(dpos, 0, sizeof(dpos));
    for (i = 0; i < 32 && n; i++)  {
        if (n & (1<<i))
           dpos[k--] = i+1;
    }
    k++;
    long long sum;
    long long nterms;
    long long index;
    sum = 0;
    /*start from msb onwards
     *say we have 100101010
     * How many numbers are there upto 100000000
     * or put it other way,number of (N-1) bit digits
     * is pow(2, N-1)
     * width of the bits is (N-1)
     * total bits = pow(2, N-1) * N
     * half of those bits would be 1
     * Goto to next msb repeat until 
     * last term
     * but before going to next term
     * remember the number of times the next term comes,
     * the msb repeats itself
     */
    for (c = 1; k < 32; k++, c++) {
        index = dpos[k];
        nterms = (1UL<<(index-1));
        sum += (nterms * (index-1))/2 + (c-1) * nterms; 
    }
    c--;
    sum += c;
    return sum;
}
int main()
{
    int t;
    int a, b, c;
    long long acnt, bcnt;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &a, &b);
        /* a < b */
        /* a < 0 < b */
        if (b >= 0) {
            bcnt = get_ones(b);
            if (a > 0) {
                acnt = get_ones(a-1);
                printf("%lld\n", bcnt - acnt);
            }
            else {
                acnt = get_ones(-1) - get_ones(a-1);
                printf("%lld\n", acnt + bcnt);
            }
        }
        else {
            /* a < b < 0 */
            bcnt = get_ones(-1) - get_ones(b);
            acnt = get_ones(-1) - get_ones(a-1);
            printf("%lld\n", acnt - bcnt);
        }
    }
    return 0;
}

