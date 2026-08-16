#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int n)
{
    int *A = (int *)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    return A;
}

void freeMatrix(int **A, int n)
{
    for (int i = 0; i < n; i++)
        free(A[i]);

    free(A);
}

void addMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

/* Special-pattern matrix multiplication */
void multiply(int **A, int **B, int **C, int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int **A1 = createMatrix(k);
    int **A2 = createMatrix(k);
    int **B1 = createMatrix(k);
    int **B2 = createMatrix(k);

    int **P = createMatrix(k);
    int **Q = createMatrix(k);

    int **X = createMatrix(k);
    int **Y = createMatrix(k);

    /* Since
       A = [ A1 A2 ]
           [ A2 A1 ]

       B = [ B1 B2 ]
           [ B2 B1 ]
    */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j + k];

            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j + k];
        }
    }

    /*
       P = (A1 + A2)(B1 + B2)
       Q = (A1 - A2)(B1 - B2)

       C1 = (P + Q) / 2
       C2 = (P - Q) / 2
    */

    addMatrix(A1, A2, X, k);
    addMatrix(B1, B2, Y, k);
    multiply(X, Y, P, k);

    subMatrix(A1, A2, X, k);
    subMatrix(B1, B2, Y, k);
    multiply(X, Y, Q, k);

    /* Construct result */

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int C1 = (P[i][j] + Q[i][j]) / 2;
            int C2 = (P[i][j] - Q[i][j]) / 2;

            C[i][j] = C1;
            C[i][j + k] = C2;
            C[i + k][j] = C2;
            C[i + k][j + k] = C1;
        }
    }

    freeMatrix(A1, k);
    freeMatrix(A2, k);
    freeMatrix(B1, k);
    freeMatrix(B2, k);
    freeMatrix(P, k);
    freeMatrix(Q, k);
    freeMatrix(X, k);
    freeMatrix(Y, k);
}

void printMatrix(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", A[i][j]);

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter size of matrix (power of 2): ");
    scanf("%d", &n);

    int **A = createMatrix(n);
    int **B = createMatrix(n);
    int **C = createMatrix(n);

    printf("Enter Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    multiply(A, B, C, n);

    printf("\nResultant Matrix:\n");
    printMatrix(C, n);

    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}