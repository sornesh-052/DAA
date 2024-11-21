#include <stdio.h>

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character added by fgets
    str[strcspn(str, "\n")] = '\0';

    printf("Length of the string: %d\n", stringLength(str));
    return 0;
}

