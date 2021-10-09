#include <cstdio>
#include <queue>
const unsigned int maxe = 3e5 + 9;
unsigned int n, num[maxe], ji[maxe], tot;
//long long tree[maxe];
/*inline void add(unsigned int x, unsigned int val)
{
    for (; x <= n; x += x & -x)
        tree[x] ^= val;
}
inline unsigned int find(unsigned int x)
{
    long long ans = 0;
    for (; x > 0; x -= x & -x)
        ans ^= tree[x];
    return ans;
}*/
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int a, b, c;
        scanf("%d%d", &a, &b);
        if (a == 1)
        {
            num[++tot] = b;
            //add(tot, b ^ num[tot - 1]);
        }
        if (a == 2)
        {
            for (unsigned int i = 1; i <= tot; i++)
            {
                if (num[i] == b)
                {
                    ji[i] = 1;
                    break;
                }
            }
        }
        if (a == 3)
        {
            scanf("%d", &c);
            if (c == 1)
            {
                unsigned int ans = 0;
                for (unsigned int i = 1; i <= tot; i++)
                {
                    if (!ji[i])
                    {
                        unsigned int lin = num[i]^b;
                        if (ans < lin)
                            ans = lin;
                    }
                    //printf("ceshi  %d :  %d   %d   %d  %d\n", i, ji[i],num[i], num[i]^b, ans);
                }
                printf("%d\n", ans);
            }
            else
            {
                std::priority_queue<unsigned int> run;
                while (!run.empty())
                    run.pop();
                for (unsigned int i = 1; i <= tot; i++)
                {
                    if (!ji[i])
                        run.push(num[i]^b);
                }
                for (int i = 1; i < c; i++)
                    run.pop();
                printf("%d\n", run.top());
            }
        }
    }
    return 0;
}