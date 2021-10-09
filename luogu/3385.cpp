#include <cstdio>
#include <vector>
#include <queue>
const int maxe = 2e3 + 9;
struct node
{
    int next, val;
};
std::vector<node> edges[maxe];
int n, m, dis[maxe], T;
bool ji[maxe];
std::vector<int> sta;
inline void found()
{
    bool chu[maxe];
    std::queue<int> run;
    for (int i = 0; i < n; i++)
    {
        chu[n + 1] = 0;
    }
    while (!run.empty())
        run.pop();
    run.push(1);
    while (!run.empty())
    {
        int now = run.front();
        run.pop();
        sta.push_back(now);
        chu[now] = 1;
        int len = edges[now].size();
        for (int i = 0; i < len; i++)
        {
            if (!chu[edges[now][i].next])
                run.push(chu[edges[now][i].next]);
        }
    }
}
inline bool dfs(int x)
{
#define id edges[x][i]
    if (ji[x] && dis[x] < 0)
        return true;
    ji[x] = 1;
    int len = edges[x].size();
    for (int i = 0; i < len; i++)
    {
        printf("now: %d  %d  %d  %d\n", x, id.next, dis[x], dis[x] + id.val);
        if (dis[id.next] > dis[x] + id.val)
        {
            dis[id.next] = dis[x] + id.val;
            if (dfs(id.next))
                return true;
        }
    }
    ji[x] = 0;
    return false;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            dis[i] = ji[i] = 0;
        }
        while (m--)
        {
            int a, b, v;
            scanf("%d%d%d", &a, &b, &v);
            edges[a].push_back(node{b, v});
            if (v >= 0)
                edges[b].push_back(node{a, v});
        }
        found();
        int len = sta.size();
        bool ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (dfs(sta[i]))
            {
                ans = 1;
                break;
            }
        }
        printf("%d\n", len);
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}