#include<cstdio>
#include<algorithm>
#define maxe 10000000
using namespace std;
int n,m;
long long a[maxe];
int ans,ans_s[maxe];
long long SUM(int now,int start_id){
    if(start_id<n-1){
        return a[start_id]+now*SUM(now,start_id+1);
        //printf("%d->%d\n",start_id,lin);
    }
    else return a[start_id]+now*a[n];
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i <= n; i++)
    {
        scanf("%lld",&a[i]);
    }
    for (int now = 1; now <= m; now++)
    {
        //printf("%d->%d\n",now,SUM(now,0));
        if(SUM(now,0)==0)ans_s[ans++]=now;
    }
    sort(ans_s,ans_s+ans);
    printf("%d\n",ans);
    for (int i = 0; i < ans; i++)
    {
        printf("%d\n",ans_s[i]);
    }
    return 0;
}