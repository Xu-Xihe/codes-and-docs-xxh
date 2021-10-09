#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
const int maxe = 1e5 + 9;
int n, m,fa[maxe],top[maxe],val[maxe],lens,dep[maxe],ask,sign;
struct nt
{
    int id, val;
};
std::vector<nt> next[maxe];
inline void dfs(int now,int tp)
{
    if(dep[now]%lens==0)
        tp = now;
    top[now] = tp;
    for (auto i:next[now])
    {
        if(i.id!=fa[now])
        {
            fa[i.id] = now;
            val[i.id] = val[now] + i.val;
            dep[i.id] = dep[now] + 1;
            dfs(i.id, tp);
        }
    }
}
inline int find(int end,int cmp)
{
    while(val[top[end]]>cmp)
    {
        end = fa[top[end]];
    }
    while(val[end]>cmp)
    {
        end = fa[end];
    }
    return end;
}
void show(char *p,int *put)
{
    printf("\n%s:\n", p);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", put[i + 1]);
    }
    printf("\n");
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        next[a].push_back(nt{b, t});
        next[b].push_back(nt{a, t});
    }
    lens = sqrt(n);
    dfs(1, 1);
    while (m--)
    {
        scanf("%d%d", &sign, &ask);
        ask /= 2;
        if(val[sign]<=ask)
        {
            printf("%d\n", sign);
            continue;
        }
        printf("%d\n", find(sign, ask));
    }
    return 0;
}