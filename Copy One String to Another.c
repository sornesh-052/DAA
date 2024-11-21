#include <stdio.h>

void copyString(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Null-terminate the copied string
}

int main() {
    char source[100], destination[100];
    
    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);

    // Remove newline character added by fgets
    source[strcspn(source, "\n")] = '\0';

    copyString(source, destination);

    printf("Copied string: %s\n", destination);
    return 0;
}

