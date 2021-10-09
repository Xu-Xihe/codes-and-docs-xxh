#include <cstdio>
const int maxe = 2e5 + 5;
const unsigned long long mode = 998244353;
int len, wood[maxe];
unsigned long long ans, edge[maxe];
long long sum(int a)
{
    return (a * (a - 1) / 2 )% mode;
}
int most(int yao)
{
    yao*=2;
    yao--;
    return yao<maxe-3?yao:maxe-3;
}
long long same(int a)
{
    long long back=0;
    for (int i = 1; i <= a-2; i++)
    {
        long int b=i*(a-1-i);
        if(i>28000)printf("%lld-->",b);
        b%=998244353;
        back+=b;
        back%=mode;
        if(i>28000)printf("%9d-->%9lld-->%lld-->%lld\n",i,back,i*(a-1-i),b);
        if(back<0){printf("fkjaldfjlajdfl");return 0;}
        if (b<0)
        {
            printf("errwerwer");
            return 0;
        }
        
    }
    return back;
}
int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        int a;
        scanf("%d", &a);
        wood[a]++;
    }
    for (int i = 1; i < maxe-2; i++)
    {
        edge[i] = wood[i] + edge[i-1];
    }
    for (int i = 1; i < maxe-2; i++)
    {
        if(wood[i]<2)continue;
        ans+=(edge[most(i)]-wood[i])*sum(wood[i])+same(wood[i]);
        ans%=mode;
        printf("shu: edge-->%d sum-->%d add-->%d ans-->%d\n\n",edge[most(i)]-wood[i],sum(wood[i]),(edge[most(i)]-wood[i])*sum(wood[i]),ans);
    }
    printf("%lld",ans);
    return 0;
}