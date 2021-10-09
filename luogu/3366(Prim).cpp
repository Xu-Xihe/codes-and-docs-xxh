#include <cstdio>
const int maxe = 6000;
int n, m, head[maxe], cnt=1;
bool vis[maxe];
struct node
{
    int w, next, v;
} edge[400009];
void add_edge(int u, int v, int m)
{
    edge[cnt].w = m;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    return;
}
int prim()
{
    int dis[maxe], ans = -1e9;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 2e9;
    }
    int k=1, min;
    vis[1]=1;
    for (int i = 0; i < n; i++)
    {
        min = 1e9;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        }
        if(min==1e9&&k!=1)
        {
            return 0;
        }
        ans += min;
        vis[k]=1;
        for (int i = head[k]; i ; i = edge[i].next)
        {
            if(!vis[edge[i].v]&&dis[edge[i].v]>edge[i].w)
            {
                dis[edge[i].v]=edge[i].w;
            }
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v, m;
        scanf("%d%d%d", &u, &v, &m);
        add_edge(u, v, m);
        add_edge(v, u, m);
    }
    int ans=prim();
    if(ans)printf("%d",ans);
    else printf("orz");
    return 0;
}