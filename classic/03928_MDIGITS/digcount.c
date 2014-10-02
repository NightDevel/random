#include <stdio.h>
#include <string.h>
#include <math.h>
long long arr[11];
void calculate_digits(long long num)
{
    int  total_digits;
    long long tzeros;
    long long tpower;
    long long tnum;
    long long upper_digit, rem_digits;
    long long digit_count, total_digit_count;
    int i;
    /* 
     * Lets say  n is 4123459
     * Lets try to solve the problem in incremental manner.
     * - find the number of digits in 4000000
     * - find the number of digits in  123459
     * - find the number of digits in   23459
     * - find the number of digits in    3459
     * - find the number of digits in     459
     * - find the number of digits in      59
     * - find the number of digits in      9
     * Rule 1: 
     * =======
     * Let's ignore the lower digits and concentrate on the MSB now
     * So n is 4000000
     *
     * let make n as 1000000
     * so 6 lsb places, which can be placed with 0-9 digits
     * so total numers count            = 10*10*10*10*10*10 = 10^6
     * so total digits(10 digits)       = (each number is of size 6 digit) = 6 * 10^6
     * for each digit                   = (6*10^6)/10 = 6 * 10^5
     * Generally for d digit number, (d-1)*10^(d-2) individual digits
     * are availble
     *
     * Now for 4000000, each digit count will be 4 * (d-1) * 10^(d-2) 
     * For     r000000, each digit count will be r * (d-1) * 10^(d-2) 
     * Rule 2:
     * ======
     * Continue with 4000000 as number
     * if we write down 4000000 as
     *                  3000000
     *                  2000000
     *                  1000000
     *   1,2,3 is repeated 10^(d)  but not 4 as it has only (123459) digits are availble
     *  
     *  So, for digits 1 to (d-1) add count of 10^d
     *  Rule 3:
     *  ======
     *  For MSB digit add all the lower numbers i.e 123456 plus own digit
     *  Looking at other way, how many number will we have with 4 in MSB = 123456 + 1
     *
     * 
     *  Rule 4:
     *  =======
     *  Handle zeros
     *  Because of Rule 1, we assume all numbers are equally likely
     *  4123459 has numbers below 1000000, 
     *  so all 6 digits number generation includes involvement of 0.
     *  so we have to remove 0 where it's in leading position.
     *
     *   0xxxxx = 10^5 + 4 zero digits
     *    0xxxx = 10^4 + 3 zero digits 
     *     0xxx = 10^3 + 2 zero digits
     *      0xx = 10^2 + 1 zero digits
     *       0x = 10^1 + 0 digits
     *        0 = 10^0
     *  for d digits number we have to do d times
     *  and subtract from total zeros's count
     */
    total_digits = 0;
    tpower  = 1;
    tnum    = num;
    tzeros  = 0;
    while (tnum) {
        total_digits++;
        tnum = tnum/10;
        tpower *= 10;
        tzeros = 10*tzeros + 1;
    }
    tpower = tpower/10; // 10^total_digits  
    
    memset(arr, 0, sizeof(arr)); 
    while (tpower) {
        /* Rule 1*/
        upper_digit = num/tpower;
        rem_digits  = num%tpower;
        digit_count = (pow(10, total_digits-2));
   
        total_digit_count = upper_digit * (total_digits-1) * digit_count;

        if (total_digit_count) {
            for (i = 0; i <= 9; i++)
                arr[i] += total_digit_count;
        }
        /*Rule 2*/
        for (i = 0; i < upper_digit; i++)
            arr[i] += tpower;

        /*Rule 3*/ 
        arr[upper_digit] += rem_digits + 1; 

        num    = num%tpower;
        tpower = tpower/10;      
        total_digits--;
    }
    /* Rule 4 */
    arr[0] -= tzeros;
//    for (i = 0; i < 10; i++) {
//        printf("%lld ", arr[i]);
//    }
//    printf("\n");
}

void calculate_range(long long a, long long b)
{
    long long tarr[11];
    int i;
    calculate_digits(a-1);
    memcpy(tarr, arr, sizeof(arr));
    calculate_digits(b);
    for (i = 0; i < 10; i++) {
        printf("%lld ", (arr[i]-tarr[i]));
    }
    printf("\n");

}
int main()
{
	long long a, b, i, k;
	while (1) {
		scanf("%lld%lld", &a, &b);
		if (a == 0 && b == 0)
			break;
		k = a;
		if (a > b) {
			a = b;
			b = k;
		}
        calculate_range(a, b);
#if 1
        memset(arr, 0, sizeof(arr));
		for (i = a; i <= b; i++) {
			k = i;
			while (k) {
				arr[k % 10]++;
				k = k / 10;
			}
		}
    	for (i = 0; i < 10; i++) {
			printf("%lld ", arr[i]);
		};
        printf("\n");

#endif
    }
    return 0;
}
