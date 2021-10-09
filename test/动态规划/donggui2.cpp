#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int len,v,w[30000],d[31000];
int dp[130000];
int main(){
	scanf("%d%d",&len,&v);
	for(int i=0;i<len;i++){
		scanf("%d%d",&w[i],&d[i]);
	}
	for(int i=0;i<len;i++){
		for(int j=v;j>=0;j--){
			if(w[i]<=j){
				dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
			}
		}
	}
	printf("%d",dp[v]);
	return 0;
}
