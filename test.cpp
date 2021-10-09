#include <cstdio>
#include <algorithm>
using std::min;
const int maxe = 3000, INF = 1000000009;
int n, m, dp[maxe][maxe], pot[maxe][maxe];
inline void pr_dis(int dp[maxe][maxe]) //最短路径输出
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}
inline void pr_way(int sta, int end) //递归重建路径
{
    if (pot[sta][end] == 0) //若有边连接,则终止递归
        return;
    pr_way(sta, pot[sta][end]);   //递归输出左侧
    printf("%d ", pot[sta][end]); //输出本位
    pr_way(pot[sta][end], end);   //递归输出右侧
}
int main()
{
    scanf("%d%d", &n, &m);
    int sta;
    scanf("%d", &sta);
    for (int i = 1; i <= n; i++) //初始化
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = i == j ? 0 : INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        dp[a][b] = min(dp[a][b], v); //判断重边
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dp[i][j] > dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    pot[i][j] = k; //更新节点记录
                }
            }
        }
    }
    for (int i = 0; i < n; i++) //输出
    {
        for (int j = 0; j < n; j++)
        {
            printf("\n%d  %d :  ", i + 1, j + 1);
            pr_way(i + 1, j + 1);
        }
    }
    printf("\n\n");
    pr_dis(dp); //输出
    return 0;
}