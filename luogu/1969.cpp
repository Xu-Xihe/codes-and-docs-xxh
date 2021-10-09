#include<stdio.h>
using namespace std;
int len,gao[100005],ans;
int main(){
    scanf("%d",&len);
    for(int i=0;i<len;i++){
        scanf("%d",&gao[i]);
    } 
    ans+=gao[0];
    for(int i = 1; i < len; i++)
    {
        if (gao[i]>gao[i-1]) {
            ans+=gao[i]-gao[i-1];
        }
    }
    printf("%d",ans);
    return 0;
}