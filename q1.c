#include<stdio.h>
int main()
{
    int n ;
    printf(" Enter n: ");
    scanf("%d",&n);

    int dp[n+1];

    if(n==0){
       printf(" Fibonacci number =0\n ");
       return 0;

    }

    dp[0]=0;
    dp[1]=1;

    for(int i=2 ; i<=n; i++)
    {
        dp[i]=dp[i-1]+ dp[i-2];

        }
        printf(" fibonacci number = %d\n ", dp[n]);



    return 0;
}