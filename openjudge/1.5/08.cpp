#include<cstdio>
using namespace std;
int len,ans;
int main(){
    scanf("%d",&len);
    ans=(len-2)*180;
    for(int i = 1; i < len; i++)
    {
        int a;
        scanf("%d",&a);
        ans-=a;
    }
    printf("%d",ans);
    return 0;
}