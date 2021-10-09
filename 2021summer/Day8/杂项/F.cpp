#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
using std::abs;
using std::set;
const int mod = 1e6;
int len, dd;
bool aa;
long long ans;
set<long long> dog;
set<long long> pel;
void del(set<long long> &chang, set<long long>::iterator a, long long val)
{
    ans += val;
    ans %= mod;
    chang.erase(a);
}
void choose(set<long long> &my, set<long long> &opt, long long b)
{
    set<long long>::iterator nbt;
    set<long long>::iterator lbt;
    if (opt.empty())
    {
        my.insert(b);
        return;
    }
    nbt = opt.lower_bound(b);
    long long aa = 2e9, bb = 2e9;
    if (nbt != opt.end())
        aa = abs(*nbt - b);
    lbt = nbt;
    --lbt;
    if (nbt != opt.begin())
        bb = abs(*lbt - b);
    if (aa > bb||(aa == bb && *lbt < b))
        del(opt, lbt, bb);
    else
        del(opt, nbt, aa);
}
int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d%d", &aa, &dd);
        if (aa)
            choose(pel, dog, dd);
        else
            choose(dog, pel, dd);
    }
    printf("%d", ans);
    return 0;
}