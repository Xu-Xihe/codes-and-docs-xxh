#include <cstdio>
#include <algorithm>
using std::max;
int n, m, in[55][55], dp[55][55][55];
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &in[i][j]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m  && i + j - k > 0; k++)
            {
                if(i+j-k>n)
                    continue;
                dp[i][j][k] = max(max(dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]), max(dp[i - 1][j][k], dp[i][j - 1][k])) + in[i][j] + in[k][i + j - k];
                if (i == k && j == i + j - k)
                    dp[i][j][k] -= in[i][j];
                //printf("ce:-->    %d   %d  %d  %d\n", i, j, k, dp[i][j][k]);
            }
        }
    }
    printf("%d", dp[m][n][m]);
    return 0;
}