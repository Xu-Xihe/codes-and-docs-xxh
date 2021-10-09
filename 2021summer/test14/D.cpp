#include <cstdio>
#include <cstring>
#include <vector>
#define ll unsigned long long
const int maxe = 1e5;
ll tree[maxe];
int m;
char tos[] = {')', '!', '@', '#', '$', '%', '^', '&', '*', '('};
inline void add(int x, ll val, int n)
{
    for (; x <= n; x += x & -x)
        tree[x] += val;
}
inline ll tog(int x)
{
    ll ans = 0;
    for (; x > 0; x -= x & -x)
        ans += tree[x];
    return ans;
}
char s[5000004];
std::vector<char> run;
std::vector<char> ins;
inline void get()
{
    ins.clear();
    char a = 0;
    while (a<48)
        a = getchar();
    while (a >=48)
    {
        ins.push_back(a);
        a = getchar();
    }
}
inline void fan(int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        if (run[i] >= 'a' && run[i] <= 'z')
        {
            run[i] -= 'a' - 'A';
            continue;
        }
        if (run[i] >= 'A' && run[i] <= 'Z')
        {
            run[i] += 'a' - 'A';
            continue;
        }
        if (run[i] >= '0' && run[i] <= '9')
        {
            run[i] = tos[run[i] - '0'];
            continue;
        }
        for (int i = 0; i < 10; i++)
            if (tos[i] == run[i])
            {
                run[i] = i + '0';
                break;
            }
    }
}
int main()
{
    scanf("%d", &m);
    int a, b, c;
    if (m > 20000)
    {
        scanf("%d%d%s", &a, &b, s);
        int len = strlen(s);
        for (int i = 0; i < len; i++)
            add(i + 1, s[i], len);
        m--;
        while (m--)
        {
            scanf("%d%d%d", &a, &b, &c);
            printf("%d\n", tog(c) - tog(b - 1));
        }
        return 0;
    }
    else
    {
        run.push_back(0);
        while (m--)
        {
            scanf("%d%d", &a, &b);
            if (a == 1)
            {
                get();
                std::vector<char>::iterator lin = run.begin() + b + 1;
                run.insert(lin, ins.begin(), ins.end());
                continue;
            }
            scanf("%d", &c);
            if (a == 2)
            {
                run.erase(run.begin() + b+1, run.begin() + c);
            }
            if (a == 3)
            {
                ll ans = 0;
                int len = run.size();
                for (int i = b; i <= c && i < len; i++)
                {
                    ans += run[i];
                    //printf("%d --> %d ", i, run[i]);
                }
                printf("%lld\n", ans);
            }
            if (a == 4)
            {
                fan(b + 1, c - 1);
            }
        }
    }
}