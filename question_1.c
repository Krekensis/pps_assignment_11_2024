/*
Shit took me 2hrs to figure out the algo.
Format is not according to the question so remove unwanted stuff
*/
#include <stdio.h>

int main() {
    int n, p;

    //printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int array[n][n];
    int sorted[n * n];
    int numberthingy[n * n];
    int index = 0;

    //printf("Enter %d elements for the matrix:\n", n * n);
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &array[i / n][i % n]);
    }
    /*printf("===============================\n");
    printf("Input matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    printf("===============================\n");
    */
   
    for (int x = 0; x < n; x++) {
        if (x % 2 == 0) {
            int a = x;
            int b = 0;
            while (b <= x) {
                sorted[index] = array[a][b];
                numberthingy[index] = a * n + b;
                index++;
                a--;
                b++;
            }
        } else {
            int a = 0;
            int b = x;
            while (a <= x) {
                sorted[index] = array[a][b];
                numberthingy[index] = a * n + b;
                index++;
                a++;
                b--;
            }
        }
    }

    for (int x = 1; x < n; x++) {
        if ((x + n - 1) % 2 == 0) {
            int a = n - 1;
            int b = x;
            while (b < n) {
                sorted[index] = array[a][b];
                numberthingy[index] = a * n + b;
                index++;
                a--;
                b++;
            }
        } else {
            int a = x;
            int b = n - 1;
            while (a < n) {
                sorted[index] = array[a][b];
                numberthingy[index] = a * n + b; 
                index++;
                a++;
                b--;
            }
        }
    }

    
    //printf("Serpentine order array:\n");
    for (int i = 0; i < n * n; i++) {
        printf("%d ", sorted[i]);
    }
    //printf("\n===============================\n");

    //printf("Enter the value of p: ");
    scanf("%d", &p);


    for (int i = 0; i < n * n - 1; i++) {
        for (int j = i + 1; j < n * n; j++) {
            if (sorted[i] > sorted[j]) {

                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;

                int tempIndex = numberthingy[i];
                numberthingy[i] = numberthingy[j];
                numberthingy[j] = tempIndex;
            }
        }
    }

    if (p > 0 && p <= n * n) {
        int aaaa = numberthingy[p - 1];
        int row = aaaa / n;
        int col = aaaa % n;

        printf("%d %d %d.\n", row, col, sorted[p - 1]);
    } else {
        printf("Invalid value of p.\n");
    }

    return 0;
}
