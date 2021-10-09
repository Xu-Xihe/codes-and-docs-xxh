#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <ctime>
const int zhi[] = {2, 3, 5, 7, 11}, maxn = 1e5 + 9;
const long long mode = 20020421;
struct corn
{
    int val[12];
    void operator+=(const corn &b)
    {
        for (int i = 0; i < 5; i++)
        {
            val[zhi[i]] += b.val[zhi[i]];
        }
    }
    corn friend operator-(corn a, const corn b)
    {
        for (int i = 0; i < 5; i++)
        {
            a.val[zhi[i]] -= b.val[zhi[i]];
        }
        return a;
    }
} node[maxn];
int n, m, fa[maxn], root, deep[maxn];
std::vector<int> next[maxn];
std::bitset<maxn> vis;
void show(corn out, int i = 0)
{
    printf("%d  : fa --> %d ,  2: %d    3: %d     5: %d    7: %d    11: %d\n", i, fa[i], out.val[2], out.val[3], out.val[5], out.val[7], out.val[11]);
}
inline corn fix(int in)
{
    corn ans;
    for (int i = 0; i < 5; i++)
    {
        ans.val[zhi[i]] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        while (!(in % zhi[i]))
        {
            ans.val[zhi[i]]++;
            in /= zhi[i];
        }
    }
    //show(ans);
    return ans;
}
inline unsigned long long mi(int n, int m, unsigned long long mod, unsigned long long sum = 1, unsigned long long ans = 1)
{
    sum = n;
    while (m)
    {
        if (m & 1)
        {
            ans *= sum;
            ans %= mod;
        }
        sum *= sum;
        sum %= mod;
        m >>= 1;
    }
    return ans;
}
inline void dfs(int now, int dep)
{
    deep[now] = dep;
    for (auto i : next[now])
    {
        if (!vis[i])
        {
            fa[i] = now;
            node[i] += node[now];
            vis[i] = 1;
            dfs(i, dep + 1);
        }
    }
}
inline unsigned long long he(corn in)
{
    unsigned long long ans = 1;
    for (int i = 0; i < 5; i++)
    {
        //printf("ceshi   %d  %d  %d\n", ans, mi(zhi[i], in.val[zhi[i]] + 1, mode) - 1, mi(zhi[i] - 1, mode - 2, mode));
        ans *= (mi(zhi[i], in.val[zhi[i]] + 1, mode) - 1) * mi(zhi[i] - 1, mode - 2, mode);
        ans %= mode;
    }
    return ans;
}
int main()
{
    //freopen("onlinejudge.in", "r", stdin);
    //freopen("onlinejudge.out", "w", stdout);
    //srand(time(NULL));
    scanf("%d%d", &n, &m);
    root = n / 2;
    vis[root] = 1;
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        node[i] = fix(a);
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        next[a].push_back(b);
        next[b].push_back(a);
    }
    dfs(root, 1);
    /*for (int i = 0; i < n; i++)
    {
        show(node[i + 1], i + 1);
    }*/
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (deep[x] > deep[y])
            std::swap(x, y);
        corn sum = node[y] - node[fa[x]];
        //show(sum);
        printf("%d\n", he(sum));
    }
    return 0;
}