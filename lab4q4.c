#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int time;
    int type;   
} Event;

int cmp(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;
    return e1->time - e2->time;
}

int main() {
    int n, i;
    int a[MAX], b[MAX];
    Event events[2 * MAX];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    for (i = 0; i < n; i++) {
        events[2 * i].time = a[i];
        events[2 * i].type = 1;   // entry
        events[2 * i + 1].time = b[i];
        events[2 * i + 1].type = 0; // exit
    }

    qsort(events, 2 * n, sizeof(Event), cmp);

    int current = 0, maxCount = 0, timeAtMax = -1;

    for (i = 0; i < 2 * n; i++) {
        if (events[i].type == 1)
            current++;
        else
            current--;

        if (current > maxCount) {
            maxCount = current;
            timeAtMax = events[i].time;
        }
    }

    printf("Maximum people = %d\n", maxCount);
    printf("Time = %d\n", timeAtMax);

    return 0;
}
