#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q)
{
    int a = *(const int *)p;
    int b = *(const int *)q;

    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

int binarySearch(const int a[], int left, int right, int key)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == key)
            return 1;
        else if (a[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0;
}


int kSum(const int a[], int n, int start, int remaining,
         long long target)
{
    if (remaining == 1) {
        if (target < -2147483648LL ||
            target > 2147483647LL)
            return 0;

        return binarySearch(a, start, n - 1, (int)target);
    }

    
    for (int i = start; i <= n - remaining; i++) {
        
        if (i > start && a[i] == a[i - 1])
            continue;

        if (kSum(a, n, i + 1, remaining - 1,
                 target - a[i])) {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    int n, k;
    long long T;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid value of n.\n");
        return 1;
    }

    int *a = malloc(n * sizeof(int));

    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements of S:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter T: ");
    scanf("%lld", &T);

    if (k < 1 || k > n) {
        printf("Invalid value of k.\n");
        free(a);
        return 1;
    }

    qsort(a, n, sizeof(int), compare);

    if (kSum(a, n, 0, k, T))
        printf("Yes: %d elements add up to %lld.\n", k, T);
    else
        printf("No: %d elements do not add up to %lld.\n", k, T);

    free(a);
    return 0;
}
