#include <stdio.h>

long long arr[10000+10];
long long get_total_jobs(long long  arr[], int n, long long v)
{
	int i;
	long long sum = 0;

	for (i = 0; i < n; i++)
		sum += v/arr[i];

	return sum;
}

long long get_time(long long arr[], int n, long long min, long long T)
{
	long long low, mid, high;
	long long tjobs;
	
	low  = 0;
	high = min * T;
	while (low < high) {
	    mid  = (low+high)/2;
		tjobs = get_total_jobs(arr, n, mid);

		if (tjobs < T)
			low = mid+1;
		else
		if (tjobs >= T)
		    high = mid;
	}

	return (high);
}

int main()
{
	int t;
	int i;
	long long n;
	long long T;
	long long min;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &n, &T);
	    min = 1000000001;
		for (i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
			if (min > arr[i])
				min = arr[i];
		}
		if (n == 1) 
			printf("%lld\n", arr[0] * T);
		else
			printf("%lld\n", get_time(arr, n, min, T));
	}
				
	return 0;
}
