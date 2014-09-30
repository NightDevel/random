#include <stdio.h>
int parent[10000+10];
int get_parent(int n)
{
	while (n != parent[n])
		n = parent[n];
	return n;
}
int main()
{
	int nodecnt, edgecnt;
	int n1, n2;
	int node;
	int i, p;
	int n1_parent;
	int n2_parent;

	scanf("%d %d", &nodecnt, &edgecnt);
	for (node = 0; node <= nodecnt; node++)
		parent[node] = node;

    while (edgecnt--) {
		scanf("%d %d", &n1, &n2); 
		n1_parent = get_parent(n1);
		n2_parent = get_parent(n2);
		if (n1_parent == n2_parent) {
			printf("NO\n");
			return 0;
		}
		
		parent[n2] = n1_parent;
    }

	p = get_parent(1);
	for (node = 2; node <= nodecnt; node++) {
		if (p != get_parent(node)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
    return 0;
}

