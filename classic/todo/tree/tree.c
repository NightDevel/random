#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VERTICES (100000+100)

/* using adjacency list */
struct edge {
    int vertex;
    int weight;
    struct edge *next;
};

typedef struct{
    struct edge *first;
    struct edge *last;
    int count;
}hdr_edge;

hdr_edge hdr[MAX_VERTICES];

/* insert this edge in hdr list */ 
void insert_edge(int s, int d, int w)
{
    struct edge *tmp;
    tmp = (struct edge *)malloc(sizeof(struct edge));
    tmp->vertex = d;
    tmp->weight = w;
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
char visited[MAX_VERTICES];
int sum;
void dfs(int vertex, int dist)
{
    int cost;
    struct edge *e;

    e = hdr[vertex].first;
    while (e) {
        if (!visited[e->vertex]) {
            visited[e->vertex] = 1;
            
            cost = (dist * e->weight);
            if (cost > modulus)
                cost = cost%modulus;

            if (vertex < e->vertex) {
                if ((sum += cost) >= modulus)
                    sum = sum % modulus;
            }
            dfs(e->vertex, cost);
        }
        e = e->next;
    }
}

int main()
{
    int i, N;
    int v;
    int s, d, w;
    scanf("%d", &N);

    /* N-1 edges */
    for (i = 1; i <= N-1; i++) {
        scanf("%d %d %d", &s, &d, &w);
        insert_edge(s, d, w);
        insert_edge(d, s, w);
    }
    sum = 0;
    for (v = 1; v <= N; v++){
        memset(visited, 0, (N+1));
        visited[v] = 1;
        dfs(v, 1);
    }
    printf("%d\n", sum);
    return 0;
}
