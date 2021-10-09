#include<stdio.h>
#include<stack>
std::stack<int>running;
int n,w,ans;
int main()
{
    scanf("%d%d",&n,&w);
    int x,y;
    running.push(0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&x,&y);
        while(1)
        {
            if(running.empty()||running.top()<=y)break;
            ans++;
            running.pop();
            //printf("out:-->%d  %d \n",running.size(),ans);
        }
        if(running.empty()||y>running.top())running.push(y);
        //printf("pushin:-->%d  %d \n",y,running.size());
    }
    printf("%d",ans+running.size()-1);
    return 0;
}