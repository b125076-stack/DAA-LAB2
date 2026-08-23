#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int num;
    char color[10];
} Item;

int main() {
    int n, i, r = 0, b = 0, y = 0;
    Item input[MAX], R[MAX], B[MAX], Y[MAX];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %s", &input[i].num, input[i].color);
    }

    for (i = 0; i < n; i++) {
        if (strcmp(input[i].color, "red") == 0) {
            R[r++] = input[i];
        } else if (strcmp(input[i].color, "blue") == 0) {
            B[b++] = input[i];
        } else if (strcmp(input[i].color, "yellow") == 0) {
            Y[y++] = input[i];
        }
    }

    for (i = 0; i < r; i++)
        printf("%d %s\n", R[i].num, R[i].color);
    for (i = 0; i < b; i++)
        printf("%d %s\n", B[i].num, B[i].color);
    for (i = 0; i < y; i++)
        printf("%d %s\n", Y[i].num, Y[i].color);

    return 0;
}
