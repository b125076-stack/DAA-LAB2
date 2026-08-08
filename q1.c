#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

long long linearSearch(int n)
{
    long long operations = 0;

    for (int i = 0; i < n; i++)
        operations++;

    return operations;
}

long long binarySearch(int n)
{
    long long operations = 0;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        operations++;

        if (mid < n - 1)
            low = mid + 1;
        else
            break;
    }

    return operations;
}

long long constantOperation()
{
    return 1;
}

long long quadraticOperation(int n)
{
    long long operations = 0;

    for (int i = 0; i < n; i++)
        operations++;

    return operations;
}

int main()
{
    FILE *fp;
    fp = fopen("growth.csv", "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp,
        "n,UnsortedSearch,SortedSearch,InsertDeleteLinear,Constant\n");

    int values[] = {
        10, 100, 500, 1000, 5000,
        10000, 20000, 50000, 100000
    };

    int count = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < count; i++)
    {
        int n = values[i];

        long long unsortedSearch = linearSearch(n);
        long long sortedSearch = binarySearch(n);

        
        long long linear = quadraticOperation(n);

        long long constant = constantOperation();

        fprintf(fp, "%d,%lld,%lld,%lld,%lld\n",
                n,
                unsortedSearch,
                sortedSearch,
                linear,
                constant);
    }

    fclose(fp);

    printf("Growth data successfully written to growth.csv\n");

    return 0;
}