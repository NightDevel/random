#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES (100000+10)

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

int incoming[MAX_VERTICES];
int parent[MAX_VERTICES];
int queue[2*MAX_VERTICES];
int start, end;

void topological_sort()
{
    struct edge *e, *p;
    int v;
    int m;
    int boss;

    boss = 0;
    while (start != end) {
        m = queue[start++];
        parent[m] = boss; 
        e = hdr[m].first;
        dprintf("cur node : %d\n", m);
        while (e) {
            v = e->vertex;
            p = e;
            e = e->next;
            free(p);
            if (--incoming[v] == 0) {
                dprintf("parent of %d is %d\n", v, m);
                queue[end++] = v;
            }
        }
        boss = m;
    }
}


int main()
{
    int N;
    int k;
    int d;
    int scnt, i, j;
    scanf("%d %d", &N, &k);
    for (i = 1; i <= k; i++) {
       scanf("%d", &scnt); 
       for (j = 1; j <= scnt; j++) {
            scanf("%d", &d); 
            insert_edge(i, d);
            incoming[d]++;
            dprintf("%d to incoming[%d] : %d\n", i, d, incoming[d]);
        }
    }
    start = end = 0;
    for (j = 1; j <= N; j++) 
        if (incoming[j] == 0)
            queue[end++] = j;

    topological_sort();
    for (i = 1; i <= N; i++)
        printf("%d\n", parent[i]);
    return 0;
}

