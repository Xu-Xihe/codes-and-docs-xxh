#include <cstdio>
#include <cstring>
const int maxe = 1009;
int n, m, point[maxe], ans;
bool solve[maxe][maxe], visit[maxe];
bool dfs(int now)
{
    for (int i = 0; i < n; i++)
    {
        if (!visit[i] && solve[now][i])
        {
            visit[i] = true;
            if (point[i] == 0 || dfs(point[i]))
            {
                point[i] = now;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        solve[i][a] = 1;
        solve[i][b] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        std::memset(visit, 0, sizeof(visit));
        if (dfs(i))
            ans++;
        else
            break;
    }
    printf("%d", ans);
    return 0;
}