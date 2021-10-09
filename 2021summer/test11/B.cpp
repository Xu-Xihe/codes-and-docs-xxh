#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
#include <iostream>
const int maxe = 1000;
int n, m, tog[maxe][maxe], fa[maxe], val[maxe], wei[maxe], dep[maxe], ans = 2e9;
std::vector<int> next[maxe];
struct nd
{
    int wei;
    std::bitset<20> key;
} node[maxe];
inline void dfs(int now, nd last)
{
    dep[now] = dep[fa[now]] + 1;
    node[now] = last;
    node[now].wei += wei[now];
    node[now].key[val[now]] = 1;
    for (auto i : next[now])
    {
        if (i != fa[now])
        {
            fa[i] = now;
            dfs(i, node[now]);
        }
    }
}
inline int lca(int a, int b)
{
    while (a != b)
    {
        if (dep[a] < dep[b])
            std::swap(a, b);
        a = fa[a];
    }
    return a;
}
std::bitset<20> cmp;
std::bitset<20> an;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &val[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &wei[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        next[a].push_back(b);
        next[b].push_back(a);
    }
    dfs(1, nd{});
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            tog[i][j] = lca(i, j);
            tog[j][i] = tog[i][j];
            //printf("lca  :  %d  %d  --- %d\n", i, j, tog[i][j]);
        }
    }
    for (int i = 0; i <= m; i++)
        cmp[i] = 1;
    //show("fa", fa);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int z = j; z <= n; z++)
                //std::cout << node[i].key << "   " << node[j].key << "   " << cmp << "  " << ((node[i].key | node[j].key) & cmp) << "  " << ans << "\n";
                if (((node[i].key | node[j].key | node[z].key) & cmp) == cmp)
                {
                    ans = std::min(ans, node[i].wei + node[j].wei + node[z].wei - node[tog[i][j]].wei - node[tog[j][z]].wei - node[tog[i][z]].wei);
                }
        }
    }
    printf("%d\n", ans);
    return 0;
}