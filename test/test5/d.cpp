#include<cstdio>
#define maxe 100055
using namespace std;
int len,hi[maxe];
int ansd(int len,int h[]){
    int ans=0;
    for(int i=0; i<len;i++){
        if(h[i]==0)continue;
        for(int j=i;j<len;j++){
            if(h[j]!=0)h[j]--;
            else break;
        }
        /*for(int j=0 ;j<len;j++)
            printf("%d ",h[j]);
        printf("\nans = %d\n\n",ans);*/
        ans++;
        if(h[i]>0)i--;
    }
    return ans;
}
int main(){
    scanf("%d",&len);
    for(int i=0;i<len;i++)
        scanf("%d",&hi[i]);
    printf("%d",ansd(len,hi));
    return 0;
}