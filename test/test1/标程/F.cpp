
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int maxn = 10;
int num[maxn];
int w[201000];
int dp[201000];
int main (){
    int t = 1;
    while (~scanf("%d%d%d%d%d%d",&num[0],&num[1],&num[2],&num[3],&num[4],&num[5])){
        int totl = 0;
        for (int i = 0; i<6 ;i++){
            totl += num[i] * (i+1);
        }
        if (totl == 0) break;
        if (totl % 2 == 1){
            printf("Collection #%d:\nCan't be divided.\n\n",t++);
            continue;
        }
        totl /= 2;
        //转为为01背包问题，有totlW个物品，每个物品仅仅可以取一次
        int totlW = 0;
        memset(w,0,sizeof w);
        for (int i = 0 ;i< 6; i ++){
            for(int j=1; j<=num[i]; j<<=1){
                w[totlW++]=j*(i+1);
                num[i]-=j;
            }
            if(num[i]>0)
                w[totlW++]=num[i]*(i+1);
        }
        memset(dp,0,sizeof dp);
        for (int i = 0 ;i< totlW ;i++)
            for (int j = totl ;j>=w[i] ;j--)
                dp[j]=max(dp[j],dp[j-w[i]]+w[i]);

        if(dp[totl]==totl)
            printf("Collection #%d:\nCan be divided.\n\n",t++);
        else
            printf("Collection #%d:\nCan't be divided.\n\n",t++);

    }
    return 0;
}
