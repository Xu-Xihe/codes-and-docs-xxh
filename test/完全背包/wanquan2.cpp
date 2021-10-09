#include<cstdio>
#include<cstring>
using namespace std;
int ji[]={5,10,20,50,100,200,500,1000,2000,5000,10000},len;
long long dp[30050];
int main()
{
    while(1)
    {
        float a;
        scanf("%f",&a);
        len=int(a*100+0.5);
        //printf("%d ",len);
        if(len==0)return 0;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int zl = 0; zl < 11; zl++)
        {
            for(int i = 0; i <= len; i++)
            {
                if(i>=ji[zl])dp[i]+=dp[i-ji[zl]];
            }
        }
        printf("%6.2f%17lld\n",a,dp[len]);
    }
}