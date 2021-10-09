#include<bits/stdc++.h>
using namespace std;
int len,jia[1005],v,maxe;
int d[1005];
int donggui(int len,int v,int w[],int d[]){
	dp[1005][1005];
	for(int i=0;i<len;i++){
		for(int j=v;j>=0;j--){
			if(w[i]<=j){
				dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
			}
		}
	}
	return dp[v];
}
int main(){
	while(1){
		scanf("%d",&len);
		if(len==0)return 0;
		for(int i=0;i<len;i++){
			scanf("%d",&jia[i]);
			if(jia[i]>maxe){
				maxe=jia[i];
			}
		}
		scanf("%d",&v);
		v-=5;
		len--;
		for(int i=1,a=1,j=0;j<len;i++){
			if(jia[j]==maxe&&a){
				a=0;
				j++;
			}
			d[i]=jia[j];
			j++;
		}
		
	}
}
