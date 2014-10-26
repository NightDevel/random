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


/* using adjacency list */
struct edge {
    int vertex;
    struct edge *next;
};

typedef struct{
    struct edge *first;
    struct edge *last;
    int count;
}hdr_edge;

hdr_edge hdr[MAX_VERTICES];

/* insert this edge in hdr list */ 
void insert_edge(int s, int d)
{
    struct edge *tmp;
    tmp = (struct edge *)malloc(sizeof(struct edge));
    tmp->vertex = d;
    tmp->next  = NULL;

    hdr_edge *h = &hdr[s];
    if (h->first == NULL) {
        h->first = h->last = tmp;
        h->count = 1;
    }
    else {
        h->last->next = tmp;
        h->last = tmp;
        h->count++;
    }
}

char visited[MAX_VERTICES];
int parent[MAX_VERTICES];
int level[MAX_VERTICES];
int process[MAX_VERTICES];
static inline max(int a, int b)
{
    return (a > b ? a: b);
}

int preprocess_tree(int vertex, int d)
{
    struct edge *e;
    int maxd;

    maxd = d;
    level[vertex] = d;
    e = hdr[vertex].first;
    while (e) {
        if (!visited[e->vertex]) {
            visited[e->vertex] = 1;
            parent[e->vertex] = vertex;
            maxd = max(maxd, preprocess_tree(e->vertex, d+1));
        }
        e = e->next;
    }
    return maxd;
}

void find_ancestors(int vertex, int nr)
{
    struct edge *e;
    if (level[vertex] < nr) {
        process[vertex] = 1;
    }
    else {
        if ((level[vertex] % nr) == 0) 
            process[vertex] = parent[vertex];
        else 
            process[vertex] = process[parent[vertex]];
    }
    for (e = hdr[vertex].first; e; e = e->next) {
        if (!visited[e->vertex]) {
            visited[e->vertex] = 1;
            find_ancestors(e->vertex, nr);
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
        for (i = 1; i <= N; i++) {
            scanf("%d", &edges);
            for (j = 1; j <= edges; j++) {
                scanf("%d", &d);
                insert_edge(i, d);
                insert_edge(d, i);
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
        memset(visited, 0, sizeof(visited));
        for (i = 1; i <= N; i++) {
            struct edge *e, *p;
            p = hdr[i].first;
            while (p) { 
                e = p;
                p = p->next;
                free(e);
            }
            hdr[i].first = NULL;
        }
    }
    return 0;
}

