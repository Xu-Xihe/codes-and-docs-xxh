#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct xxh
{
    int num;
    int ans;
};
queue<xxh>runing;
int start,end_xxh;
bool ji[200000];
void pushed(xxh in){
    if (!ji[in.num])
    {
        ji[in.num]=true;
        runing.push(in);
    }
    return ;
}
int main(){
    while(~scanf("%d%d",&start,&end_xxh)){
        while(!runing.empty())runing.pop();
        memset(ji,0,sizeof(ji));
        if (end_xxh<=start)
        {
            printf("%d\n",start-end_xxh);
            continue;
        }
        xxh a;
        a.num=start;
        a.ans=0;
        runing.push(a);
        ji[a.num]=1;
        while (1)
        {
            if (runing.front().num==end_xxh)
            {
                printf("%d\n",runing.front().ans);
                break;
            }
            xxh a,b;
            a.ans=runing.front().ans+1;
            b.ans=runing.front().ans+1;
            a.num=runing.front().num+1;
            b.num=runing.front().num-1;
            if(a.num>0&&a.num<100001)pushed(a);
            if(b.num>0)pushed(b);
            if(runing.front().num<end_xxh){
                xxh c;
                c.num=runing.front().num*2;
                c.ans=runing.front().ans+1;
                pushed(c);
            }
            runing.pop();
        }
    }
    return 0;
}