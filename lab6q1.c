#include <stdio.h>
#include <math.h>

#define MAX 100

void reverseArray(int a[], int n) {
    int i, t;
    for(i = 0; i < n/2; i++) {
        t = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = t;
    }
}

void partition(int a[], int n, int pivot) {
    int i, j = -1, t;
    for(i = 0; i < n; i++) {
        if(a[i] < pivot) {
            j++;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
}

int main() {
    int a[MAX], b[MAX], i, j, n;
    int max, first, second, pivot, count, mode, maxCount;
    double sum = 0, mean, var = 0, sd;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    max = a[0];
    first = second = -2147483648;

    for(i = 0; i < n; i++) {
        if(a[i] > max) max = a[i];

        if(a[i] > first) {
            second = first;
            first = a[i];
        } else if(a[i] > second && a[i] != first) {
            second = a[i];
        }

        sum += a[i];
    }

    mean = sum / n;

    for(i = 0; i < n; i++) {
        var += (a[i] - mean) * (a[i] - mean);
    }
    sd = sqrt(var / n);

    maxCount = 0;
    mode = a[0];
    for(i = 0; i < n; i++) {
        count = 0;
        for(j = 0; j < n; j++) {
            if(a[i] == a[j]) count++;
        }
        if(count > maxCount) {
            maxCount = count;
            mode = a[i];
        }
    }

    for(i = 0; i < n; i++) b[i] = a[i];

    printf("\nMaximum = %d\n", max);
    printf("First largest = %d\n", first);
    printf("Second largest = %d\n", second);
    printf("Mean = %.2f\n", mean);
    printf("Standard deviation = %.2f\n", sd);
    printf("Mode = %d\n", mode);

    reverseArray(b, n);
    printf("\nReversed array:\n");
    for(i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");

    pivot = a[0];
    for(i = 0; i < n; i++) b[i] = a[i];
    partition(b, n, pivot);

    printf("Partitioned array with pivot %d:\n", pivot);
    for(i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");

    return 0;
}
