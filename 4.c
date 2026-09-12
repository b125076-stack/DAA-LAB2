#include <stdio.h>
#include <string.h>

#define MAX 16
#define STATES (1 << MAX)

int visited[STATES];
int parent[STATES];
int moveMade[STATES];

int validMove(int state, int i, int n)
{
    
    if(i == n - 1)
        return 1;
    if(!(state & (1 << (i + 1))))
        return 0;

    for(int j = i + 2; j < n; j++)
    {
        if(state & (1 << j))
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    printf("Enter number of switches (max 15): ");
    scanf("%d", &n);

    int start = (1 << n) - 1;
    int goal = 0;

    int queue[STATES];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;
    parent[start] = -1;

    while(front < rear)
    {
        int state = queue[front++];

        if(state == goal)
            break;

        for(int i = 0; i < n; i++)
        {
            if(validMove(state, i, n))
            {
                int next = state ^ (1 << i);

                if(!visited[next])
                {
                    visited[next] = 1;
                    parent[next] = state;
                    moveMade[next] = i + 1;
                    queue[rear++] = next;
                }
            }
        }
    }

    if(!visited[goal])
    {
        printf("No solution.\n");
        return 0;
    }

    int path[MAX];
    int count = 0;
    int current = goal;

    while(parent[current] != -1)
    {
        path[count++] = moveMade[current];
        current = parent[current];
    }

    printf("\nMinimum moves = %d\n", count);

    printf("Switches toggled:\n");

    for(int i = count - 1; i >= 0; i--)
        printf("%d ", path[i]);

    printf("\n");

    return 0;
}