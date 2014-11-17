#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif

#define MAX_N 501
#define MAX_S 125250
//char arr[MAX_N * MAX_S];
int  lpos[MAX_N];


void find_sum(int N, int sum)
{
    int s, value;
    lpos[0] = 0;
    for (s = 1; s <= sum; s++)
        lpos[s] = -1;
        for (value = 1; value <= s; value++) {
            ts = s - value; 
            if (ts >= 0 && lpos[ts] != -1 && ((value-1) >= lpos[ts]))  {
                lpos[s] = value;
                break;
            }
        } 
    }
}

int main()
{
    int N, S;
    int a, b;
    int tsum, sum;
    scanf("%d %d", &N, &S);
    tsum = (N*(N+1))/2;
    a = (S+tsum)/2;
    b = a - S;
    sum = a > b? b: a
}

