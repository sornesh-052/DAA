#include <stdio.h>
int solutionCount = 0;
void printSubset(int subset[], int size) {
    printf("Subset %d: { ", ++solutionCount);
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int total, int index, int targetSum) {
    if (total == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }
    for (int i = index; i < n; i++) {
        if (total + set[i] <= targetSum) {
            subset[subsetSize] = set[i];
            sumOfSubsets(set, subset, n, subsetSize + 1, total + set[i], i + 1, targetSum);
        }
    }
}
int main() {
    int n, targetSum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n], subset[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    printf("Subsets that sum to %d are:\n", targetSum);
    sumOfSubsets(set, subset, n, 0, 0, 0, targetSum);
    if (solutionCount == 0) {
        printf("No subset found with the sum %d.\n", targetSum);
    }

    return 0;
}
