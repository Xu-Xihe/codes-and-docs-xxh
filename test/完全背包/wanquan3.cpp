#include<cstdio>
#define maxe 1050
using namespace std;
int n,k;
long long first[maxe],second[maxe];
const long long big=1e18;
int main()
{
    scanf("%d%d",&n,&k);
    first[0]=1;
    for(int zl=1;zl<=k;zl++)
    {
        for(int i = 0; i <= n; i++)
        {
            if (i>=zl) {
                first[i]+=first[i-zl];
                second[i]+=second[i-zl]+first[i]/big;
                first[i]%=big;
            }
        }
    }
    if(second[n]==0)printf("%lld",first[n]);
    else printf("%lld%18lld",second[n],first[n]);
    return 0;
}