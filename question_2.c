#include <stdio.h>
#define max 100

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int fibo(int n) {
    if (n <= 1)
        return n;
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int N; 
    scanf("%d", &N);
    getchar();

    char type[max];
    int arg1[max], arg2[max];

    for (int i = 0; i < N; i++) {
        scanf("%c", &type[i]);
        if (type[i] == 'F') {
            scanf("%d", &arg1[i]);
            arg2[i] = -1; 
        } else if (type[i] == 'G') {
            scanf("%d %d", &arg1[i], &arg2[i]);
        }
        getchar();
    }

    for (int i = 0; i < N; i++) {
        if (type[i] == 'F') {
            for (int j = 0; j < arg1[i]; j++) {
                printf("%d ", fibo(j));
            }
            printf("\n");
        } else if (type[i] == 'G') {
            printf("%d\n", gcd(arg1[i], arg2[i]));
        }
    }

    return 0;
}
