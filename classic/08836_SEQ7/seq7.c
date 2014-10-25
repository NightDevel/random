#include <stdio.h>
#define MAX_F_ELEM  (124390+10) //1692 
#define MAX_FF_ELEM (124390+10)

long long FF[MAX_FF_ELEM];
long long F[MAX_F_ELEM];
int incr_arr[MAX_F_ELEM];

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif


void gen_sequence1()
{
    F[1] = 1;
    F[2] = 3;
    F[3] = 5;
    
    int iter;
    int cur_pos, cur_incr;
    /*generate the sequence this way
     * 1 ends at 1
     * 2 ends at 2
     * 3 ends at 5
     * we need three parameters
     *
     * cur_incr = how much increment
     * iteration = size of group having cur_incr
     * start of cur_pos 
     *
     * here cur_pos = 4, 
     * 
     * incr = 3
     * number of iter = 2
     * a[4] = a[3_end] + incr = 5 + 3 = 8
     * a[5] = a[4_end] + incr = 5 + 3 = 11
     * 
     * incr = 4
     * number of interations for this group = a[incr] - a[incr-1] = a[3] - a[2] = 3 groups (5,6,7)
     * a[6] = a[5_end] +  incr = 11 + 4 = 15
     * a[7] = a[6_end] + incr  = 15 + 4 = 19
     */
    cur_pos     = 4;
    cur_incr    = 3;
    iter        = 2;
    while (cur_pos < MAX_F_ELEM) {

        for (; iter-- > 0 && cur_pos < MAX_F_ELEM; cur_pos++)   {
            F[cur_pos] = F[cur_pos-1] + cur_incr; 
            dprintf("%lld\n", F[cur_pos]);
        }
        cur_incr++;
        iter = F[cur_incr] - F[cur_incr-1];
    } 
}
/* lets G be the sequence
 * F be the position of an interger which last occurence in the sequence
 * eg: F[1] = 1
 *     F[2] = 2
 *     F[3] = 5
 *     F[4]=  8
 *     Given F and n, find G(n) 
 *     G(n) is k, such that (  F[k-1] < n <= F[k] )
 */
long long find_nth(long long *arr, int size, long long n)
{
    long long m, l, h;

    l = 0;
    h = size - 1;

    while (l <= h) {
        m = (l+h)/2;
        if (arr[m] == n) 
            return m;

        if (arr[m] < n && n < arr[m+1])
            return m+1;

        if (n > arr[m]) 
            l = m + 1;
        else
            h = m - 1;
    }
}



/* hard code the MAX_FF_ELEM such that it crosses 10^13
 * FF[k] be such that the last occurence of F[k] in G
 * This is to not to store the huge values of F[k].
 * FF[k] = FF[k-1] + n * G(k)
 */
void gen_sequence2()
{
    /*const long long max_value = 10000023976079;*/
    long long  k = 1;
    long long G;
    FF[0] = 0;
    for (k = 1; k < MAX_FF_ELEM; k++) {
        G = find_nth(F, MAX_F_ELEM, k);
        FF[k] = FF[k-1] + k * G;
    }
    dprintf("final k = %lld, G = %lld, FF = %lld\n", k, G, FF[k-1]);

}
#include <math.h>
long long G(long long n)
{
    long long k = find_nth(FF, MAX_FF_ELEM, n);
    dprintf("%lld: f = %lld, ff= %lld\n", k, F[k], FF[k]);
    return (F[k] - floor((FF[k]-n)/k));
}
int main()
{
    int t;
    long long n;
    gen_sequence1(); 
    gen_sequence2(); 
#if 1
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        printf("%lld\n", G(n));
    }
    return 0;
#else
    long long i;
    for (i = 1; i <= 1e13; i++)
        if (i % 10000000000 == 0) 
            printf("%lld\n", i);

        long long G1, G2;
        G1 = G(i);
        G2 = find_nth(F, MAX_F_ELEM, i);
        if (G1 != G2)
            printf("%lld : G(i): %lld, find: %lld\n", i, G1, G2);
#endif
}
