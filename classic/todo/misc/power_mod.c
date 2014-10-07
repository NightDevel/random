#include <stdio.h>
long long power_mod(long long a, int p, int m)
{   
	if (p == 1)
		return a%m;

    if (p == 0)
        return 1;

	if (p%2 == 0)
		return power_mod((a*a)%m, p/2, m)%m;
    else
    	return (a*power_mod(a, p-1, m))%m;
}

long long power_mod1(long long a, int p, int m)
{
    long long c = 1;
    while (p > 1) {
        if (p%2 == 0) {
            a = (a*a)%m;
            p = p/2;
        }
        else {
            c = (c * a)%m;
            p--;
        }
    }
    return (c*a)%m;
}

int main(int argc, char *argv[])
{
	long long a;
	int p;
	int m;
	a = atoi(argv[1]);
	p = atoi(argv[2]);
	m = atoi(argv[3]);
    printf("%lld\n", power_mod(a, p, m));
	printf("%lld\n", power_mod1(a, p, m));

}

