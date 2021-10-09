#include<cstdio>
using namespace std;
struct visiter
{
    int time ,start_id, end_id;
}m_in[10004];
int n,m,k,n_in[1005];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&n_in[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&m_in[i].time,&m_in[i].start_id,&m_in[i].end_id);
    }
}