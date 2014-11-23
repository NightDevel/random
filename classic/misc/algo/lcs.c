
#include <stdio.h>

#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif
#include <string.h>

int max(int p, int q)
{
    return (p > q ? p:q);
}

int lcs(char *s1, char *s2)
{
    if (*s1 == 0|| *s2 == 0)
        return 0;

    if (*s1 == *s2) 
        return lcs(s1+1, s2+1)+1;
    
    return max(lcs(s1+1, s2), lcs(s1, s2+1));
}

#define MAX_SIZE 200
int arr[MAX_SIZE][MAX_SIZE];
int lcs_dp(char *s1, char *s2)
{
    int p, q;

    p = strlen(s1);
    q = strlen(s2);

    int i, j;
    for (i = 0; i < max(p, q); i++)  {
        arr[0][i] = 0;
        arr[i][0] = 0;
    }
    s1--, s2--;
    for (i = 1; i <= p; i++) {
        for (j = 1; j <= q; j++) {
            if (s1[i] == s2[j]) 
                arr[i][j] = 1 + arr[i-1][j-1];
            else
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            dprintf("%d %d: %d\n", i, j, arr[i][j]);
        }
    }
    return arr[p][q];
}

int darr[2][MAX_SIZE];
int lcs_dp_1(char *s1, char *s2)
{
    int p, q;

    p = strlen(s1);
    q = strlen(s2);

    int i, j;
    for (i = 0; i <= q; i++)  
        darr[0][i] = 0;
    darr[1][0] = 0;
    s1--, s2--;

    int l = 1, m;
    for (i = 1; i <= p; i++) {
        l = l^1;
        m = l^1;
        for (j = 1; j <= q; j++) {
            if (s1[i] == s2[j]) 
                darr[l][j] = 1 + darr[m][j-1];
            else
                darr[l][j] = max(darr[m][j], darr[l][j-1]);
            dprintf("%d %d: %d\n", i, j, darr[l][j]);
        }
    }
    return darr[l][q];
}


int main()
{
    char s1[MAX_SIZE];
    char s2[MAX_SIZE];

    scanf("%s %s", s1, s2);

    printf("%d\n", lcs(s1, s2));
    printf("%d\n", lcs_dp(s1, s2));
    printf("%d\n", lcs_dp_1(s1, s2));

    return 0;
}

