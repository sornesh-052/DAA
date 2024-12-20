#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d: ", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

