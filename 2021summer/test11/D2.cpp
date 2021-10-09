#include <set>
#include <cstdio>
#include <vector>
using std::multiset;
multiset<int, std::greater<int>> run[2];
struct dd
{
    int a, b;
};
std::vector<dd> lin;
int n, now, ins;
char in[10];
inline int fan(int put)
{
    int ans = 0;
    while (put)
    {
        ans *= 10;
        ans += put % 10;
        put /= 10;
    }
    return ans;
}
#define back ((now + 1) % 2)
int main()
{
    freopen("score.in", "r", stdin);
    freopen("score.out", "w", stdout);
    scanf("%d%s", &n, in);
    while (n--)
    {
        scanf("%s%d", in, &ins);
        if (in[0] == 'I')
        {
            run[now].insert(ins);
            run[back].insert(fan(ins));
            int aa = fan(fan(ins));
            if (aa != ins)
                lin.push_back(dd{ins, aa});
        }
        if (in[0] == 'D')
        {
            run[now].erase(ins);
            run[back].erase(fan(ins));
        }
        if (in[0] == 'R')
        {
            int ans = 1;
            multiset<int>::iterator end = run[now].lower_bound(ins);
            multiset<int>::iterator sta = run[now].begin();
            while (sta != end)
            {
                ans++;
                sta++;
            }
            printf("%d\n", ans);
        }
        if (in[0] == 'K')
        {
            for (auto i : run[now])
            {
                ins--;
                if (!ins)
                {
                    printf("%d\n", i);
                    break;
                }
            }
        }
        if (in[0] == 'E')
        {
            for (auto i : lin)
            {
                run[now].erase(i.a);
                run[now].insert(i.b);
            }
            lin.clear();
            now += 1;
            now %= 2;
        }
    }
    return 0;
}