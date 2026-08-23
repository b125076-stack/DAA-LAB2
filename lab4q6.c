#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int x;
    int type;   
} Event;

int cmp(const void *a, const void *b) {
    Event *e1 = (Event *)a;
    Event *e2 = (Event *)b;

    if (e1->x != e2->x)
        return e1->x - e2->x;

    return e2->type - e1->type;   
}

int main() {
    int n, i;
    int l[MAX], r[MAX];
    Event events[2 * MAX];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }

    for (i = 0; i < n; i++) {
        events[2 * i].x = l[i];
        events[2 * i].type = 1;      
        events[2 * i + 1].x = r[i];
        events[2 * i + 1].type = 0;  
    }

    qsort(events, 2 * n, sizeof(Event), cmp);

    int current = 0, best = 0, point = -1;

    for (i = 0; i < 2 * n; i++) {
        if (events[i].type == 1)
            current++;
        else
            current--;

        if (current > best) {
            best = current;
            point = events[i].x;
        }
    }

    printf("Point = %d\n", point);
    printf("Maximum intervals = %d\n", best);

    return 0;
}
