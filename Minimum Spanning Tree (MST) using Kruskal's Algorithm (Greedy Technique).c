#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX];

// Find the root of a set
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union of two sets
void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Comparison function for qsort
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal's algorithm
void kruskal(int n, int e) {
    int mstWeight = 0, mstEdges = 0;
    int i;

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    qsort(edges, e, sizeof(Edge), compareEdges);

    printf("Edges in MST:\n");
    for (i = 0; i < e; i++) {
        // Check if including this edge creates a cycle
        if (find(edges[i].u) != find(edges[i].v)) {
            printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(edges[i].u, edges[i].v);
            mstEdges++;
        }

        // Stop if we have included enough edges for the MST
        if (mstEdges == n - 1)
            break;
    }

    printf("Minimum Cost of MST: %d\n", mstWeight);
}

int main() {
    int n, e, i;

    // Input the number of vertices and edges
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    // Input the edges
    for (i = 0; i < e; i++) {
        printf("Enter edge (u v weight): ");
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Run Kruskal's algorithm
    kruskal(n, e);

    return 0;
}
