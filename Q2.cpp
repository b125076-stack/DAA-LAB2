#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

long long mergeCount = 0;
long long threeMergeCount = 0;

/* -------------------- NORMAL MERGE SORT -------------------- */

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[MAX], R[MAX];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        mergeCount++;

        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* -------------------- MODIFIED 3-WAY MERGE SORT -------------------- */

void mergeThree(int arr[], int low, int mid1, int mid2, int high)
{
    int temp[MAX];

    int i = low;
    int j = mid1 + 1;
    int k = mid2 + 1;

    int index = low;

    while(i <= mid1 && j <= mid2 && k <= high)
    {
        threeMergeCount++;

        if(arr[i] <= arr[j] && arr[i] <= arr[k])
            temp[index++] = arr[i++];
        else if(arr[j] <= arr[i] && arr[j] <= arr[k])
            temp[index++] = arr[j++];
        else
            temp[index++] = arr[k++];
    }

    while(i <= mid1 && j <= mid2)
    {
        if(arr[i] <= arr[j])
            temp[index++] = arr[i++];
        else
            temp[index++] = arr[j++];
    }

    while(j <= mid2 && k <= high)
    {
        if(arr[j] <= arr[k])
            temp[index++] = arr[j++];
        else
            temp[index++] = arr[k++];
    }

    while(i <= mid1 && k <= high)
    {
        if(arr[i] <= arr[k])
            temp[index++] = arr[i++];
        else
            temp[index++] = arr[k++];
    }

    while(i <= mid1)
        temp[index++] = arr[i++];

    while(j <= mid2)
        temp[index++] = arr[j++];
 
    while(k <= high)
        temp[index++] = arr[k++];

    for(i = low; i <= high; i++)
        arr[i] = temp[i];
}

void threeWayMergeSort(int arr[], int low, int high)
{
    if(low >= high)
        return;

    int third = (high - low) / 3;

    int mid1 = low + third;
    int mid2 = low + 2 * third + 1;

    if(mid2 > high)
        mid2 = high;

    threeWayMergeSort(arr, low, mid1);

    threeWayMergeSort(arr, mid1 + 1, mid2);

    threeWayMergeSort(arr, mid2 + 1, high);

    mergeThree(arr, low, mid1, mid2, high);
}

/* -------------------- PRINT ARRAY -------------------- */

void printArray(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

/* -------------------- MAIN FUNCTION -------------------- */

int main()
{
    int arr1[] = {45,12,78,34,23,90,11,67,54,10};

    int arr2[] = {45,12,78,34,23,90,11,67,54,10};

    int n = sizeof(arr1)/sizeof(arr1[0]);

    printf("Original Array:\n");

    printArray(arr1, n);

    mergeSort(arr1, 0, n - 1);

    printf("\nSorted using Merge Sort:\n");

    printArray(arr1, n);

    threeWayMergeSort(arr2, 0, n - 1);

    printf("\nSorted using Modified 3-Way Merge Sort:\n");

    printArray(arr2, n);

    printf("\nComparison Count (Merge Sort): %lld", mergeCount);

    printf("\nComparison Count (3-Way Merge Sort): %lld", threeMergeCount);

    printf("\n\nWorst Case Complexity (Merge Sort)        : O(n log n)");

    printf("\nWorst Case Complexity (3-Way Merge Sort)  : O(n log n)");

    return 0;
}