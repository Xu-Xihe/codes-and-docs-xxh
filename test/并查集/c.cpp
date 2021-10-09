#include <cstdio>
#include <cstring>
#define maxe 50005
using namespace std;
int fa[maxe];
int rank_x[maxe];
void Init(int x)
{
    for(int i=1; i<=x; i++)
    {
        fa[i] = i;
    }
    memset(rank_x, 0, sizeof(rank_x));
}
 
int Find(int x)
{
    if(fa[x] != x)
    {
        int fx = Find(fa[x]);
        rank_x[x] = (rank_x[x]+rank_x[fa[x]]) % 3;
        fa[x]=fx;
    }
    return fa[x];
}
 
bool Union(int x, int y, int type)
{
    int fx = Find(x);
    int fy = Find(y);
    if(fx == fy)
    {
        if((rank_x[y]-rank_x[x]+3)%3 != type)
            return true;
        return false;
    }
    fa[fy] = fx;
    rank_x[fy] = (rank_x[x]-rank_x[y]+3+type) % 3;
    return false;
}
int n,m,d,x,y; 
int main()
{
    scanf("%d%d",&m, &n);
    int sum = 0;
    Init(m);
    while(n--)
    {
        scanf("%d%d%d",&d,&x,&y);
        if(x>m || y>m || (x==y && d==2))
            sum++;
        else if(Union(x, y, d-1))
            sum++;
    }
    printf("%d\n",sum);
    return 0;
}