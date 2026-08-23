#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int start;
    int end;
} Interval;

int cmp(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->start - i2->start;
}

int main() {
    int n, i, k = 0;
    Interval intervals[MAX], merged[MAX];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    qsort(intervals, n, sizeof(Interval), cmp);

    merged[k++] = intervals[0];

    for (i = 1; i < n; i++) {
        if (intervals[i].start <= merged[k - 1].end) {
            if (intervals[i].end > merged[k - 1].end) {
                merged[k - 1].end = intervals[i].end;
            }
        } else {
            merged[k++] = intervals[i];
        }
    }

    for (i = 0; i < k; i++) {
        printf("(%d, %d)\n", merged[i].start, merged[i].end);
    }

    return 0;
}
