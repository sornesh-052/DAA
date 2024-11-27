#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    int i,j,space;
    for (i = 0; i < n; i++) {
        int value = 1;
        for ( space=0;space<n-i-1;space++) {
            printf(" ");
        }
        for ( j = 0; j <= i; j++) {
            printf("%d ", value);
            value = value * (i - j) / (j + 1);
        }
        printf("\n");
    }

    return 0;
}
