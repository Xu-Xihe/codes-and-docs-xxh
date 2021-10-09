#include<cstdio>
#include<algorithm>
#include<vector>
#define maxe_edge 50005
#define maxe_id 10005
using namespace std;
struct edge
{
    int s_id , e_id , valu;
}edges[maxe_edge];
struct line
{
    int s_id,e_id;
}lines[30099];
struct node
{
    int next_id,valu;
};
vector<node>nodes[maxe_id];
bool cmp(edge a,edge b){
    return a.valu > b.valu;
}
int n,m;
int fa[maxe_id],q;
int deep[maxe_id];
bool ji[maxe_id];
int father[maxe_id];
int find(int in){
    return in==fa[in]?in:fa[in]=find(fa[in]);
}
void together (int a,int b){
    int x=find(a),y=find(b);
    if (x!=b)
    {
        fa[x]=y;
    }
}
void dfs(int now_id){
    for (int i = 0; i < nodes[now_id].size(); i++)
    {
        if(!ji[nodes[now_id][i].next_id]){
            deep[nodes[now_id][i].next_id]=deep[now_id]+1;
            father[nodes[now_id][i].next_id]=now_id;
            ji[nodes[now_id][i].next_id]=true;
            dfs(nodes[now_id][i].next_id);
        }
    }
}
int finder(int a,int b){
    for (int i = 0; i < nodes[a].size(); i++)
    {
        if(nodes[a][i].next_id==b)
            return nodes[a][i].valu;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        fa[i]=i;
        father[i]=i;
    }
    for (int i = 0; i < m; i++)
    {
        edge a;
        scanf("%d%d%d",&a.s_id,&a.e_id,&a.valu);
        a.s_id--;
        a.e_id--;
        edges[i]=a;
    }
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        line a;
        scanf("%d%d",&a.e_id,&a.s_id);
        a.s_id--;
        a.e_id--;
        lines[i]=a;
    }
    sort(edges,edges+m,cmp);
    for (int i = 0; i < m; i++)
    {
        if(find(edges[i].s_id)!=find(edges[i].e_id)){
            together(edges[i].s_id,edges[i].s_id);
            node a;
            a.valu=edges[i].valu;
            a.next_id=edges[i].e_id;
            nodes[edges[i].s_id].push_back(a);
            a.next_id=edges[i].s_id;
            nodes[edges[i].e_id].push_back(a);
        }
    }
    ji[0]=true;
    dfs(0);
    /*for (int i = 0; i < n; i++)
    {
        printf("%d->%d->%d\n",i,deep[i],father[i]);
    }
    */
    for (int i = 0; i < q; i++)
    {
        int now_a=lines[i].s_id,now_b=lines[i].e_id;
        int now_da=deep[now_a],now_db=deep[now_b];
        int ans=1e9;
        while (1)
        {
            //printf("%d->%d\n%d->%d\n%d\n\n",now_a,now_da,now_b,now_db,ans);
            if (now_da>now_db)
            {
                now_da--;
                ans=min(ans,finder(now_a,father[now_a]));
                now_a=father[now_a];
            }
            if(now_da<now_db)
            {
                now_db--;
                ans=min(ans,finder(now_b,father[now_b]));
                now_b=father[now_b];
            }
            //printf("%d->%d\n%d->%d\n%d\n\n",now_a,now_da,now_b,now_db,ans);
            if(now_da==now_db&&father[now_a]!=father[now_b]){
                printf("-1\n");
                break;
            }
            else {
                printf("%d\n",ans);
                break;
            }
        }
    }
    return 0;
}