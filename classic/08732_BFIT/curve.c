#include <stdio.h>
#define MAX_VALUES 10010

int data[MAX_VALUES];

void solve(long long n, long long sumof_y, long long sumof_xy)
{
    /*curve fitting 
     *have to calculate 4 values
     * sum(x), sum(x^2), sum(y), sum(xy)
     * sum(x) = sum(1...n) = n(n+1)/2
     * sum(x^2) = sum(1+2^2 + 3^2 ...+n^2) = n (n+1) (2n+1)/6
     */

    /* 
     * |n      sum(x)  |   |a b|
     * |sum(x) sum(x^2)| = |c d| 
     * inverse = |d -b|            |e f|
     *           |-c a|/(ad-bc)  = |g h|
     *
     * b = e * sum(y) + f * sum(xy)
     * a = g * sum(y) + h * sum(xy)
     */
    long long a, b, c, d, det;
    a = n;
    b = c = (n * (n+1))/2;
    d = (n * (n+1) * (2*n+1))/6;

    det = (a * d - b * c); 

    double bf, af;
    bf = ((d  * sumof_y + (-b) * sumof_xy)*1.0)/det;
    af = ((-c * sumof_y + a    * sumof_xy)*1.0)/det;
    printf("%.4lf %.4lf\n", af, bf);
}

int main()
{
    int t;
    int n;
    int i;
    int sum_of_y;
    long long sum_of_xy;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        sum_of_y = 0;
        sum_of_xy = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &data[i]);
        }
        for (i = 1; i <= n; i++) {
            sum_of_y  += data[i];
            sum_of_xy += i * data[i]; 
        }
        solve(n, sum_of_y, sum_of_xy);
    }
    return 0;
}

