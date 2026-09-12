#include <stdio.h>
#include <stdlib.h>

struct Person
{
    char name[50];
    int birth;
    int death;
};

struct Event
{
    int year;
    int type;
};

int compare(const void *a, const void *b)
{
    struct Event *x = (struct Event *)a;
    struct Event *y = (struct Event *)b;

    if(x->year != y->year)
        return x->year - y->year;

    return x->type - y->type;
}

int main()
{
    int n;

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    struct Person p[n];
    struct Event events[2 * n];

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter name: ");
        scanf("%s", p[i].name);

        printf("Enter birth year: ");
        scanf("%d", &p[i].birth);

        printf("Enter death year: ");
        scanf("%d", &p[i].death);

        events[2*i].year = p[i].birth;
        events[2*i].type = 1;      

        events[2*i+1].year = p[i].death;
        events[2*i+1].type = 0;   

    qsort(events, 2*n, sizeof(struct Event), compare);

    int alive = 0;
    int maxAlive = 0;
    int bestYear = 0;

    for(int i = 0; i < 2*n; i++)
    {
        if(events[i].type == 0)
            alive--;
        else
        {
            alive++;

            if(alive > maxAlive)
            {
                maxAlive = alive;
                bestYear = events[i].year;
            }
        }
    }

    printf("\nBest year = %d\n", bestYear);
    printf("Maximum scientists alive = %d\n", maxAlive);

    return 0;
}