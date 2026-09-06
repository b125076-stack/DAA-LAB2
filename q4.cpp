 #include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int arr[], int n)
{
    int dp[n][n];

    for (int i = 1; i < n; i++)
        dp[i][i] = 0;


    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

          
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int arr[] = {10, 30, 5, 60};

    int n = sizeof(arr) / sizeof(arr[0]);

    int result = matrixChainMultiplication(arr, n);

    cout << "Minimum number of scalar multiplications: "
         << result << endl;

    return 0;
}