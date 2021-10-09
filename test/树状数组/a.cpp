#include<cstdio>
#define maxe 50005
using namespace std;
int ci,len,in[maxe],tree[maxe];
void add(int d,int z){
    for (; d <=len ; d+=d&(-d))
    {
        tree[d]+=z;
    }
}
int part(int end){
    int ans=0;
    for (; end >0 ; end-=end&(-end))
    {
        ans+=tree[end];
    }
    return ans;
}
int main(){
    scanf("%d",&ci);
    for(int i=1;i<=ci;i++)
    {
        scanf("%d",&len);
        for (int j = 0; j < len; j++)
        {
            scanf("%d",&in[j+1]);
        }
        for (int j = 1; j <= len; j++)
        {
            tree[j]=part(j-1)-part(j-(j&(-j)))+in[j];
        }
        printf("Case %d:\n",i);
        while (1)
        {
            char c[10];
            int a,b;
            scanf("%s",c);
            if (c[0]=='E')break;
            scanf("%d%d",&a,&b);
            if(c[0]=='Q'){
                int ans=part(b);
                if (a==1){
                    printf("%d\n",ans);
                }
                else{
                    printf("%d\n",ans-part(a-1));
                }
            }
            else if(c[0]=='A'){
                add(a,b);
            }
            else if(c[0]=='S'){
                add(a,b*(-1));
            }
        }
    }
    return 0;
}