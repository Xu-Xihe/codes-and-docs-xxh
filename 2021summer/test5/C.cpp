#include <cstdio>
#include <vector>
#include <algorithm>
const int maxe = 5e4 + 9;
int len, val[maxe], ci[maxe], k, root, fa[maxe], deep[maxe], size[maxe], top[maxe], fson[maxe];
bool isf[maxe];
std::vector<int> in[maxe];
inline int dfs_1(int now, int dad, int dp)
{
    fa[now] = dad;
    deep[now] = dp;
    int sum = 0, len = in[now].size(), big = 0, ji = 0, lin;
    for (int i = 0; i < len; i++)
    {
        if (in[now][i] == dad)
            continue;
        lin = dfs_1(in[now][i], now, dp + 1);
        if (big < lin)
        {
            big = lin;
            ji = in[now][i];
        }
        sum += lin;
    }
    size[now] = sum + 1;
    fson[now] = ji;
    isf[ji] = 1;
    return size[now];
}
inline void dfs_2(int now)
{
    if(now==fson[fa[now]])
        top[now] = top[fa[now]];
    else
        top[now] = now;
    int n = in[now].size();
    for (int i = 0; i < n; i++)
    {
        if(in[now][i]==fa[now])
            continue;
        dfs_2(in[now][i]);
    }
}
inline int LCA(int a, int b)
{
    for (; top[a] != top[b] ; deep[top[a]] > deep[top[b]] ? a = fa[top[a]] : b = fa[top[b]])
        ;
        //printf("LCAS    %d  %d\n",a,b);
    return deep[a] < deep[b] ? a : b;
}
inline int ans(int sta, int end)
{
    int out = val[sta] + val[end];
    //printf("in   %d  %d  ", sta, end);
    int tfa = LCA(sta, end);
    int now = sta;
    //printf("  %d  out\n", tfa);
    while (now != tfa)
    {
        now = fa[now];
        if (((deep[sta] - deep[now]) % k) == 0&&now!=end)
            out += val[now];
        //printf("ceshi   %d  %d  %d  %d  \n", now, deep[sta], deep[now]);
    }
    now = fa[end];
    if(end==tfa)
        return out;
    while (now != tfa)
    {
        if (((deep[now] - deep[tfa] + deep[sta] - deep[tfa]) % k) == 0)
            out += val[now];
        now = fa[now];
    }
    return out;
}
void show(char *p, int *out, int lo)
{
    printf("\n%s  :\n", p);
    for (int i = 0; i < lo; i++)
    {
        printf("%d ", out[i + 1]);
    }
    printf("\n");
}
int main()
{
    freopen("dust.in", "r", stdin);
    freopen("dust.out", "w", stdout);
    scanf("%d", &len);
    srand(1468);
    root = rand() % len + 1;
    for (int i = 1; i <= len; i++)
    {
        scanf("%d", &val[i]);
    }
    for (int i = 1; i < len; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        in[a].push_back(b);
        in[b ].push_back(a);
    }
    dfs_1(root, root, 1);
    dfs_2(root);
    for (int i = 1; i <= len; i++)
    {
        scanf("%d", &ci[i]);
    }
    /*printf("root:  %d\n", root);
    show("fa", fa, len);
    show("deep", deep, len);
    show("size", size, len);
    show("top", top, len);
    show("fson", fson, len);
    for (int i = 1; i <= len; i++)
        printf("%d ", isf[i]);
    printf("\n");*/
    for (int i = 1; i < len; i++)
    {
        scanf("%d", &k);
        printf("%d\n", ans(ci[i], ci[i + 1]));
    }
    return 0;
}