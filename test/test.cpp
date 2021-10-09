#include<cstdio>
#include<math.h>
using namespace std;
double hailun(int a,int b,int c)
{
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int len,in[45],sum,out;
int dp[2000][2000];
int main()
{
    scanf("%d",&len);
    for(int i = 0; i < len; i++)
    {
        scanf("%d",&in[i]);
        sum+=in[i];
    }
    dp[0][0]=1;
    for(int i = 0; i < len; i++)
    {
        for(int j = sum; j >= 0; j--)
        {
            for(int z = sum; z >= j; z--)
            {
                if(dp[j][z]==1)
                {
                    dp[j+in[i]][z]=1;
                    dp[j][z+in[i]]=1;
                }
            }
            
        }
        
    }
    for(int i = 0; i < sum+1; i++)
    {
        for(int j = 0; j < sum+1; j++)
        {
            //printf("%d ",dp[i][j]);
            if(dp[i][j]==1)
            {
                double lin=hailun(i,j,sum-i-j)*100;
                int hehe=lin;
                if(hehe>out)out=hehe;
            }
        }
        //printf("\n");
    }
    if(out==0)printf("-1");
    else printf("%d",out);
    return 0;
}