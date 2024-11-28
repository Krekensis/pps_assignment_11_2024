#include <stdio.h>
#include <stdbool.h>

bool selfdiv(int num) {
    int copy = num;
    while (copy > 0) {
        int digit = copy % 10; 
        if (digit == 0 || num % digit != 0) {
            return false;
        }
        copy /= 10;
    }
    return true;
}

int main() {
    int left, right;

    if (scanf("left = %d, right = %d", &left, &right) != 2) {
        printf("Invalid input format\n");
        return 1;
    }

    if (left < 1 || right > 10000 || left > right) {
        printf("Invalid input range\n");
        return 1;
    }

    for (int i = left; i <= right; i++) {
        if (selfdiv(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
