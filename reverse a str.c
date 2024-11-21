#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    printf("Reversed string: ");
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character added by fgets
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);
    return 0;
}

