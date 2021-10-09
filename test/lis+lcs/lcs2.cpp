#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxe 2000
using namespace std;
char a[maxe],b[maxe];
int lena,lenb;
int dp[maxe][maxe];
int main(){
    while (~scanf("%s%s",a,b))
    {
        memset(dp,0,sizeof(dp));
        lena=strlen(a);
        lenb=strlen(b);
        for (int i = 1; i <= lena; i++)
        {
            for (int j = 1; j <= lenb; j++)
            {
                if (a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[lena][lenb]);
    }
    return 0;
}
