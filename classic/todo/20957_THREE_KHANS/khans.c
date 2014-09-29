#include <stdio.h>
#include <string.h>
char *int_to_bin(int n, char *e)
{
    while (n) {
        *e-- = n%2 + '0';
         n = n/2;
    }
    return e+1;
}
void print_bin(int a)
{
	char bin[20];
	int  l = 19;
	bin[l--] = '\0';
	while (a) {
		bin[l--] = a&1? '1': '0';
		a = a >> 1;
	}	
	l++;
	printf("%s\n", &bin[l]);
}

void process(int n)
{
    char am[64];
    char sh[64];
    char sl[64];
    char len;
    char *amr;
    char *sal;
    char *sha;

    int a, b, c;

    memset(am, '0', sizeof(am));
    am[63] = '\0';
    amr = int_to_bin(n, am + 62); 
    len = strlen(amr);;
    printf("%s\n", amr);
    memcpy(sh, am, 64);
    memcpy(sl, am, 64);
    /* sal next immediate number which equal number of 1 
     * find the sequence 
     * 0 1 in the number and set it to 1 0 
     */
    char *e;
    sal = (sl + 63 - len);
    e = sl + 62;
	int c1  = 0;
	int pos = 0;;
    while (1) {
		pos++;
        if (e[0] == '1' && e[-1] == '0'){
            e[0] = '0'; e[-1] = '1';
            e--;
            break;
        }
		if (e[0] == '1')
			c1 = c1<<1|1;
        e--;
    }
	/* shift all 1 to the right */
	if (e < sal) {
		c = 1<<pos|c1; 
	}
	else {
		c = strtol(sal, NULL, 2);
	}
	c1  = 0;
	pos = 0;
    sha = (sh + 63 - len);
    e = sh + 62; 
    while (1) {
		pos++;
        if (e[0] == '0' && e[-1] == '1'){
            e[0] = '1'; e[-1] = '0';
            e--;
            break;
        }
		if (e[0] == '1')
			c1 = c1<<1|1;
        e--;
    }
 	/* shift all 1 to the left */
	if (e == sh) {
		a = 1<<pos|c1; 
	}
	else {
		a = strtol(sha, NULL, 2);
	}
    b = strtol(amr, NULL, 2);
    printf("%d %d %d\n", a, b, c);
	print_bin(a);
	print_bin(b);
	print_bin(c);
//    printf("%s", p);

}

int main()
{
    int T;
    scanf("%d", &T);
    unsigned int n;
    while (T--){
        scanf("%d", &n);
		if (((n+1) & n) == 0)
			printf("no\n");
		else
			process(n);
    }
    return 0;
}

