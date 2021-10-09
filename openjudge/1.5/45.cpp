#include<cstdio>
using namespace std;
int day,ans;
int main(){
    scanf("%d",&day);
    for (int sum = 1,ji=1,a=0; sum <= day; a++)
    {
        if (a==ji)
        {
            ji++;
            a=0;
        }
        ans+=ji;
        sum++;
        //printf("%d %d %d %d \n",sum,a,ji,ans);
    }
    printf("%d",ans);
    return 0;
}