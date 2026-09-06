#include <stdio.h>
#include <math.h>

#define MAX 50

void add(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int n) {
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void multiply(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int n) {
    int i, j, k;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            c[i][j] = 0;
            for(k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

int isZeroMatrix(int a[MAX][MAX], int n) {
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(a[i][j] != 0) return 0;
    return 1;
}

int isSymmetric(int a[MAX][MAX], int n) {
    int i, j;
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(a[i][j] != a[j][i]) return 0;
    return 1;
}

void transposeInPlace(int a[MAX][MAX], int n) {
    int i, j, t;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }
}


void printMatrix(int a[MAX][MAX], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main() {
    int n, i, j;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter matrix A (%d x %d):\n", n, n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B (%d x %d):\n", n, n);
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    add(A, B, C, n);
    printf("\nA + B:\n");
    printMatrix(C, n);

    multiply(A, B, C, n);
    printf("\nA * B:\n");
    printMatrix(C, n);

    printf("\nA is %sa zero matrix\n", isZeroMatrix(A, n) ? "" : "not ");
    printf("A is %ssymmetric\n", isSymmetric(A, n) ? "" : "not ");

    transposeInPlace(A, n);
    printf("\nTranspose of A in place:\n");
    printMatrix(A, n);

    return 0;
}
