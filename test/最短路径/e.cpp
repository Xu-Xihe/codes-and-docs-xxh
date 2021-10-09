#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define maxe 200
using namespace std;
int ld, len,what,how;
double dp[maxe][maxe],yong[maxe][maxe];
int main(){
    while (~scanf("%d%d%d%d",len,ld,how,what))
    {
        for(int i=0;i<=len;i++)
            for (int j = 0; j <=len; j++)
                dp[i][j]=1;    
        for (int i = 0; i < ld; i++)
        {
            int a,b;
            double c ,d,e,f;
            scanf("%d%d%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
            dp[a][b]=c;
            yong[a][b]=d;
            dp[b][a]=e;
            yong[a][b]=f;
        }
        
    }
    return 0;
}