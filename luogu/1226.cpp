#include <cstdio>
int a, b, p;
inline int mi(int n, int m, int mod, long long sum = 1, long long ans = 1) //n表示底数,m表示指数,mod为模数,sum为累加器,ans为结果
{
    sum = n;  //初始化累加器至n^1
    while (m) //保证指数不为0
    {
        if (m & 1) //如果最后一位是1,则应该乘上
        {
            ans *= sum;
            ans %= mod;
        }
        sum *= sum; //累加器自乘
        sum %= mod;
        m >>= 1; //这一位已经处理完毕,开始处理下一位
    }
    return ans % mod;
}
int main()
{
    scanf("%d%d%d", &a, &b, &p);
    printf("%d^%d mod %d=%d\n", a, b, p, mi(a, b, p)); //奇奇怪怪的输出方式
}