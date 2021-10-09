#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define maxe 10000
using namespace std;
struct node
{
    int next_id ,valu;
};
struct way
{
    int start_id,end_id;
}ways[maxe];
int find_max(int len,int in[],bool hh[]){
    int max=-1000,ji=0;
    for (int i = 0; i < len; i++)
    {
        if(in[i]>max&&!hh[i]){
            max=in[i];
            ji=i;
        }
    }
    return ji;
}
vector<node>edge[maxe];
bool isit[maxe];
int diji[maxe],m,n,len;
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        node d;
        d.next_id=b;
        d.valu=c;
        edge[a].push_back(d);
        d.next_id=a;
        edge[b].push_back(d);
    }
    scanf("%d",&len);
    while (len--)
    {
        for(int i=0;i<=n;i++)diji[i]=-1;
        memset(isit,0,sizeof(isit));
        int st_id,en_id;
        scanf("%d%d",&st_id,&en_id);
        diji[st_id]=1e9;
        isit[st_id]=1;
        int now_id=st_id;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < edge[now_id].size(); j++)
            {
                diji[edge[now_id][j].next_id]=min(edge[now_id][j].valu,diji[now_id]);
            }
            now_id=find_max(n,diji,isit);
            isit[now_id]=1;
        }
        printf("%d\n",diji[en_id]);
    }
    return 0;
}