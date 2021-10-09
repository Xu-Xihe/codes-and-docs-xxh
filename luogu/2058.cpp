#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
int ans;
const int maxe = 1e5+10;
unsigned int check[maxe];
struct intype
{
    int time,len;
    vector<int>nation;
};
queue<intype>running;
intype inside()
{
    intype a;
    a.nation.clear();
    scanf("%d%d",&a.time,&a.len);
    for (int i = 0; i < a.len; i++)
    {
        int d;
        scanf("%d",&d);
        a.nation.push_back(d);
    }
    return a;
}
void chu(intype in)
{
    for (int i = 0; i < in.len; i++)
    {
        if(check[in.nation[i]]==0)ans++;
        check[in.nation[i]]++;
    }
    while(1)
    {
        if((in.time-86400)>=running.front().time)
        {
            for (int i = 0; i < running.front().len; i++)
            {
                check[running.front().nation[i]]--;
                if(check[running.front().nation[i]]==0)ans--;
            }
            running.pop();
        }
        else break;
    }
   return;
}
int main()
{
    int clang;
    scanf("%d",&clang);
    for (int i = 0; i < clang; i++)
    {
        intype puin=inside();
        running.push(puin);
        chu(puin);
        printf("%d\n",ans);
    }
    return 0;
}