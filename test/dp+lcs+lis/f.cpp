#include<cstdio>
#include<cstring>
using namespace std;
int ji[1000000];
int ans,len;
int main(){
    while (~scanf("%d",&len))
    {
        memset(ji,0,sizeof(ji));
        for (int i = 0; i < len; i++)
        {
            int in;
            scanf("%d",&in);
            ji[in]++;
            if(ji[in]==(len+1)/2)ans=in;
        }
        printf("%d\n",ans);
    }
    return 0;
}