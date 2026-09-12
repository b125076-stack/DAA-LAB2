#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int E, F;
    printf("Enter number of eggs: ");
    scanf("%d", &E);

    printf("Enter number of floors: ");
    scanf("%d", &F);

    int dp[E + 1][F + 1];

    int i, j, x;

    for(i = 1; i <= E; i++)
        dp[i][0] = 0;

    for(i = 1; i <= E; i++)
        dp[i][1] = 1;

    for(j = 1; j <= F; j++)
        dp[1][j] = j;

    for(i = 2; i <= E; i++)
    {
        for(j = 2; j <= F; j++)
        {
            dp[i][j] = 999999;

            for(x = 1; x <= j; x++)
            {
                int broken = dp[i - 1][x - 1];
                int notBroken = dp[i][j - x];

                int trials = 1 + max(broken, notBroken);

                if(trials < dp[i][j])
                    dp[i][j] = trials;
            }
        }
    }

    printf("\nMinimum number of trials = %d\n", dp[E][F]);

    return 0;
}