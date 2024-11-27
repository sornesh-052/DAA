#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int dp[n+1][W+1]; 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W]; 
}
int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int val[n], wt[n];
int i,j;
   
    printf("Enter the values of the items: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    printf("Enter the weights of the items: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    int max_value = knapsack(W, wt, val, n);
    printf("The maximum value that can be obtained is: %d\n", max_value);

    return 0;
}
