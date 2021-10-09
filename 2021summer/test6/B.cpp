#include <cstdio>
#include <set>
const int maxe = 1e5;
int n, in[maxe], k;
std::multiset<double> ans;
int main()
{
    freopen("ave.in", "r", stdin);
    freopen("ave.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        double now = 0, lin;
        for (int j = 1; j <= i; j++)
        {
            now += in[j];
        }
        lin = now / i;
        if (ans.size() < k || ans.upper_bound(lin) != ans.end())
            ans.insert(lin);
        for (int j = 2; j <= n - i + 1; j++)
        {
            now -= in[j - 1];
            now += in[j + i - 1];
            lin = now / i;
            if (ans.size() < k || ans.upper_bound(lin) != ans.end())
                ans.insert(lin);
        }
        /*printf("\nnow :  %d\n", i);
        for (auto a : ans)
        {
            printf("ceshi  %lf\n", a);
        }*/
    }

    for (double i : ans)
    {
        k--;
        if (!k)
        {
            printf("%.4f\n", i);
            return 0;
        }
    }
}