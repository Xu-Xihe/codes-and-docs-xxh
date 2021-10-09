#include <cstdio>
#include <vector>
#include <algorithm>
const int maxn = 5e5 + 9;
int n, m, root, size[maxn], son[maxn], top[maxn], dep[maxn], fa[maxn];
std::vector<int> next[maxn];
inline void dfs1(int now, int deep)
{
    dep[now] = deep;
    int big = 0, ji = 0;
    for (auto i : next[now])
    {
        if (!fa[i])
        {
            fa[i] = now;
            dfs1(i, deep + 1);
            if (size[i] > big)
            {
                big = size[i];
                son[now] = i;
            }
            size[now] += size[i];
        }
    }
    size[now]++;
    return;
}
inline void dfs2(int now, int t, bool big)
{
    top[now] = t;
    if (!son[now])
        return;
    dfs2(son[now], t, 1);
    for (int i : next[now])
    {
        if (i != fa[now] && i != son[now])
        {
            dfs2(i, i, 0);
        }
    }
}
inline int lca(int a, int b)
{
    while (top[a] != top[b])
    {
        if (dep[top[a]] < dep[top[b]])
            std::swap(a, b);
        a = fa[top[a]];
    }
    return dep[a] > dep[b] ? b : a;
}
int main()
{
    scanf("%d%d%d", &n, &m, &root);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        next[a].push_back(b);
        next[b].push_back(a);
    }
    fa[root] = root;
    dfs1(root, 1);
    dfs2(root, root, 0);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}