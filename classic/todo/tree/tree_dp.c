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
long long  sum;
long long cost[MAX_VERTICES];
int child_list[MAX_VERTICES];
int child_top = 0;
/* have to calculate euler tour and each node depth */
long long tree_cost = 0;
long long dfs(int vertex)
{
    long long child_cost;
    long long c;
    int  child_start;
    struct edge *e;
    long long  sum_of_nodes;
    long long sum_of_child;
    

    sum_of_nodes = 0;
    /* from current node to every other node*/
    long long total_sum_of_child = 0;
    /* sum of nodes = includes lower nodes values too  in isolation*/
    /* e.w * e.cost */
    child_start = child_top;
    child_cost = 0;
    for (e = hdr[vertex].first; e; e = e->next) {
        if (!visited[e->vertex]) {
            visited[e->vertex] = 1;
            sum_of_child = dfs(e->vertex);
            /* Gives all combination of weights from current parent to the child below 
            * sum of child nodes + (sum of child notes * child weight) 
            */
            printf("sum of child: %d\n", sum_of_child);
            sum_of_nodes += sum_of_child + (1 + sum_of_child) * e->weight;
            total_sum_of_child += (1+sum_of_child) * e->weight;
            cost[e->vertex] = (1+sum_of_child)*e->weight;
            child_list[child_top++] = e->vertex;
            printf("After dfs: vertex: %d: dest = %d: weight: %d, sum of nodes = %d, total_sum_of_child = %d\n", vertex, e->vertex, e->weight, sum_of_nodes, total_sum_of_child);
        }
    }
    printf("---Vertex: %d, Final: sum_of_nodes = %d, total_sum_of_child = %d\n", vertex, total_sum_of_child, sum_of_nodes); 
    long long  p;
    /* Equation:
     * cost (node) = sum(cost of each child) + all possible combination (multiplication) of child cost 
     */
    /* if not a leaf node */
    if (child_start != child_top) {
        e = hdr[vertex].first;
        p = total_sum_of_child;
        for ( ; e; e = e->next) {
            printf("Before processing: vertex:%d, evertex = %d," 
                        "ctop = %d, top_element = %d\n", vertex, e->vertex, child_top, child_list[child_start]);
            if (child_list[child_start] == e->vertex) {
                p -= cost[e->vertex];
                tree_cost +=  cost[e->vertex] * p;
                printf("%d : p = %d, psum = %d\n", e->vertex, p, p * cost[e->vertex]);
                child_list[child_start] = 0;
                child_top--;
                child_start++;
            }
        }
        printf("tree_cost = %d\n", tree_cost);

    }
    else {    
        printf("leaf = %d\n", vertex);
    }
    tree_cost += (sum_of_nodes - total_sum_of_child);
    return total_sum_of_child;
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
    memset(visited, 0, (N+1));
    visited[1] = 1;
    sum = dfs(1);
    printf("%d: %lld, %lld\n", sum, tree_cost, (sum + tree_cost));
    return 0;
}
