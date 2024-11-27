#include <stdio.h>

int main() {
    int n, num, pos;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int arr[n+1]; 
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);

    printf("Enter the position where to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);
    pos--;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    printf("Updated list:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
