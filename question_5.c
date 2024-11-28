#include <stdio.h>
#include <string.h>

int main() {
    int cases, num, i, count = 0;
    long long x;
    scanf("%d", &cases);
    long long results[cases];

    for (int j = 0; j < cases; j++) {
        scanf("%d", &num); 
        x = num;

        while (1) {
            char pp[100000];
            sprintf(pp, "%lld", x);
            
            int valid = 1;
            for (i = 0; i < strlen(pp); i++) {
                if (pp[i] != '9' && pp[i] != '0') {
                    valid = 0;
                    break;
                }
            }
            if (valid){
                break;
            }
            x += num;
        }
        results[j] = x;
    }

    for (int j = 0; j < cases; j++) {
        printf("%lld\n", results[j]);
    }

    return 0;
}
