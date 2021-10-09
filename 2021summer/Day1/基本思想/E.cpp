#include <cstdio>
#include <queue>
#include <vector>
int len,max,min;
bool cmp_min(int a, int b)
{
    return a < b;
}
std::priority_queue<int, std::vector<int>, std::greater<int> >maxe;
std::priority_queue<int, std::vector<int>, std::less<int> >mine;
int main()
{
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        int a;
        scanf("%d",&a);
        maxe.push(a);
        mine.push(a);
    }
    scanf("%d",&len);
    while (maxe.size()>1)
    {
        int a=maxe.top();
        maxe.pop();
        int b=maxe.top();
        maxe.pop();
        maxe.push(a*b+1);
    }
    max=maxe.top();
    while (mine.size()>1)
    {
        int a=mine.top();
        mine.pop();
        int b=mine.top();
        mine.pop();
        //printf("a-->%d b-->%d maxe-->%d\n",a,b,a*b+1);
        mine.push(a*b+1);
    }
    min=mine.top();
    printf("%d",max-min);
    return 0;
}