#include <stdio.h>

#define MAX 200

void reverse(int p[], int i, int j) {
    int t;
    while(i < j) {
        t = p[i];
        p[i] = p[j];
        p[j] = t;
        i++;
        j--;
    }
}

void printArray(int p[], int n) {
    int i;
    for(i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");
}

void mergeByReversal(int p[], int l, int m, int r) {
    int i = l;
    while(i <= m && p[i] <= p[m + 1]) i++;

    if(i > m) return;

    int j = m + 1;
    while(j <= r && p[j] < p[i]) j++;

    reverse(p, i, m);
    reverse(p, m + 1, j - 1);
    reverse(p, i, j - 1);

    if(i < j - 1) {
        int leftSize = (i - l) + (j - 1 - (m + 1) + 1);
        int newMid = l + leftSize - 1;
        mergeByReversal(p, l, newMid, j - 1);
    }
}

void sortByReversal(int p[], int l, int r) {
    if(l >= r) return;
    int m = (l + r) / 2;
    sortByReversal(p, l, m);
    sortByReversal(p, m + 1, r);
    mergeByReversal(p, l, m, r);
}

int main() {
    int n, i, p[MAX];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter permutation of 1 to %d:\n", n);
    for(i = 0; i < n; i++) scanf("%d", &p[i]);

    sortByReversal(p, 0, n - 1);

    printf("Sorted array:\n");
    printArray(p, n);

    return 0;
}
