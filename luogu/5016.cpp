#include<stdio.h>
using namespace std;
long long by,sb[100005],m,ms,p1,s1,s2,jia,yi,xiao=1e11,nows;
int ch;//by=bingying,sb=shibing
int main(){
	//freopen("in.txt","r",stdin);
    scanf("%lld",&by);
    for(int i=0;i<by;i++)
        scanf("%lld",&sb[i]);
    scanf("%lld%lld%lld%lld",&m,&p1,&s1,&s2);
    sb[p1-1]+=s1;
    for(int i=0;i<(m-1);i++)
        jia+=sb[i]*(m-i-1);
    for(int i=m;i<by;i++)
        yi+=sb[i]*(i-m+1);
    if(jia==yi){
    	printf("%lld",m);
    	return 0;
    }
    if(jia>yi){
        ms=jia-yi;
        for(int i=m;i<by;i++){
            nows=ms-s2*(i-m+1);
            if(nows<0)nows*=-1;
            if(nows<xiao){
                xiao=nows;
                ch=i+1;
            }
        }
    }
    if(jia<yi){
        ms=yi-jia;
        for(int i=m-2;i>=0;i--){
            nows=ms-s2*(m-i-1);
            if(nows<0)nows*=-1;
            if(nows<xiao){
                xiao=nows;
                ch=i+1;
            }
        }
    }
    if(ms<xiao)ch=m;
    printf("%d",ch);
    return 0;
}
