#include<cstdio>
int n, m, x_start, x_end, y_start, y_end;
long long dp[60][60];
int main()
{
    scanf("%d%d%d%d%d%d", &n, &m, &x_start, &y_start, &x_end, &y_end);
    dp[x_start][y_start]++;
    for (int i = x_start+1; i <= n; i++)
    {
        if(i>x_end)break;
        for (int j = 1; j <= m; j++)
        {
            int a=i-2,b=j-2;
            a*=a>0?1:0;
            b*=b>0?1:0;
            dp[i][j]=dp[a][j-1]+dp[a][j+1]+dp[i-1][b]+dp[i-1][j+2];
        }
    }
    /*for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d ",dp[j+1][i+1]);
        }
        printf("\n\n");
    }
    */
    printf("%lld", dp[x_end][y_end]);
    return 0;
}