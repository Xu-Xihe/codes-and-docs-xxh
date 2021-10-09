#include<cstdio>
#include<algorithm>
int len,now=-1e9,ans;
struct active
{
    int start,end;
}activities[2000];
bool cmp(active a,active b)
{
    return a.end<b.end;
}
int main()
{
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d%d",&activities[i].start,&activities[i].end);
    }
    std::sort(activities,activities+len,cmp);
    for (int i = 0; i < len; i++)
    {
        if(activities[i].start<now)continue;
        ans++;
        now=activities[i].end;
    }
    printf("%d",ans);
    return 0;
}