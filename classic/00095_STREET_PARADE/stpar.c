#include <stdio.h>

#define MAX_TRUCKS 1010
void print_order(int *trucks, int n)
{
	int stack[MAX_TRUCKS];
	int si = -1;
	int ti = 0;
	int k  = 1;


	while (ti < n) {
		if (k == trucks[ti]) {
			ti++;
			k++;
		}
		else if (si >= 0 && k == stack[si]) {
			si--;
			k++;
		}
		else
			stack[++si] = trucks[ti++];
	}

	while (si >= 0 && (k == stack[si])) {
		k++;
		si--;
	}

	if (si == -1)
		printf("yes\n");
	else
		printf("no\n");
}

int main()
{
	int trucks[MAX_TRUCKS];
    int T, i;
    while (1){
		scanf("%d", &T);
		if (T == 0)
			break;
		for (i = 0; i < T; i++)
			scanf("%d", &trucks[i]);
		print_order(trucks, T);
    }
    return 0;
}

