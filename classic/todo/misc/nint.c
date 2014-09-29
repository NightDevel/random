#include <stdio.h>
int nbits(int a)
{
	int c = 0;
	while (a) {
		c += a&1? 1: 0;
		a = a>>1;
	}
	return c;
}

void print_bin(int a)
{
	char bin[20];
	int  l = 19;
	bin[l--] = '\0';
	while (a) {
		bin[l--] = a&1? '1': '0';
		a = a >> 1;
	}	
	l++;
	printf("%s\n", &bin[l]);
}

int main()
{
	int a;
	int n;
	int new;
	scanf("%d", &a);
	n = nbits(a);
	new = a;
	while (nbits(++new) != n);
	print_bin(a);
	printf("%d:", new);
	print_bin(new);
	new = a;	
	while (--new > 0 && nbits(new) != n);
	printf("%d:", new);
	print_bin(new);
}
