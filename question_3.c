#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int findingNemo(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, k, t;
    if (scanf("%d", &n) != 1 || n < 1 || n > 100000) {
        printf("-1\n");
        return 0;
    }
    int nums[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("-1\n");
            return 0;
        }
    }

    if (scanf("%d", &k) != 1 || k < 0 || k > n) {
        printf("-1\n");
        return 0;
    }

    if (scanf("%d", &t) != 1) {
        printf("-1\n");
        return 0;
    }

    if (k > 0 || k < n) {
        reverse(nums, 0, n - 1); //[0 ... n-1]
        reverse(nums, 0, k - 1); //[>>>> 0 ... k-1, <<<< k ... n-1 ]
        reverse(nums, k, n - 1); //[0 ... k-1, >>>> k ... n-1 <<<<]
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int index = findingNemo(nums, n, t);
    printf("%d\n", index);

    return 0;
}
