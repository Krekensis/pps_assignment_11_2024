#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100], digits[100];
    int j = 0;
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            digits[j++] = input[i];
        }
    }
    digits[j] = '\0';
    printf("%s", digits);
    return 0;
}
