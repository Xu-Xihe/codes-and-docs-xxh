#include<cstdio>
#include<queue>
#include<vector>
#define maxe 2100
using namespace std;
struct xxh
{
    int nodeid,valu;
    friend bool operator<(xxh a,xxh b){
        return a.valu>b.valu;
    }
};
struct way
{
    int nodeid,valu;
};
vector<way>node[maxe];
priority_queue<xxh>runing;
int n,t,dist[maxe];
int main(){
    while (~scanf("%d%d",&t,&n))
    {
       for(int i=0;i<n;i++)dist[i+1]=1e9;
       for (int i = 0; i < t; i++)
       {
            int a,b,c;
            way d;
            scanf("%d%d%d",&a,&b,&c);
            d.nodeid=a;
            d.valu=c;
            node[b].push_back(d);
            d.nodeid=b;
            node[a].push_back(d);
       }
       xxh fir;
       fir.nodeid=n;
       fir.valu=0;
       dist[n]=0;
       runing.push(fir);
       while (!runing.empty())
       {
            xxh fir=runing.top();
            runing.pop();
            for (int i = 0; i < node[fir.nodeid].size(); i++)
            {
                int a=node[fir.nodeid][i].valu+dist[fir.nodeid];
                if (a<dist[node[fir.nodeid][i].nodeid])
                {
                    dist[node[fir.nodeid][i].nodeid]=a;
                    xxh lin;
                    lin.nodeid=node[fir.nodeid][i].nodeid;
                    lin.valu=dist[node[fir.nodeid][i].nodeid];
                    runing.push(lin);
                }
            }
       }
       printf("%d\n",dist[1]);
    }
    return 0;
}