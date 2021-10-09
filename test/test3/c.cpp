#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct ll
{
    int sid,eid,ci;
    string a;
}ways[50];
bool in(ll ind[],int&len){
    ind[0].ci=0;
    char lin;
    int i=0;
    while (~scanf("%c",&lin))
    {
        if(lin=='\n'){
            ind[0].eid=i;
            return true;
        }
        if(lin=='['){
            ind[len].a+='*';
            int d;
            scanf("%d",&d);
            ind[len++].sid=i+1;
            ind[len].ci=d;
            char aa;
            scanf("%c",&aa);
        }
        if(lin==']'){
            ind[len].eid=i;
            len--;
        }
        else ind[len].a+=lin;
        i++;
    }
    ind[0].eid=i;
    return false;
}
bool cmp(ll a,ll b){
    return a.sid<b.sid;
}
void pr(ll in,int now){
    for (int i = 0; i < in.ci; i++)
    {
        for (int j = 0; ; j++)
        {
            if(in.a[j]=='*')pr(ways[now+1],now+1);
            else printf("%c",in.a[j]);
        }
    }
    return ;
}
int len;
int main(){
    while (in(ways,len))
    {
        sort(ways,ways+len,cmp);
        pr(ways[0],0);
    }
    return 0;
}