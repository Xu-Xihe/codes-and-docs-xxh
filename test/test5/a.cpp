#include<cstdio>
#define maxe 1000005
using namespace std;
int n,m,k,x;
int h[maxe];
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&x);
    long long ans;
    h[0]=x;
    for(ans=1;;ans++) {
        x+=m;
        if(x>=n) x-=n;
        h[ans]=x;
        if(x==h[0]) break;
    }
    int len1=k/10,len2=k%10;
    int q=1;
    for(int j=1;j<=len1;j++) q=q*10000000000%ans;
    for(int j=1;j<=len2;j++) q=q*10%ans;
    printf("%d",h[q]);
    return 0;
}