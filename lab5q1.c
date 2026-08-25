#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

int quickSelect(int a[], int low, int high, int k)
{
    if (low == high)
        return a[low];

    int p = partition(a, low, high);

    if (p == k)
        return a[p];

    else if (k < p)
        return quickSelect(a, low, p - 1, k);

    else
        return quickSelect(a, p + 1, high, k);
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n % 2 != 0)
    {
        int median = quickSelect(a, 0, n - 1, n / 2);

        printf("Median = %d\n", median);
    }
    else
    {
        int m1 = quickSelect(a, 0, n - 1, n / 2 - 1);
        int m2 = quickSelect(a, 0, n - 1, n / 2);

        float median = (m1 + m2) / 2.0;

        printf("Median = %.2f\n", median);
    }

    return 0;
}