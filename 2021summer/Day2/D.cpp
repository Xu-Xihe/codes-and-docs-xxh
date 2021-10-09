#include <cstdio>
#include <queue>
const int maxn = 600;
int len, connect[maxn][maxn];
bool vis[maxn];
struct top
{
    int dis, num;
    bool friend operator<(top a, top b)
    {
        return a.dis > b.dis;
    }
};
std::priority_queue<top> next;
int prim()
{
    int ans = 0, now = 0;
    for (int i = 0; i <= len; i++)
    {
        for (int i = 0; i <= len; i++)
        {
            if (!vis[i])
            {
                next.push(top{connect[now][i], i});
            }
        }
        if (next.empty())
            return ans;
        top a = next.top();
        next.pop();
        if (!vis[a.num])
        {
            ans += a.dis;
            now = a.num;
            vis[now] = 1;
            i--;
        }
    }
}
int main()
{
    scanf("%d", &len);
    for (int i = 1; i <= len; i++)
    {
        int a;
        scanf("%d", &a);
        connect[0][i] = a;
        connect[i][0] = a;
    }
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= len; j++)
        {
            scanf("%d", &connect[i][j]);
        }
    }
    printf("%d",prim());
    return 0;
}