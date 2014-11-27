#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES (100000+100)

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

static const int modulus = 1000000007;
int paths[MAX_VERTICES];
int find_total_paths(int N)
{
    int i;
    struct edge *e, *p;
    paths[1] = 0;
    paths[N] = 1;
    for (i = N-1; i >= 1; i--) {
        paths[i] = 0;
        e = hdr[i].first;
        while (e) {
           paths[i] += paths[e->vertex];
           p = e;
           e = e->next;
           if (paths[i] > modulus)
               paths[i] = paths[i]%modulus;
           free(p);
        }
		hdr[i].first = NULL;
        dprintf("%d = %d\n", i, paths[i]);
    }
    return paths[1];
}

int main()
{
    int T, N, E;
    int i, s, d;
    int sum;
	int iter;

	iter = 1;
    scanf("%d", &T);
    while (scanf("%d", &N) != EOF) {
        scanf("%d", &E);
        for (i = 1; i <= E; i++) {
            scanf("%d %d", &s, &d);
            if (s < d)
                insert_edge(s, d);
        }
        sum = find_total_paths(N);
        printf("Case %d: %d\n", iter++, sum);
    }
    return 0;
}
