#include<cstdio>
#include<algorithm>
#define maxe 1000000
using namespace std;
int n,m,q,u,v,t,a[maxe];
double p;
int find_max(int len,int finder[]){
    int ans=-1,ji=-1;
    for (int q = 0; q < n; q++)
    {
        if(finder[q]>ji){
            ji=finder[q];
            ans=q;
        }
    }
    return ans;
}
void ususl_long(int longest,int len,int a[]){
    for (int i = 0; i < len-1; i++)
    {
        a[i]+=i!=longest?q:0;
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    p=double(u)/double(v);
    for (int miao = 1; miao <= m; miao++)
    {
        //printf("miao=%d==",miao);
        int longest=find_max(n,a);
        if(miao%t==0)printf("%d ",a[longest]);
        int lin=double(a[longest])*p*1.0;
        //printf("lin=%lf %lf=",p,lin);
        a[longest]-=lin;
        a[n++]=lin;
        ususl_long(longest,n,a);
        /*for (int i = 0; i < n; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");*/
    }
    printf("\n");
    sort(a,a+n,cmp);
    for (int i = 0; i < n; i++)
    {
        if((i+1)%t==0)printf("%d ",a[i]);
    }
    return 0;
}