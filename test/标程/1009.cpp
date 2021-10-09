#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int ans[510];
int state[1010];
void getAns(int n){
    if (n==0) return ;
    getAns(n/2);
    for (int i=0; i<500; i++)
        for (int j = 0 ;j<500 ;j++)
            state[i+j] += ans[i]*ans[j];
    if (n%2)
        for (int i=0;i<1000;i++) state[i] *=2;
    for (int i= 0 ;i<500; i++){
        ans[i] = state[i]%10;
        state[i+1] += state[i]/10;
    }
    memset(state,0,sizeof state);
}
int main (){
    int n;scanf("%d",&n);
    printf("%d\n",int(log(2)/log(10)*n+1));
    memset(ans,0,sizeof ans);
    memset(state,0,sizeof state);
    ans[0]= 1;
    getAns(n);

    ans[0] --;
    int nowId = 0;
    while (ans[nowId]<0){
        ans[nowId] += 10;
        ans[nowId+1] --;
        nowId ++;
    }

    int cnt = 0;
    for (int i=499 ;i>=0 ;i--){
        cnt ++;
        printf("%d",ans[i]);
        if (cnt==50){
            printf("\n");
            cnt = 0;
        }
    }
    return 0;
}
