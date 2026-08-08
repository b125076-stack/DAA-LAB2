#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int size1, int b[], int size2, int result[])
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (a[i] <= b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < size1)
        result[k++] = a[i++];

    while (j < size2)
        result[k++] = b[j++];
}

int main()
{
    int k, n;

    printf("Enter number of arrays (k): "); 
    scanf("%d", &k);

    printf("Enter number of elements in each array (n): ");
    scanf("%d", &n);

    int **arr = malloc(k * sizeof(int *));

    for (int i = 0; i < k; i++)
    {
        arr[i] = malloc(n * sizeof(int));

        printf("Enter sorted array %d:\n", i + 1);

        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }

    int total = n;
    int *result = malloc(total * sizeof(int));

    for (int i = 0; i < n; i++)
        result[i] = arr[0][i];

    /* Merge arrays one by one */
    for (int i = 1; i < k; i++)
    {
        int newSize = total + n;

        int *temp = malloc(newSize * sizeof(int));

        merge(result, total, arr[i], n, temp);

        free(result);

        result = temp;
        total = newSize;
    }

    printf("\nFinal sorted array:\n");

    for (int i = 0; i < total; i++)
        printf("%d ", result[i]);

    printf("\n");

    for (int i = 0; i < k; i++)
        free(arr[i]);

    free(arr);
    free(result);

    return 0;
}