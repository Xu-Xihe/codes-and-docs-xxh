#include<cstdio>
#include<algorithm>
using namespace std;
int n,v[200];
long long w[200],m;
/*int main(){
    while (~scanf("%d%lld",&n,&m))
    {
        long long s=1e9;
        for (int i = 0; i < n; i++)
        {
           scanf("%d",&w[i]);
           s=min(s,w[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&v[i]);
        }
        for (int now = s+1; ; now++)
        {
            long long cost=0;
            for (int i = 0; i < n; i++)
            {
                cost+=now-w[i]>0?(now-w[i])*v[i]:0;
            }
            if(cost>m){
                printf("%d\n",now-1);
                break;
            }
        }
    }
    return 0;
}*/
int fen(int s,int e){
    return (s+e)/2;
}
bool isok(int now){
    long long cost=0;
    for (int i = 0; i < n; i++)
    {
        cost+=now-w[i]>0?(now-w[i])*v[i]:0;
    }
    return cost>m?false:true;
}
int main(){
    while (~scanf("%d%lld",&n,&m))
    {
        long long s=1e9;
        for (int i = 0; i < n; i++)
        {
           scanf("%lld",&w[i]);
           s=min(s,w[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&v[i]);
        }
        long long sid=1,eid=m;
        while (1)
        {
            if(isok(fen(sid,eid)))sid=fen(sid,eid);
            else eid=fen(sid,eid);
            if(sid+1==eid){
                printf("%lld\n",sid);
                break;
            }
        }
    }
    
}