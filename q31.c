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

    int numArrays = k;
    int size = n;

   
    while (numArrays > 1)
    {
        int newCount = (numArrays + 1) / 2;

        int **newArr = malloc(newCount * sizeof(int *));

        int index = 0;

        for (int i = 0; i < numArrays; i += 2)
        {
            if (i + 1 < numArrays)
            {
                int newSize = size * 2;

                newArr[index] = malloc(newSize * sizeof(int));

                merge(arr[i], size,
                      arr[i + 1], size,
                      newArr[index]);

                free(arr[i]);
                free(arr[i + 1]);

                index++;
            }
            else
            {
                
                newArr[index] = arr[i];
                index++;
            }
        }

        free(arr);

        arr = newArr;
        numArrays = newCount;
        size *= 2;
    }

    printf("\nFinal sorted array:\n");

    for (int i = 0; i < k * n; i++)
        printf("%d ", arr[0][i]);

    printf("\n");

    free(arr[0]);
    free(arr);

    return 0;
}