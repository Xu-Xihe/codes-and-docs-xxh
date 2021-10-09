#include <algorithm>
#include <vector>
#include <cstdio>
#include <unordered_map>
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
const int maxe = 1e6 + 9;
int n, m, k, in[maxe], num[maxe],tot, nu[maxe];
void show(char *p,int *put)
{
    printf("\n%s:\n", p);
    for (int i = 0; i < tot; i++)
    {
        printf("%d ", put[i + 1]);
    }
    printf("\n");
}
//std::unordered_map<int, int> tonum;
std::unordered_map<int, int> tosi;
inline int find(int l, int r)
{
    int ans = 0;
    for (int i = 0; i <= n; i++)
        nu[i] = 0;
    for (int i = l; i <= r; i++)
    {
        nu[tosi[in[i]]]++;
    }
    for (int i = 1; i <= tot; i++)
    {
        //printf("ceshi  %d:  %d   %d  %d  %d \n", i, nu[i], num[i],num[i] - nu[i] * 2,abs(num[i] - nu[i] * 2));
        if (nu[i]>0 && abs(num[i] - nu[i] * 2) <= k)
            ans++;
    }
    //show("nu", nu);
    return ans;
}
int main()
{
    IO("magic");
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in[i]);
        if (tosi[in[i]] == 0)
        {
            tosi[in[i]] = ++tot;
            //printf("%d  -->  %d\n", in[i], tot);
            //tonum[tot] = in[i];
        }
        num[tosi[in[i]]]++;
    }
    //show("num", num);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", find(a, b));
    }
    return 0;
}