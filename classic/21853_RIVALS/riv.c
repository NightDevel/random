#include <stdio.h>
#ifdef DEBUG
#define dprintf(...) do { printf(__VA_ARGS__); } while (0)
#else
#define dprintf(...) 
#endif

#define MAX_LEN 1000000+10
int G[MAX_LEN];
#define MODULUS 1000000007
int find_all_paths(int px, int py)
{
    int x, y;
    G[px] = 0;
    for (x = px-1; x >= 0; x--) 
        G[x] = 1; 

    for (y = py-1; y >= 0; y--) {
        G[px] = 1;
        dprintf("%d: ", y);
        for (x = px-1; x >= 0; x--) {
            G[x] = G[x] + G[x+1]; 
            if (G[x] >= MODULUS)   
                G[x] = G[x] % MODULUS;
            dprintf("%5d ", G[x]);
        }
        printf("\n");
    }
    return G[0];
}

int main()
{
    int t;
    int x, y;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &x, &y);
        printf("%d\n", find_all_paths(x, y));
    }
    return 0;
}

