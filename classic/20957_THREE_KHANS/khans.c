#include <stdio.h>
#include <string.h>
void print_bin(int a)
{
    char bin[100];
    int  l = sizeof(bin)-1;
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
    long long  T, nT;
    long long  n;
    double ravg, davg;

    long long  a, b, c;
    long long num, pos, one_set;
#define UMASK (0x3L) 

    
    davg = 0;
    ravg = 0;
    scanf("%lld", &T);
    nT = T;
    while (T--){
        scanf("%lld", &n);

        b   = n;
        num = n;
        one_set = 0;
        pos = 0;
        /* find bit pattern 01 and change it to 10
         * find number of bits(c) set to 1 before 10 pattern
         * set the lowest (c) bits to 1
         */
        while (num) {
            /* if bit pattern is of 01 then bingo */
            if ((num & UMASK) == 0x1) {
                num = (num & ~UMASK) | 0x2;
                break;
            }
            else if (num & 0x1) {
                one_set++;
            }
            pos++;
            num = num >> 1;
        } 
        if (num == 0)
            c = -1;
        else
            c = (num << pos)|((1<<one_set)-1);

        num = n;
        one_set = 0;
        pos = 0; 
        if ((num & (num+1)) == 0)
            a = -1;
        else {
            /* find the pattern 10
             * count the number of bits set to 1 (c)
             * move all the 1 bits adjacent to 10 pattern
             */
            while (num) {
                /* if bit pattern is of 10 then bingo */
                if ((num & UMASK) == 0x2) {
                    num = (num & ~UMASK) | 0x1;
                    break;
                }
                else if (num & 0x1) {
                    one_set++;
                }
                pos++;
                num = num >> 1;
            } 
            a = (num << pos)|(((1<<one_set)-1)<<(pos-one_set));
        }
        //printf("%ld %ld %ld\n", a, b, c); 
        if (b*b  == a * c)
            ravg++;
        davg += (c - a);
    }
    ravg = ravg/nT;
    davg = davg/nT;
    printf("%lf %lf\n", ravg, davg);
    return 0;
}
