#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int len,ji[]={1,5,10,25},in[4];
int dp[5][10005];
int main(){
    while(1){
        scanf("%d",&len);
        int a=0;
        for(int i = 0; i < 4; i++)
        {
            scanf("%d",&in[i]);
            if (in[i]==0)
            {
                a++;
            }
        }
        if (len==0&&a==4) {
            return 0;
        }
        bool right=false;
        memset(dp,0,sizeof(dp));
        for(int zl = 1; zl <= 4; zl++)
        {
            for(int i = 1; i <= len; i++)
            {
                if(i>=ji[zl-1]&&i/ji[zl-1]<=in[zl-1]){
                    int maxe=dp[zl-1][i];
                    for(int z=0;z<i/ji[zl-1];z++){
                        if(dp[zl-1][i-(z+1)*ji[zl-1]]>0||i-(z+1)*ji[zl-1]==0)
                            maxe=max(maxe,dp[zl-1][i-(z+1)*ji[zl-1]]+z+1);
                    }
                    dp[zl][i]=maxe;
                }
                else dp[zl][i]=dp[zl-1][i];
            }
            /*for(int zz = 0; zz < 5; zz++)
            {
                for(int j = 0; j <= len; j++)
                {
                    printf("%d ",dp[zz][j]);
                }
                printf("\n");
            }
            printf("\n");*/
            if(dp[zl][len]>0){
                int a[5];
                memset(a,0,sizeof(a));
                int lin=len;
                for(int aa = zl; aa >0; aa--)
                {
                    if(dp[aa][lin]==dp[aa-1][lin])continue;
                    for(int i = 0; i < lin/ji[aa-1]; i++)
                    {
                        if(dp[aa][lin]-i-1==dp[aa-1][lin-(i+1)*ji[aa-1]]||lin-(i+1)*ji[aa-1]==0){
                            a[aa]=i+1;
                            lin-=(i+1)*ji[aa-1];
                        }
                    }
                }
                printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",a[1],a[2],a[3],a[4]);
                right=true;
                break;
            }
        }
        if(!right)printf("Charlie cannot buy coffee.\n");
    }
}