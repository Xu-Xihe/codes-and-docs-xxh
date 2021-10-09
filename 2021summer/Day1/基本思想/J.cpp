#include<cstdio>
#include<algorithm>
int m,n;
struct play
{
    int date,out;
}plays[1000];
bool taken[1000];
bool cmp(play a,play b)
{
    return a.out>b.out;
}
bool finish(int end)
{
    for (int i = end; i > 0; i--)
    {
        if(!taken[i])
        {
            taken[i]=true;
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d%d",&m,&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&plays[i].date);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&plays[i].out);
    }
    std::sort(plays,plays+n,cmp);
    for (int i = 0; i < n; i++)
    {
        if(finish(plays[i].date))continue;
        m-=plays[i].out;
    }
    printf("%d",m);
    return 0;
}