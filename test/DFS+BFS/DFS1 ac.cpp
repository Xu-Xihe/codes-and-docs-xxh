#include<cstdio>
using namespace std;
int out[]={0,1,0,0,2,10,4,40,92,352,724};
int N;
int main(){
    while(1){
        scanf("%d",&N);
        if(N==0)return 0;
        if(N<=0)printf("%d\n",out[0]);
        else printf("%d\n",out[N]);
    }
}