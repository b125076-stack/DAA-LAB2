#include <stdio.h>
#include <stdlib.h>


int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void) {
    int n;
    long long x; 

    printf("Enter n (size of each set): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid n.\n");
        return 1;
    }

    printf("Enter target sum x: ");
    if (scanf("%lld", &x) != 1) {
        printf("Invalid x.\n");
        return 1;
    }

    int *S1 = malloc(n * sizeof(int));
    int *S2 = malloc(n * sizeof(int));
    if (!S1 || !S2) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements of S1:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &S1[i]) != 1) {
            printf("Invalid input for S1.\n");
            return 1;
        }
    }

    printf("Enter %d elements of S2:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &S2[i]) != 1) {
            printf("Invalid input for S2.\n");
            return 1;
        }
    }

    
    qsort(S2, n, sizeof(int), cmp_int);

    
    int found = 0;
    int a_val = 0, b_val = 0;
    int INT_MIN,INT_MAX;

    for (int i = 0; i < n && !found; i++) {
        long long needed = x - (long long)S1[i];

    
        int key = (int)needed;  
        
        if (needed < (long long)INT_MIN || needed > (long long)INT_MAX) {
            continue; 
        }

        int *res = bsearch(&key, S2, n, sizeof(int), cmp_int);
        if (res != NULL) {
            found = 1;
            a_val = S1[i];
            b_val = *res;
        }
    }

    if (found) {
        printf("Pair exists: %d + %d = %lld\n", a_val, b_val, x);
    } else {
        printf("No pair (a from S1, b from S2) sums to %lld.\n", x);
    }

    free(S1);
    free(S2);
    return 0;
}
