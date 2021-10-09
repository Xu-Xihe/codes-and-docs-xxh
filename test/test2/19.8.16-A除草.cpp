#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N = 30000;
int n;
int dp[N][3];//dp[i][0]代表没拿刀,dp[i][1]代表拿刀了
int st[N],dt[N],sd[N];
typedef long long ll;
ll ans;
int main(){
    while(~scanf("%d",&n)&&n){
        ans=0;
        memset(dt,0,sizeof dt);
        memset(st,0,sizeof dt);
        memset(sd,0,sizeof sd);
        memset(dp,0,sizeof dp);
        int a,b,c;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a,&b,&c);
            dt[i]=a;
            st[i]=b;
            sd[i]=c;
        }
        dp[1][0]=st[1];
        dp[1][1]=dt[1]+sd[1];
        for(int i=2;i<=n;i++){
            dp[i][0]=min(dp[i-1][0]+st[i],dp[i-1][1]+sd[i]+st[i]);
            dp[i][1]=min(dp[i-1][1]+dt[i],dp[i-1][0]+sd[i]+dt[i]);
        }
        ans=min(dp[n][0],dp[n][1]);
        cout<<ans<<endl;
    }
    return 0;
}
        /*
        bool knife=0;//没拿刀
        for(int i=1;i<=n;i++){
            if(knife==0){
                if(dt[i]+sd[i]<st[i]){
                    ans+=dt[i]+sd[i];
                    knife=1;
                }
                else{
                    ans+=st[i];
                }
            }
            else{
                if(st[i]+sd[i]<dt[i]){
                    ans+=st[i]+sd[i];
                    knife=0;
                }
                else{
                    ans+=dt[i];
                }
            }
        }
        */