#include<cstdio>
#include<algorithm>
#define maxe 45
using namespace std;
int len,card,g[400],cc[5];
int dp[maxe][maxe][maxe][maxe];
int main(){
    scanf("%d%d",&len,&card);
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&g[i]);
    }
    for (int i = 0; i < card; i++)
    {
        int a;
        scanf("%d",&a);
        cc[a]++;
    }
    for (int a = 1; a <= cc[1]+1; a++)
    {
        for (int b = 1; b <= cc[2]+1; b++)
        {
            for (int c = 1; c <= cc[3]+1; c++)
            {
                for (int d = 1; d <= cc[4]+1; d++)
                {
                    dp[a][b][c][d]=max(max(dp[a-1][b][c][d],dp[a][b-1][c][d]),max(dp[a][b][c-1][d],dp[a][b][c][d-1]))+g[a+2*b+3*c+4*d-10];
                }
            }
        }
    }
    printf("%d",dp[cc[1]+1][cc[2]+1][cc[3]+1][cc[4]+1]);
    return 0;
}