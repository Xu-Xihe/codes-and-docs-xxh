#include <cstdio>
#include <vector>
const int maxe = 2000;
int n, ans;
std::vector<int> edge[maxe];
bool ji[maxe];
char in[maxe];
inline void dfs(int now, int deep)
{
    if (deep == 4)
    {
        ans++;
        return;
    }
    ji[now] = 1;
    int len = edge[now].size();
    for (int i = 0; i < len; i++)
    {
        if (!ji[edge[now][i]])
        {
            dfs(edge[now][i], deep + 1);
        }
    }
    ji[now] = 0;
}
int main()
{
    freopen("tour.in", "r", stdin);
    freopen("tour.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", in);
        for (int j = 0; j < n; j++)
        {
            if (in[j] == '1')
                edge[i].push_back(j + 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 1);
    }
    printf("%d", ans);
    return 0;
}