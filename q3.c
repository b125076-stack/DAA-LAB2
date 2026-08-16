#include <stdio.h>

typedef struct {
    int max;
    int min;
} MaxMin;

MaxMin findMaxMin(int a[], int low, int high) {
    MaxMin result, left, right;
    int mid;

    if (low == high) {
        result.max = a[low];
        result.min = a[low];
        return result;
    }

    if (high == low + 1) {
        if (a[low] > a[high]) {
            result.max = a[low];
            result.min = a[high];
        } else {
            result.max = a[high];
            result.min = a[low];
        }
        return result;
    }

  
    mid = low + (high - low) / 2;

    left = findMaxMin(a, low, mid);
    right = findMaxMin(a, mid + 1, high);


    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

int main() {
    int n, i;
    MaxMin answer;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be positive.\n");
        return 1;
    }

    int a[n];

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    answer = findMaxMin(a, 0, n - 1);

    printf("\nMaximum element = %d\n", answer.max);
    printf("Minimum element = %d\n", answer.min);

    return 0;
}
