#include<cstdio>
#include<vector>
#define maxe 200005
using namespace std;
int dp[maxe],len,k,p;
long long ans;
vector<int>color[55];
long long manyin(int color_id){
    long long ans=0;
    for (int zl = 0; zl < color[color_id].size()-1; zl++)
    {
        for (int i = 1; i < color[color_id].size()-zl; i++)
        {
            if(dp[color[color_id][zl+i]]-dp[color[color_id][zl]-1]>0){
                ans+=color[color_id].size()-zl-i;
                //printf("%d %d->%d\n\n",zl,i,color[color_id].size()-zl-i);
                break;
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d%d%d",&len,&k,&p);
    for (int i = 1; i <= len; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        dp[i]=b<=p?dp[i-1]+1:dp[i-1];
        color[a].push_back(i);
    }
    for (int jishu = 0; jishu < k; jishu++)
    {
        ans+=manyin(jishu);
        //printf("%d->%d\n",jishu,ans);
    }
    printf("%lld\n",ans);
    return 0;
}