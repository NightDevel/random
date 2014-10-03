long long G[20], *g, a, z = 10, k, c, t, n;
Y(d)
{
	a = 1, t = n;
	while (d++, a *= z, t /= z) ;
	while (d--, a /= z) {
		c = n / a;
		t = 9;
		while (g[t] += c * d * a / z + (t < c) * a, --t) ;
		n %= a;
		g[c] += n + 1;
	}
}

main()
{
	while (scanf("%lld%lld", &a, &k), a > k ? a ^= k ^= a ^= k : a) {
		g = G;
		n = a - 1;
		Y(0);
		g += z;
		n = k;
		Y(0);
		k = 1;
		while (printf("%lld ", *++g - G[k]), *g = G[k] = 0, k++ < 9) ;
		puts("");
	}
}
