#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif

#define MAX_N 125250
int  lpos[MAX_N];

int  list[MAX_N];
int find_sum(int N, int sum)
{
	int s, value;
	int ts;
	lpos[0] = 0;
	for (s = 1; s <= sum; s++) {
		lpos[s] = -1;
		for (value = 1; value <= s &&  value <= N; value++) {
			ts = s - value; 
			if (ts >= 0 && lpos[ts] != -1 && ((value-1) >= lpos[ts]))  {
				lpos[s] = value;
				break;
			}
		} 
		dprintf("%d: %d\n", s, lpos[s]);
	}
	int i, k = 0;
	if (lpos[sum] != -1) {
		ts = sum;
		while (ts > 0) {
			list[k++] = lpos[ts];
			ts -= lpos[ts];
		}
		if (ts != 0) {
			dprintf("Something Wrong\n");
		}
	}
#if 0
	for (i = k-1; i >= 0; i--)
		printf("%d ", list[i]);
	printf("\n");
#endif
    char ch[2];
    ch[0] = '+';
    ch[1] = '-';
    int th = N*(N+1)/2;
	if (k > 0 && ((list[k-1] == 1) || (th == 2*sum))) {
        if ((th == 2*sum) && (list[k-1] != 1)) {
            ch[0] = '-';
            ch[1] = '+';
            k -= 1;
        }
        else {
            k -= 2;
        }
        printf("1");
        for (i = 2; i <= N; i++) {
            if (i == list[k]) {
                printf("%c", ch[0]);
                k--;
            }
            else
                printf("%c", ch[1]);
            printf("%d", i);
        }
        printf("\n");

        return 1;
    }
    return 0;
    
}

int main()
{
	int N, S;
	int a, b;
	int tsum, sum;
    int t;

//    scanf("%d", &t);
    t = 1;
    while (t--) {
        scanf("%d %d", &N, &S);
        tsum = (N*(N+1))/2;
        a = (S+tsum)/2;
        dprintf("tsum = %d, S = %d, a = %d\n", tsum, S, a);
        if ((abs(S) > tsum) || (2*a  != (S+tsum))) {
            printf("Impossible\n");
        }
        else if (!find_sum(N, a)) {
            printf("Impossible\n");
        }
    }
    return 0;
}
