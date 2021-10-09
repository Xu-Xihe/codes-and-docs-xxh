#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxe 100005
using namespace std;
int ci,len;
int in[maxe];
int dp[maxe],qi[maxe];
int ans,start,endl;
int main(){
    scanf("%d",&ci);
    for(int zzz = 0; zzz < ci; zzz++)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&len);
        ans=-1e9;
        qi[0]=1;
        endl=start=1;
        for(int i = 1; i <= len; i++)
        {
            scanf("%d",&in[i]);
        }
        for(int i = 1; i <= len; i++)
        {
            if(dp[i-1]>=0){
                qi[i]=qi[i-1];
                dp[i]=dp[i-1]+in[i];
            }
            else {
                dp[i]=in[i];
                qi[i]=i;
            }
            if (dp[i]>ans){
                ans=dp[i];
                start=qi[i];
                endl=i;
            }
        }
        printf("Case %d:\n%d %d %d\n",zzz+1,ans,start,endl);
        if (zzz+1<ci) {
            printf("\n");
        }
    }
    return 0;
}