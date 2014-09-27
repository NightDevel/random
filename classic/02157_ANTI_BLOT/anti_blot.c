#include <stdio.h>
#include <string.h>

void process(char *a, char *b, char *c)
{
    int ai, bi, ci;
    int m;
    int s;
    char *p;
    
    p = strstr(a, "machula"); 
    if (p == NULL) 
        ai = atoi(a);
    else
        s = 1;

    p = strstr(b, "machula"); 
    if (p == NULL) 
        bi = atoi(b);
    else
        s = 2;

    p = strstr(c, "machula");
    if (p == NULL) 
        ci = atoi(c);
    else
        s = 3;

    if (s == 1) {
        m = ci - bi;
        printf("%d + %d = %d\n", m, bi, ci); 
    }
    else if (s == 2) {
        m = ci - ai;
        printf("%d + %d = %d\n", ai, m, ci); 
    }
    else if (s == 3) {
        m = ai + bi;
        printf("%d + %d = %d\n", ai, bi, m); 
    }
}

int main()
{
    int t;
    char a[20], b[20], c[20];

    scanf("%d", &t);
    while (t--){
        scanf("%s + %s = %s", &a, &b, &c);
        process(a, b, c);
    }
    return 0;
}

