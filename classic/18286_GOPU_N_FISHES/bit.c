#include <stdio.h>

const int arr[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

int D[65536];
void enumerate(unsigned int mask)
{
	unsigned int tmask = mask;
	int bitset;
	if (D[mask])
		return;
//	if (!tmask)
//		printf("\n");
	while (tmask) {
		bitset = 31 - __builtin_clz(tmask);
//		printf("mask: %-3d, bit = %d \n", mask, bitset);
		tmask = tmask & ~arr[bitset];
		enumerate(mask & ~arr[bitset]);
	}
	D[mask] = 1;
}


int main()
{
	unsigned int n;
	int bitset = 0;
	while (~scanf("%d", &n)) {
		enumerate(n);
	}
	return 0;
}

