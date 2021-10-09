#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int a,b,k,n,
long long dp[1005][1005];
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	dp[0][0]=1;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=m;j++)
        {
            if (i==0 && j==0) continue;
    		dp[i][j]=0;
        	if (i>0)dp[i][j]=(dp[i][j]+dp[i-1][j]*a)%10007;
            if (j>0){
                dp[i][j]=(dp[i][j]+dp[i][j-1]*b)%10007;
            }
		}
 	printf("%lld\n",dp[n][m]);
    return 0;
}