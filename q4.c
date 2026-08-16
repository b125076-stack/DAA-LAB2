#include <stdio.h>
#include <stdlib.h>

void add(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    int P1[k][k], P2[k][k], P3[k][k], P4[k][k], P5[k][k], P6[k][k], P7[k][k];
    int T1[k][k], T2[k][k];

    add(k, A11, A22, T1);
    add(k, B11, B22, T2);
    strassen(k, T1, T2, P1);

    add(k, A21, A22, T1);
    strassen(k, T1, B11, P2);

    subtract(k, B12, B22, T2);
    strassen(k, A11, T2, P3);

    subtract(k, B21, B11, T2);
    strassen(k, A22, T2, P4);

    add(k, A11, A12, T1);
    strassen(k, T1, B22, P5);

    subtract(k, A21, A11, T1);
    add(k, B11, B12, T2);
    strassen(k, T1, T2, P6);

    subtract(k, A12, A22, T1);
    add(k, B21, B22, T2);
    strassen(k, T1, T2, P7);

    int C11[k][k], C12[k][k], C21[k][k], C22[k][k];
    int X[k][k], Y[k][k];

    add(k, P1, P4, T1);
    subtract(k, T1, P5, T2);
    add(k, T2, P7, C11);

    add(k, P3, P5, C12);
    add(k, P2, P4, C21);

    add(k, P1, P3, T1);
    subtract(k, T1, P2, T2);
    add(k, T2, P6, C22);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter order of matrix (power of 2): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter first matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter second matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(n, A, B, C);

    printf("Result matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
