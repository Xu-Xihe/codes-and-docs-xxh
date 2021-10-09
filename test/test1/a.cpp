#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct way{
    int sid,eid,valu;
}ways[8000000];
int len,lway,fa[40000],ans;
char in[40000][100];
bool cmp(way a,way b){
    return a.valu<b.valu;
}
int diff(char a[],char b[]){
    int ans=0;
    for (int i = 0; i < strlen(a); i++)
    {
        if(a[i]!=b[i])ans++;
    }
    return ans;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void together(int a,int b){
    if (find(a)!=find(b))
    {
        fa[find(a)]=fa[find(b)];
    }
    return ;
}
int main(){
    while (~scanf("%d",&len))
    {
        if(len==0)return 0;
        for(int i=0;i<=len;i++)fa[i]=i;
        ans=0;
        lway=0;
        for (int i = 0; i < len; i++)
        {
            scanf("%s",in[i]);
        }
        for (int i = 0; i < len; i++)
        {
            for (int j = i+1; j < len; j++)
            {
                ways[lway].valu=diff(in[i],in[j]);
                ways[lway].sid=i;
                ways[lway++].eid=j;
            }
        }
        sort(ways,ways+lway,cmp);
        for (int i = 0; i < lway; i++)
        {
            if(find(ways[i].sid)!=find(ways[i].eid)){
                ans+=ways[i].valu;
                together(ways[i].eid,ways[i].sid);
            }
        }
        printf("The highest possible quality is 1/%d.\n",ans);
    }
    return 0;
}
