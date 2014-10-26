#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_VERTICES (1000+10)
#ifdef DEBUG
#define dprintf(fmt, ...) do { fprintf(stderr, fmt, __VA_ARGS__); } while (0)
#else
#define dprintf(fmt, ...) 
#endif


char visited[MAX_VERTICES];
int parent[MAX_VERTICES];
int level[MAX_VERTICES];
int process[MAX_VERTICES];
int graph[MAX_VERTICES][MAX_VERTICES];
int max_nodes;

static inline max(int a, int b)
{
    return (a > b ? a: b);
}

int preprocess_tree(int vertex, int d)
{
    int maxd;
    int q;

    maxd = d;
    level[vertex] = d;
    for (q = 1; q <= max_nodes; q++) {
        if (graph[vertex][q]) {
            if (!visited[q]) {
                visited[q] = 1;
                parent[q] = vertex;
                maxd = max(maxd, preprocess_tree(q, d+1));
            }
        }
    }
    return maxd;
}

void find_ancestors(int vertex, int nr)
{
    int q;
    if (level[vertex] < nr) {
        process[vertex] = 1;
    }
    else {
        if ((level[vertex] % nr) == 0) 
            process[vertex] = parent[vertex];
        else 
            process[vertex] = process[parent[vertex]];
    }
    for (q = 1; q <= max_nodes; q++) {
        if (graph[vertex][q]) {
            if (!visited[q]) {
                visited[q] = 1;
                find_ancestors(q, nr);
            }
        }
    }
}
int LCA(int x, int y)
{
    while (process[x] != process[y]) {
        if (level[x] > level[y])
            x = process[x];
        else
            y = process[y];
    }

    while (x != y) {
        if (level[x] > level[y])
            x = parent[x];
        else
            y = parent[y];
    }        
    return x;
}

int main()
{
    int i, j, q, N;
    int d, edges;
    int index;
    int t;

    scanf("%d", &t);
    index = 1;
    while (index <= t) {
        scanf("%d", &N);
        max_nodes = N;

        for (i = 1; i <= N; i++) {
            scanf("%d", &edges);
            for (j = 1; j <= edges; j++) {
                scanf("%d", &d);
                graph[i][d] = 1;
                graph[d][i] = 1;
            }
        }
        visited[1] = 1;
        int H = preprocess_tree(1, 0);
        if (H > 0) {
            memset(visited, 0, sizeof(visited));
            visited[1] = 1;
            find_ancestors(1, (int)sqrt(H));
        }
        else {
            process[1] = 1;
        }

        int x, y;
        scanf("%d", &q);
        printf("Case %d:\n", index); 
        for (i = 1; i <= q; i++) {
            scanf("%d %d", &x, &y);
            printf("%d\n", LCA(x,y));
        }
        index++;
        memset(parent , 0, sizeof(parent));
        memset(level  , 0, sizeof(level));
        memset(process, 0, sizeof(process));
        memset(graph  , 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}
