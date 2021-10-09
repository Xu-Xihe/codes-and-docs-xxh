#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxe 10000
using namespace std;
char a[maxe],b[maxe];
int lena,lenb;
int dp[maxe][maxe];
int ji[maxe][maxe][2];
int main(){
    while (~scanf("%s%s",a,b))
    {
        lena=strlen(a);
        lenb=strlen(b);
        for (int i = 1; i <= lena; i++)
        {
            for (int j = 1,lin=0; j <= lenb; j++)
            {
                if (a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    ji[i][j][1]=ji[i-1][j-1][1];
                    ji[i][j][2]=ji[i-1][j-1][2];
                }
                else{
                    if (dp[i-1][j]>dp[i][j-1]) {
                        dp[i][j]=dp[i-1][j];
                        if (a[i-2]==b[j-1]) {
                            ji[i][j][1]=i-1;
                            ji[i][j][2]=j;
                        }
                        else{
                            ji[i][j][1]=ji[i-1][j][1];
                            ji[i][j][2]=ji[i-1][j][2];
                        }
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-1];
                        if (a[i-1]==b[j-2]) {
                            ji[i][j][1]=i;
                            ji[i][j][2]=j-1;
                        }
                        else{
                            ji[i][j][1]=ji[i][j-1][1];
                            ji[i][j][2]=ji[i][j-1][2];
                        }
                    }
                }
            }
        }
        for (int i = 0; i < lena; i++)
        {
            for (int j = 0; j < lenb; j++)
            {
                printf("%d ",dp[i+1][j+1]);
            }
            printf("\n");
        }
        for (int i = 0; i < lena; i++)
        {
            for (int j = 0; j < lenb; j++)
            {
                printf("%d-%d ",ji[i+1][j+1][1],ji[i+1][j+1][2]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}