#include <stdio.h>
#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif

long long lvl_start[300];
int max_limit;
int build_tree(int m)
{
	long long max_sum;
	long long lvl;
	int k;
	max_sum = (1<<31-1);
	k		= 0;
	lvl_start[k++]  = 1;
	for (lvl = 1; lvl_start[k-1] <= max_sum; k++, lvl *= m) {
		lvl_start[k] = lvl_start[k-1]+lvl; 
		printf("%ld %ld\n", max_sum, lvl_start[k]);
	}
	if (lvl_start[k-1] > max_sum)
		k--;
	max_limit = k;
	printf("\n");
}

int find_lvl(int n)
{	
	int l = 0;
	while (lvl_start[l++] <= n);
	return l-2;
}

int find_parent(int n1, int n2, int m)
{
	int n1_lvl;
	int n2_lvl;
    int t;
    t = n2;
    if (n1 > n2) {
        n2 = n1;
        n1 = t;
    }
    n1_lvl = find_lvl(n1);
	n2_lvl = find_lvl(n2);

    dprintf("n1 lvl = %d\nn2 lvl = %d\n", n1_lvl, n2_lvl);
    n1 -= lvl_start[n1_lvl];
    n2 -= lvl_start[n2_lvl];
    while (n1_lvl < n2_lvl) {
        n2 = n2/m; 
        n2_lvl--;
        dprintf("n2 = %d\n", n2+lvl_start[n2_lvl]);
    }
    while (n1 != n2) {
        n1 /=m;
        n2 /=m;
        n1_lvl--;
        dprintf("n1 = %d\n", n1+lvl_start[n1_lvl]);
        dprintf("n2 = %d\n", n2+lvl_start[n1_lvl]);
    }
	printf("%d %d\n", n1_lvl, n1 + lvl_start[n1_lvl]);
    return n1 + lvl_start[n1_lvl];
}

int main()
{
    int t;
	int m;
	int n1, n2;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d %d", &m, &n1, &n2);
	    build_tree(m);
		find_parent(n1, n2, m);
	}
    return 0;
}

