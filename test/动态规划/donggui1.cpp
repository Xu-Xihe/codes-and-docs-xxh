#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ci,len,v,zhong[1005],jia[1005];
int dp[1005][1005];
int main(){
	scanf("%d",&ci);
	while(ci--){
		scanf("%d%d",&len,&v);
		jia[0]=0;
		zhong[0]=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=len;i++){
			scanf("%d",&jia[i]);
		}
		for(int i=1;i<=len;i++){
			scanf("%d",&zhong[i]);
		}
		for(int i=1;i<=len;i++){
			for(int j=0;j<=v;j++){
				if(zhong[i]>j){
					dp[i][j]=dp[i-1][j];
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-zhong[i]]+jia[i]);
				}
			}
		}
		printf("%d\n",dp[len][v]);
	}
}
