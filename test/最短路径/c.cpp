#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct id
{
    int node,vule;
    friend bool operator<(id a,id b){
        return a.vule>b.vule;
    }
};
vector<id>ways[1100];
vector<int>endl;
int n,m,s,w,dist[1101];
int sfa(int start){
    priority_queue<id>runing;
    dist[start]=0;
    id a;
    a.vule=0;
    a.node=start;
    runing.push(a);
    while (!runing.empty())
    {
        id fi=runing.top();
        runing.pop();
        int len=ways[fi.node].size();
        for (int i = 0; i < len; i++)
        {
            if(dist[fi.node]+ways[fi.node][i].vule<dist[ways[fi.node][i].node]){
                dist[ways[fi.node][i].node]=dist[fi.node]+ways[fi.node][i].vule;
                a.node=ways[fi.node][i].node;
                a.vule=dist[ways[fi.node][i].node];
                runing.push(a);
            }
        }
    }
    int small =1e9;
    for (int i = 0; i < endl.size(); i++)
    {
        small=min(dist[endl[i]],small);
    }
    return small;
}       
int main(){
    while (~scanf("%d%d%d",&n,&m,&s))
    {
        for(int i=0;i<=n;i++){
            dist[i]=1e9;
            ways[i].clear();
        }
        endl.clear();
        for (int i = 0; i < m; i++)
        {
            id a;
            int s,e;
            scanf("%d%d%d",&s,&e,&a.vule);
            a.node=s;
            ways[e].push_back(a);
            a.node=e;
            ways[e].push_back(a);
        }
        scanf("%d",&w);
        for (int i = 0; i < w; i++)
        {
            int a;
            scanf("%d",&a);
            endl.push_back(a);
        }
        int ans=sfa(s);
        printf("%d\n",ans==1e9?-1:ans);
    }
    return 0;
}