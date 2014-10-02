#include<stdio.h>
typedef long long l;
l G[20], *g, a, b, k, c;
void cd(l n)
{
	l p = 1, t = n, d = 0;
	while (t) {
		d++;
		t = t / 10;
		p *= 10;
	}
	while (d--, p = p / 10) {
		c = n / p;
		for (t = 1; t <= 9; t++)
			g[t] += c * d * p / 10 + (t < c ? p : 0);
		g[c] += (n = n % p) + 1;
	}
}

int main()
{
	while (scanf("%lld%lld", &a, &b), k = a + b) {
		a = a > b ? b : a;
		g = G;
		cd(a - 1);
		g += 10;
		cd(k - a);
		for (k = 1; k < 10; k++) {
			printf("%lld ", g[k] - G[k]);
			G[k] = g[k] = 0;
		}
		puts("");
	}
	return 0;
}
