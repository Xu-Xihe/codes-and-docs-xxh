#include<cstdio>
long long fi,se,end,len,cha;
int main(){
    scanf("%lld%lld%lld",&fi,&se,&len);
    cha=se-fi;
    end=cha*(len-1)+fi;
    //printf("%d-%d\n",cha,end);
    printf("%lld\n",((fi+end)*len)/2);
    return 0;
}