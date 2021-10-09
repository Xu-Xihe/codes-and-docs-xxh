#include<bits/stdc++.h>
using namespace std;
int len,a[25],lin[25];
void eeee(int in){
    if (in==len+1){
        for(int i=1;i<=len;i++)
            printf("%d ",a[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=len;i++)
        if(lin[i]==0){
            lin[i]=1;
            a[in]=i;
            eeee(in+1);
    	    lin[i]=0;
        }
}
int main(){
    scanf("%d",&len);
    eeee(1);
    return 0;
}
