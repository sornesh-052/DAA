#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF INT_MAX

int dp[MAX][1 << MAX], dist[MAX][MAX], n;

int tsp(int pos, int mask) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];
    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INF;
    for (int next = 0; next < n; next++) {
        if ((mask & (1 << next)) == 0)
            ans = (ans < dist[pos][next] + tsp(next, mask | (1 << next))) ? ans : dist[pos][next] + tsp(next, mask | (1 << next));
    }

    return dp[pos][mask] = ans;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            dp[i][j] = -1;

    printf("Minimum Cost of TSP: %d\n", tsp(0, 1));
    return 0;
}

