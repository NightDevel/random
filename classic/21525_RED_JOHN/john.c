#include <stdio.h>
#include <math.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif


int primes[35000];
int min_pos  = 0;
int max_pos = 0;
void generate_primes(int max)
{
    int i, l, s, n;
    /* two is prime */
    l = 0;
    primes[l++] = 2;
    primes[l++] = 3;
    primes[l++] = 5;
    primes[l++] = 7;
    /* skip even numbers */
    for (n = 11; n <= max; n += 2) {
        s = sqrt(n) + 1;
        for (i = 3; i <= s; i += 2) {
            if ((n%i) == 0) {
                break;
            }
        }
        if (n%i != 0)
            primes[l++] = n;
    }
    max_pos = l-1;
    dprintf("last prime :pos = %d, %d\n", max_pos, primes[max_pos]);
}

int find_nth(int *arr, int size, int n)
{
    int m, l, h;

    l = 0;
    h = size - 1;

    if (n == 1)
        return 0;

    while (l <= h) {
        m = (l+h)/2;
        if ((arr[m] == n) || (arr[m] < n && n < arr[m+1]))
            return m+1;

        if (n > arr[m]) 
            l = m + 1;
        else
            h = m - 1;
    }
}




/* Generate number of ways to fill up the wall of size 4xN
 * with bricks of size 4x1 and 1x4
 * Main idea is :
 *  1. If we use 4x1 size brick, then length remaining is N-1, so find no 
 *  of ways to fill up N-1 wall.
 *  2. If we use 1x4 bricks, we have to use 4 of that type to fill height of 4
 *  inturn they will use width of 4, remaining length is N-4, so find no 
 *  of ways to fill up N-4 wall.
 *  W[N] = W[N-1] + W[N-4]
 */

#define MAX_WALL_LENGTH 42
int wall[MAX_WALL_LENGTH];
int find_ways(int range)
{
    wall[0] = 0;
    wall[1] = 1;
    wall[2] = 1;
    wall[3] = 1;
    wall[4] = 2;
   
    int i;
    for (i = 5; i <= range; i++)
       wall[i] = wall[i-1] + wall[i-4]; 
    dprintf("final wall ways = %d\n", wall[MAX_WALL_LENGTH]);
    return wall[range];
}




int main()
{
    int t;
    int N;
    int r;
    r = find_ways(MAX_WALL_LENGTH);
    generate_primes(r);
    scanf("%d", &t);
    while (t--){
        scanf("%d", &N);
        dprintf("%d\n", wall[N]);
        printf("%d\n", find_nth(primes, max_pos+1, wall[N]));
//        printf("%d\n", find_nth(primes, max_pos+1, N));
    }
    return 0;
}

