#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int longest=2e6+5;
int len;
long long ans;
int all[longest];//整体储存
int small[longest];
struct intype
{
    int longs,kind,same;
};
queue<intype>running;
int main()
{
   freopen("stdout.out","r",stdin);
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        int lin;
        scanf("%d",&lin);
        all[lin]++;
    }
    for (int i = 1; i < longest; i++)
    {
       small[i]=small[i-1]+all[i-1];
        if(all[i]>=2)
        { 
            intype lin;
            lin.longs=i;
            long long asd=all[i]*(all[i]-1);
            asd%=998244353;
            lin.kind=asd/2;
            lin.same=0;
            for (int j = 1; j <= all[i]-2; j++)
            {
                long long a=j;
                a*=a;
                if(j%100==0||j>all[i]-10)printf("\n%lld",a);
                a%=998244353;
                lin.same+=(a+j)/2%998244353;
                lin.same%=998244353;
               if(j%100==0||j>all[i]-10)printf("che:%d %d %d\n\n",j,lin.same,a);
            }
            running.push(lin);
        }
    }
    int size=running.size();
    for (int i = 0; i < size; i++)
    {
        intype front=running.front();
        running.pop();
        long long lin=front.kind*abs(small[front.longs*2]-all[front.longs]);
        ans+=lin%998244353;
        ans+=front.same;
        ans%=998244353;
        printf("\ncheshi:%d %d %d %d %d\n\n",front.longs,front.kind,small[front.longs*2]-all[front.longs],front.same,ans);
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}