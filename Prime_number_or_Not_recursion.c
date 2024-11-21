#include <stdio.h>
int isPrimeHelper(int n, int i) {
    if (n <= 2) 
        return (n == 2) ? 1 : 0;
    if (n % i == 0)
        return 0;
    if (i * i > n)
        return 1;
    return isPrimeHelper(n, i + 1);
}
int isPrime(int n) {
    return isPrimeHelper(n, 2);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
    return 0;
}
