#include <cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
struct edge
{
    int a, b, weigh;
}ways[220000];
int fa[10000], n, m,ans;
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void together(int a, int b)
{
    int fx = find(a), fy = find(b);
    if(fx!=fy)fa[fx] = fy;
    return;
}
bool cmp(edge a, edge b)
{
    return a.weigh < b.weigh;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n+5; i++)
    {
        fa[i]=i;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &ways[i].a, &ways[i].b, &ways[i].weigh);
    }
    std::sort(ways,ways+m,cmp);
    for (int i = 0; i < m; i++)
    {
        if(find(ways[i].a)!=find(ways[i].b))
        {
            //printf("ce: %d  %d\n\n",ways[i].a,ways[i].b);
            ans+=ways[i].weigh;
            together(find(ways[i].a),find(ways[i].b));
        }
    }
    if(ans!=0)printf("%d",ans);
    else printf("orz");
    return 0;
}