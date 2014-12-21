#



#else
#define dprintf(...) 
#endif
#define MAX_N 21

char INP[MAX_N][MAX_N];
long long  D[(1<<(MAX_N-1))+20];

/* base logic:
 * say we want to calculate max possibe assignment
 * such that each of A B C will choose different positions
 *
 * three variables
 *  VALUES 
 *   1   2   3
 ---------------
 |A| 1 | 0 | 1 |
 ---------------
 |B| 2 | 1 | 0 |
 ---------------
 |C| 1 | 1 | 1 |
 ---------------
 * 
 *to find max combination, we have do this
  find: 
  1 2 3
  A B C = 1 + 1 + 1 = 3
  A C B = 1 + 1 + 0 = 2
  B A C = 2 + 0 + 1 = 3
  B C A = 2 + 1 + 1 = 4
  C A B = 1 + 0 + 0 = 2
  C B A = 1 + 1 + 1 = 3
  find the maxium of the above which is B C A


1  (1, 2, 4, 3)
2  (1, 3, 2, 4)
3  (1, 3, 4, 2)
4  (1, 4, 2, 3)
5  (1, 4, 3, 2)
6  (2, 1, 3, 4)
7  (2, 1, 4, 3)
8  (2, 3, 1, 4)
9  (2, 3, 4, 1)
10 (2, 4, 1, 3)
11 (2, 4, 3, 1)
12 (3, 1, 2, 4)
13 (3, 1, 4, 2)
14 (3, 2, 1, 4)
15 (3, 2, 4, 1)
16 (3, 4, 1, 2)
17 (3, 4, 2, 1)
18 (4, 1, 2, 3)
19 (4, 1, 3, 2)
20 (4, 2, 1, 3)
21 (4, 2, 3, 1)
22 (4, 3, 1, 2)
23 (4, 3, 2, 1)





lets calculate this way:
bits = 4
(1<<N)-1 = 15


D[13(1101): 3] = D[15(1111): 3: 1] +  = 1 
D[12(1100): 2] = D[13(1101): 2: 0] + D[14(1110): 2: 1] +  = 2 
D[11(1011): 3] = D[15(1111): 3: 2] +  = 1 
D[10(1010): 2] = D[11(1011): 2: 0] + D[14(1110): 2: 2] +  = 2 
D[09(1001): 2] = D[11(1011): 2: 1] + D[13(1101): 2: 2] +  = 2 
D[08(1000): 1] = D[09(1001): 1: 0] + D[10(1010): 1: 1] + D[12(1100): 1: 2] +  = 6 
D[07( 111): 3] = D[15(1111): 3: 3] +  = 1 
D[06( 110): 2] = D[07( 111): 2: 0] + D[14(1110): 2: 3] +  = 2 
D[05( 101): 2] = D[07( 111): 2: 1] + D[13(1101): 2: 3] +  = 2 
D[04( 100): 1] = D[05( 101): 1: 0] + D[06( 110): 1: 1] + D[12(1100): 1: 3] +  = 6 
D[03(  11): 2] = D[07( 111): 2: 2] + D[11(1011): 2: 3] +  = 2 
D[02(  10): 1] = D[03(  11): 1: 0] + D[06( 110): 1: 2] + D[10(1010): 1: 3] +  = 6 
D[01(   1): 1] = D[03(  11): 1: 1] + D[05( 101): 1: 2] + D[09(1001): 1: 3] +  = 6 
D[00(    ): 0] = D[01(   1): 0: 0] + D[02(  10): 0: 1] + D[04( 100): 0: 2] + D[08(1000): 0: 3] +  = 24 

assignment matrix
1
4
1 1 1 1
1 0 1 1
1 1 0 1
0 1 1 1

D[n(binary rep): number of bits 1 in n] = number of ways to reach from current n to full n
in this case D[14(1110): 3] is to say, we have already filled the 3 bits, now have to fill the last bit
                                       and last bit can reach only 1, 2, 3 but not zero
D[14] is zero
D[13] is 1 because D[13: arr[3][1]] 
D[11] is 1 because D[11: arr[3][2]]
D[7]  is 1 because D[7: arr[3][3]]
D[12] is D[13 = D[12 with Arr[2][0]]] + D[14 = D[13 with arr[2][1]]
D[12] is to say D[12 (1100)] we have filled 2 bits and have to fill 2 other lower bits, arr[2][0] takes to D[13] which
we already know on how to reach D[15] from there and so on

D[14(1110): 3] = D[15(1111): 3: 0] +  = 0  
D[13(1101): 3] = D[15(1111): 3: 1] +  = 1  
D[12(1100): 2] = D[13(1101): 2: 0] + D[14(1110): 2: 1] +  = 1 
D[11(1011): 3] = D[15(1111): 3: 2] +  = 1 
D[10(1010): 2] = D[11(1011): 2: 0] + D[14(1110): 2: 2] +  = 1 
D[09(1001): 2] = D[11(1011): 2: 1] + D[13(1101): 2: 2] +  = 1 
D[08(1000): 1] = D[09(1001): 1: 0] + D[10(1010): 1: 1] + D[12(1100): 1: 2] +  = 2 
D[07( 111): 3] = D[15(1111): 3: 3] +  = 1 
D[06( 110): 2] = D[07( 111): 2: 0] + D[14(1110): 2: 3] +  = 1 
D[05( 101): 2] = D[07( 111): 2: 1] + D[13(1101): 2: 3] +  = 2 
D[04( 100): 1] = D[05( 101): 1: 0] + D[06( 110): 1: 1] + D[12(1100): 1: 3] +  = 3 
D[03(  11): 2] = D[07( 111): 2: 2] + D[11(1011): 2: 3] +  = 1 
D[02(  10): 1] = D[03(  11): 1: 0] + D[06( 110): 1: 2] + D[10(1010): 1: 3] +  = 3 
D[01(   1): 1] = D[03(  11): 1: 1] + D[05( 101): 1: 2] + D[09(1001): 1: 3] +  = 3 
D[00(    ): 0] = D[01(   1): 0: 0] + D[02(  10): 0: 1] + D[04( 100): 0: 2] + D[08(1000): 0: 3] +  = 11 

Important fact is: every number depends on previous number for calculation
eg: D[06] = D[07] + D[14] etc.
finally D[0] will give the result

*/
char * printbits(int n)
{
    static char bistr[100];
    int l = 99;
    bistr[l] = '\0';
    while (n) {
        bistr[--l] = n % 2 + '0';
        
    }
    return &bistr[l];
}

int main()
{
    int t;
    int N;
    int i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                scanf("%d", &INP[i][j]);

        int mask, bit, bcount;
        int max = (1<<N) - 1;
        memset(D, 0, sizeof(D));
        D[max] = 1;
        for (mask = max-1; mask >= 0; mask--) {
            bcount = __builtin_popcount(mask);
            dprintf("D[%02d(%4s): %d] = ", mask, printbits(mask), bcount);
            for (bit = 0; bit < N; bit++) {
#if DEBUG
                if (!(mask & (1 << bit)))
                    dprintf("D[%02d(%4s): %d: %d] + ", mask|(1<<bit), printbits(mask|(1<<bit)), bcount, bit); 
#endif
                if (INP[bcount][bit] && !(mask & (1 << bit)))
                    D[mask] += D[mask| (1<<bit)];
            }
            dprintf(" = %d \n", D[mask]);
        }
        printf("%lld\n", D[0]);
    }
}
