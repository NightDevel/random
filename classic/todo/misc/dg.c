long long G[20], *g, a, k, c, z = 10, p, t, n;

Y(d)
{
	p = 1, t = n;
	while (d++, p *= z, t /= z) ;
	while (d--, p /= z) {
		c = n / p;
		for (t = 1; t < z; t++)
			g[t] += c * d * p / z + (t < c ? p : 0);
		g[c] += (n %= p) + 1;
	}
}

main()
{
	while (scanf("%lld%lld", &a, &n), k = a + n) {
		a = a > n ? n : a;
		g = G;
		n = a - 1;
		Y(0);
		g += z;
		n = k - a;
		Y(0);
		for (k = 1; k < z; g[k] = G[k] = 0, k++)
			printf("%lld ", g[k] - G[k]);
		puts("");
	}
}