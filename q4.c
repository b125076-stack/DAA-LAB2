#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI acos(-1.0)

void fft(double complex *a, int n, int invert) {
    int i, j, len;
    for(i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for(; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if(i < j) {
            double complex t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    for(len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        double complex wlen = cos(ang) + I * sin(ang);
        for(i = 0; i < n; i += len) {
            double complex w = 1;
            for(j = 0; j < len / 2; j++) {
                double complex u = a[i + j];
                double complex v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if(invert) {
        for(i = 0; i < n; i++) a[i] /= n;
    }
}

int nextPowerOfTwo(int x) {
    int p = 1;
    while(p < x) p <<= 1;
    return p;
}

void convolution(int A[], int m, int B[], int n, int C[]) {
    int size = nextPowerOfTwo(m + n - 1);
    int i;

    double complex *fa = (double complex*)calloc(size, sizeof(double complex));
    double complex *fb = (double complex*)calloc(size, sizeof(double complex));

    for(i = 0; i < m; i++) fa[i] = A[i];
    for(i = 0; i < n; i++) fb[i] = B[i];

    fft(fa, size, 0);
    fft(fb, size, 0);

    for(i = 0; i < size; i++) fa[i] *= fb[i];

    fft(fa, size, 1);

    for(i = 0; i < m + n - 1; i++) C[i] = (int)round(creal(fa[i]));

    free(fa);
    free(fb);
}

int main() {
    int m, n, i;

    printf("Enter length of A: ");
    scanf("%d", &m);
    printf("Enter length of B: ");
    scanf("%d", &n);

    int *A = (int*)malloc(m * sizeof(int));
    int *B = (int*)malloc(n * sizeof(int));
    int *C = (int*)malloc((m + n - 1) * sizeof(int));

    printf("Enter %d elements of A:\n", m);
    for(i = 0; i < m; i++) scanf("%d", &A[i]);

    printf("Enter %d elements of B:\n", n);
    for(i = 0; i < n; i++) scanf("%d", &B[i]);

    convolution(A, m, B, n, C);

    printf("Convolution result:\n");
    for(i = 0; i < m + n - 1; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    free(A);
    free(B);
    free(C);

    return 0;
}
