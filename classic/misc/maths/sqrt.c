#include <stdio.h>
unsigned long isqrt(unsigned long x)
{
	register unsigned long op, res, one;

	op = x;
	res = 0;

	/* "one" starts at the highest power of four <= than the argument. */
	one = 1 << 30;  /* second-to-top bit set */
	while (one > op) one >>= 2;

		while (one != 0) {
		if(op >= res + one) {
			op -= res + one;
			res += one << 1;  // <-- faster than 2 * one
		}
		res >>= 1;
		one >>= 2;
	}
	return res;
}

typedef unsigned char       uint8;
typedef unsigned short int  uint16;
typedef unsigned long int   uint32;


uint32  // OR uint16 OR uint8
isqrt32 (uint32 n) 
	// OR isqrt16 ( uint16 n ) OR  isqrt8 ( uint8 n ) - respectively [ OR overloaded as isqrt (uint?? n) in C++ ]
{
	register uint32 // OR register uint16 OR register uint8 - respectively
		root, remainder, place;

	root = 0;
	remainder = n;
	place = 0x40000000; // OR place = 0x4000; OR place = 0x40; - respectively

	while (place > remainder)
		place = place >> 2;

	while (place)
	{
		if (remainder >= root + place)
		{
			remainder = remainder - root - place;
			root = root + (place << 1);
		}
		root = root >> 1;
		place = place >> 2;
	}
	return root;
}

#include <math.h>
int main()
{
	int i;
	for (i = 1; i < 1000000000; i++)
		//printf("%d\n", (int)sqrt(i));
		(int)sqrt(i);
		
}
