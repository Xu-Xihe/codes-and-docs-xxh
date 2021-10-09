#include<vector>
#include<cstdio>
#define maxe 300005
using namespace std;
int n,m,ans[maxe];
bool is[maxe];
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n-1; i++)
    {
        int a;
        scanf("%d%d",&a,&a);
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d",&a);
        is[i+1]=a==0?true:false;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        ans[a]+=is[a]?1:0;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",ans[i+1]);
    }
    
    return 0;
}