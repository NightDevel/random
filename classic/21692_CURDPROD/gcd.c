#include <stdio.h>

long long num[10000+5];
long long gcd(long long  a, long long b)
{
	if (b == 0)
		return a;

	return gcd(b, a%b);
}

int get_array_gcd(int arr[], int n)
{
	int i, m;
	int g;
	g = arr[0];
	for (i = 1; i < m; i++) 
		g = gcd(g, arr[i]);
	return g;
}

long long get_array_lcm(long long arr[], int n)
{

	int i;
	long long l;

	if (n == 1)
		return arr[0];

	l = (arr[0] * arr[1])/gcd(arr[0], arr[1]);
	for (i = 2; i < n; i++) { 
		l = (l * arr[i])/gcd(l, arr[i]);
		printf("%lld\n", l);
	}
	return l;
}

long long get_ratio(long long arr[], int n, int T)
{
	long long l;
	long long s;
	long long d;
	long double f;
	int i, min;

	l   = get_array_lcm(arr, n);
	printf("lcm = %lld\n", l);
	s   = 0;
	min = 1000000001;
	for (i = 0; i < n; i++) {
		s += l/arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	d = l/min;
	printf("%d %d %d\n", d, s, T);
	printf("%lld\n", ((d*T+s-1)/s)*min);
}


int main()
{
	int t;
	int n;
	int T;
	int i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &T);
		for (i = 0; i < n; i++) {
			scanf("%lld", &num[i]);
		}
		get_ratio(num, n, T);
	}
				
	return 0;
}

	
