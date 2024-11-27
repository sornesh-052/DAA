#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4
int findMinInRow(int cost[N][N], bool assigned[N], int row) {
    int min = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (!assigned[j] && cost[row][j] < min) {
            min = cost[row][j];
        }
    }
    return min;
}
int calculateLowerBound(int cost[N][N], bool assigned[N], int level) {
    int bound = 0;
    for (int i = level; i < N; i++) {
        bound += findMinInRow(cost, assigned, i);
    }
    return bound;
}
void solveBranchAndBound(int cost[N][N], int result[N], bool assigned[N], int currentCost, int level, int* minCost) {
    if (level == N) {
        if (currentCost < *minCost) {
            *minCost = currentCost;
            return;
        }
    }
    for (int j = 0; j < N; j++) {
        if (!assigned[j]) {
            assigned[j] = true;
            result[level] = j;
            int newCost = currentCost + cost[level][j];
            int lowerBound = newCost + calculateLowerBound(cost, assigned, level + 1);
            if (lowerBound < *minCost) {
                solveBranchAndBound(cost, result, assigned, newCost, level + 1, minCost);
            }
            assigned[j] = false;
        }
    }
}

int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    int result[N];
    bool assigned[N] = { false };
    int minCost = INT_MAX;
    solveBranchAndBound(cost, result, assigned, 0, 0, &minCost);

    printf("Minimum cost: %d\n", minCost);
    printf("Task assignments:\n");
    for (int i = 0; i < N; i++) {
        printf("Agent %d assigned to Task %d\n", i + 1, result[i] + 1);
    }

    return 0;
}
