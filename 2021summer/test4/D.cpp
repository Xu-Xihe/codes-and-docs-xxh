#include <cstdio>
#include <algorithm>
const int maxe = 3009;
const long long mod = 998244353;
int sta, bei, ci, T, xi[maxe];
unsigned int out[maxe];
/*inline void mode(long long& a)
{
    long long yi = a / mod;
    a -= yi * mod;
}*/
inline unsigned int fast(unsigned int n,int k)
{
    long long ans = 1;
    //printf("mi : %d  %d  ", n, k);
    while(k)
    {
        if(k&1)
        {
            ans *= n;
            ans %= mod;
        }
        n *= n;
        n %= mod;
        k >>= 1;
    }
    //printf("  %d \n", ans);
    return ans;
}
inline unsigned int add(unsigned int n)
{
    long long ans = 0;
    for (int i = 0; i <= ci; i++)
    {
        ans += xi[i] * fast(n, i);
        ans %= mod;
        //printf("add %d  %d  %d\n", n, i, ans);
    }
    return ans;
}
struct node
{
    unsigned int val;
    int tag;
} ask[maxe];
inline bool cmp(node a, node b)
{
    return a.val < b.val;
}
int main()
{
    scanf("%lld%d%d", &out[0], &bei, &ci);
    for (int i = 0; i <= ci; i++)
    {
        scanf("%d", &xi[i]);
    }
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
    {
        scanf("%lld", &ask[i].val);
        ask[i].tag = i;
    }
    std::sort(ask, ask + T,cmp);
    for (int i = 1; i <= T; i++)
    {
        out[ask[i].tag] = out[ask[i - 1].tag];
        for (int j = ask[i-1].val+1; j <= ask[i].val; j++)
        {
            //printf("ce1  %d  ", out[ask[i].tag]);
            out[ask[i].tag] *= bei;
            //printf("ce2  %d  ", out[ask[i].tag]);
            out[ask[i].tag] %= mod;
            out[ask[i].tag] += add(j);
            //printf("ce3  %d \n", out[ask[i].tag]);
        }
    }
    for (int i = 1; i <= T; i++)
    {
        printf("%lld\n", out[i]);
    }
    return 0;
}