#include<cstdio>
using namespace std;
int len,ans[3];
int main(){
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ans[0]+=a;
        ans[1]+=b;
        ans[2]+=c;
    }
    printf("%d %d %d %d",ans[0],ans[1],ans[2],ans[0]+ans[2]+ans[1]);
    return 0;
}