#include <stdio.h>
#include <limits.h>
#define N 4
void subtractRowMin(int cost[N][N]) {
    for (int i = 0; i < N; i++) {
        int min = cost[i][0];
        for (int j = 1; j < N; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
            }
        }
        for (int j = 0; j < N; j++) {
            cost[i][j] -= min;
        }
    }
}
void subtractColMin(int cost[N][N]) {
    for (int j = 0; j < N; j++) {
        int min = cost[0][j];
        for (int i = 1; i < N; i++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
            }
        }
        for (int i = 0; i < N; i++) {
            cost[i][j] -= min;
        }
    }
}
int isCovered(int rowCovered[N], int colCovered[N], int i, int j) {
    return rowCovered[i] || colCovered[j];
}
void coverZeros(int cost[N][N], int rowCovered[N], int colCovered[N], int mark[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cost[i][j] == 0 && !isCovered(rowCovered, colCovered, i, j)) {
                mark[i][j] = 1; 
                rowCovered[i] = 1;
                colCovered[j] = 1;
            }
        }
    }
}
int hungarianAlgorithm(int cost[N][N]) {
    int rowCovered[N] = {0}, colCovered[N] = {0};
    int mark[N][N] = {0};
    int minCost = 0;
    subtractRowMin(cost);
    subtractColMin(cost);
    coverZeros(cost, rowCovered, colCovered, mark);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mark[i][j] == 1) {
                minCost += cost[i][j];
            }
        }
    }

    return minCost;
}
int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    int optimalCost = hungarianAlgorithm(cost);
    printf("The optimal cost is: %d\n", optimalCost);

    return 0;
}
