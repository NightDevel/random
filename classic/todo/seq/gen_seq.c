#include <stdio.h>
#define MAX_ELEM 130080606
long long arr[MAX_ELEM];

void generate_rev_seq()
{
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 6;
    
    int iter;
    int cur_pos, cur_incr;
    /*generate the sequence this way
     * 1 starts from 1
     * 2 starts from 2
     * To fill 3 = add 2 value (2) + incr (1)
     */
    cur_pos     = 5;
    cur_incr    = 3;
    iter        = 1;
    while (cur_incr < MAX_ELEM){

        iter = arr[cur_incr+1] - arr[cur_incr];
        for (;iter-- > 0 && cur_pos < MAX_ELEM; cur_pos++)  {
            arr[cur_pos] = arr[cur_pos-1] + cur_incr; 
            }
        cur_incr++;
    } 
    printf("%2lld : %2lld\n", cur_pos-1, arr[cur_pos-1]);
}

void generate_rev_seq1()
{
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    
    int iter;
    int cur_pos, cur_incr;
    /*generate the sequence this way
     * 1 starts from 1
     * 2 starts from 2
     * 3 starts from 4
     * we need three parameters
     *
     * cur_incr = how much increment
     * iteration = size of group having cur_incr
     * start of cur_pos 
     *
     * here cur_pos = 4, looking at other way, where does 3 value is series is going to end
     * 
     * incr = 2
     * number of iter = 1
     * a[4] = a[3_end] = a[3_start] + incr = 4 + 2 = 6
     * 
     * incr = 3
     * number of interations for this group = a[incr+1] - a[incr] = a[4] - a[3] = 2 groups (4,5)
     * a[5] = a[4_end] = a[4_start] +  incr = 6 + 3 = 9
     * a[6] = a[5_end] = a[5_start] + incr  = 9 + 3 = 12
     
     * incr = 4
     * number of interations for this group = a[incr+1] - a[incr] = a[5] - a[4] = 3 groups (6,7,8)
     * a[7] = a[6_end] = a[6_start] + incr  = 12 + 4 = 16
     * a[8] = a[7_end] = a[7_start] + incr  = 16 + 4 = 20
     * a[9] = a[8_end] = a[8_start] + incr  = 20 + 4 = 24
     *
     *
     */
    cur_pos     = 4;
    cur_incr    = 2;
    iter        = 1;
    while (cur_pos < MAX_ELEM) {

        for (; iter-- > 0 && cur_pos < MAX_ELEM; cur_pos++)  
            arr[cur_pos] = arr[cur_pos-1] + cur_incr; 

        cur_incr++;
        iter = arr[cur_incr+1] - arr[cur_incr];
    } 
//    printf("%2lld : %2lld\n", cur_pos-1, arr[cur_pos-1]);
}

long long find_nth(long long n)
{
    long long m, l, h;

    l = 0;
    h = MAX_ELEM-1;

    while (l <= h) {
        m = (l+h)/2;
        if ((arr[m] == n) ||(arr[m] < n && n < arr[m+1]))
            return m;

        if (n > arr[m]) 
            l = m + 1;
        else
            h = m - 1;
    }


}
int main()
{
    int t;
    long long n;
    generate_rev_seq1(); 
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        printf("%lld\n", find_nth(n));
    }
    return 0;
}
