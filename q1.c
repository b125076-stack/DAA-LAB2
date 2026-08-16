#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1, steps = 0;

    while (low <= high) {
        steps++;
        int mid = (low + high) / 2;

        if (arr[mid] == x) {
            printf("Binary Search: Found at index %d\n", mid);
            printf("Binary Search Steps: %d\n", steps);
            return 1;
        }

        if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    printf("Binary Search: Not Found\n");
    printf("Binary Search Steps: %d\n", steps);
    return 0;
}

int ternarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1, steps = 0;

    while (low <= high) {
        steps++;
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (arr[mid1] == x) {
            printf("Ternary Search: Found at index %d\n", mid1);
            printf("Ternary Search Steps: %d\n", steps);
            return 1;
        }

        if (arr[mid2] == x) {
            printf("Ternary Search: Found at index %d\n", mid2);
            printf("Ternary Search Steps: %d\n", steps);
            return 1;
        }

        if (x < arr[mid1])
            high = mid1 - 1;
        else if (x > arr[mid2])
            low = mid2 + 1;
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    printf("Ternary Search: Not Found\n");
    printf("Ternary Search Steps: %d\n", steps);
    return 0;
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    binarySearch(arr, n, x);
    ternarySearch(arr, n, x);

    return 0;
}
