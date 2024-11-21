#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskal(int n, int e) {
    int mstWeight = 0, mstEdges = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    qsort(edges, e, sizeof(Edge), compareEdges);

    printf("Edges in MST:\n");
    for (int i = 0; i < e; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(edges[i].u, edges[i].v);
            mstEdges++;
        }
        if (mstEdges == n - 1)
            break;
    }

    printf("Minimum Cost of MST: %d\n", mstWeight);
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        printf("Enter edge (u, v, weight): ");
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(n, e);
    return 0;
}

