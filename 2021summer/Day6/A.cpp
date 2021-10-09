#include<cstdio>
#include<stack>
int len,h,ans;
struct one
{
    int a,wei;
};
std::stack<one>running;
int main()
{
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&h);
        while(!running.empty()&&running.top().a<h)running.pop();
        ans+=running.empty()?i:i-running.top().wei-1;
        running.push(one{h,i});
    }
    printf("%d",ans);
    return 0;
}