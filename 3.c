#include <stdio.h>

#define MAX 30

long long dp[MAX];
int split[MAX];

void solve(int n, char from, char to, char aux1, char aux2)
{
    if(n == 0)
        return;

    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    int k = split[n];

    solve(k, from, aux1, to, aux2);

    /* Move remaining n-k disks using 3 pegs */
    void hanoi(int d, char a, char b, char c)
    {
        if(d == 0)
            return;

        hanoi(d - 1, a, c, b);
        printf("Move disk %d from %c to %c\n", d, a, b);
        hanoi(d - 1, c, b, a);
    }

    hanoi(n - k, from, to, aux2);

    solve(k, aux1, to, from, aux2);
}

int main()
{
    int n = 8;
    int i, k;

    dp[0] = 0;
    dp[1] = 1;

    for(i = 2; i <= n; i++)
    {
        dp[i] = 999999999;

        for(k = 1; k < i; k++)
        {
            long long moves = 2 * dp[k] + ((1LL << (i-k)) - 1);

            if(moves < dp[i])
            {
                dp[i] = moves;
                split[i] = k;
            }
        }
    }

    printf("Minimum moves for %d disks = %lld\n", n, dp[n]);

    return 0;
}