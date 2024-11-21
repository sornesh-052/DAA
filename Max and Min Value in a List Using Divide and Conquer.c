#include <stdio.h>

void findMinMax(int arr[], int low, int high, int* min, int* max) {
    if (low == high) {
        *min = *max = arr[low];
    } else if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
    } else {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;

        findMinMax(arr, low, mid, &min1, &max1);
        findMinMax(arr, mid + 1, high, &min2, &max2);

        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main() {
    int arr[] = {3, 5, 1, 9, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    return 0;
}

