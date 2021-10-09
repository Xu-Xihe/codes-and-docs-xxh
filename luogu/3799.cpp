#include<cstdio>
const int maxe = 5e3+5;
const long long ans_mode=1e9+7;
long long wood[maxe],ans;
int len;
long long sum(long long in)
{
    return in*(in-1)/2;
}
int main()
{
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        int a;
        scanf("%d",&a);
        wood[a]++;
    }
    for (int i = 1; i < maxe; i++)
    {
        if(wood[i]>=2)
        {
            for (int j = 1; j <= i/2; j++)
            {
                if(j==i/2&&i%2==0)
                {
                    ans+=sum(wood[i])*sum(wood[j]);
                    ans%=ans_mode;
                    break;
                }
                ans+=sum(wood[i])*wood[j]*wood[i-j];
                ans%=ans_mode;
            }
        }
    }
    printf("%d\n",ans%ans_mode);
    return 0;
}