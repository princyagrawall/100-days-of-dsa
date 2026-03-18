#include <stdio.h>
#include <string.h>

// Recursive function to print string in reverse
void mirror(char str[], int index) {
    if (index < 0)
        return;

    printf("%c", str[index]);
    mirror(str, index - 1);
}

int main() {
    char str[100];

    // Input
    scanf("%s", str);

    // Get length of string
    int len = strlen(str);

    // Output (mirror format)
    mirror(str, len - 1);

    return 0;
}