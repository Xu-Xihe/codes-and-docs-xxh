#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
const int maxe = 1e5 + 9, mbk = 500;
int n, m, q, len, num, last, ans, in[maxe];
struct Ask
{
    int l, r, val;
    bool friend operator<(const Ask a, const Ask b)
    {
        return a.val < b.val;
    }
};
std::multiset<Ask> que;
struct Nd
{
    int val, id;
} blk[mbk][mbk];
inline int erfen(int sta, int end, Nd chk[], int cmp)
{
    int l = sta, r = end, res = end + 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (chk[mid].val >= cmp)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}
inline int find(Ask in)
{
    int ret = 0;
    int sta = in.l / len, end = in.r / len;
    int lin = sta == len ? last : len;
    for (int i = erfen(0, lin - 1, blk[sta], in.val); i < lin; i++)
    {
        if (blk[sta][i].id >= in.l && blk[sta][i].id <= in.r)
            ret++;
    }
    if (sta == end)
        return ret;
    for (int i = 1; i <= end - sta - 1; i++)
    {
        ret += len - erfen(0, len - 1, blk[sta + i], in.val);
    }
    lin = end == len ? last : len;
    for (int i = erfen(0, lin - 1, blk[end], in.val); i < lin; i++)
    {
        if (blk[end][i].id >= in.l && blk[end][i].id <= in.r)
            ret++;
    }
    return ret;
}
inline bool cmp(Nd a, Nd b)
{
    return a.val < b.val;
}
inline void chg(int bit, int val)
{
    int du = 0;
    if (in[bit] == val)
        return;
    int sml = std::min(in[bit], val) , big = std::max(in[bit], val);
    std::multiset<Ask>::iterator sta = in[bit] < val ? que.lower_bound(Ask{0, 0, sml}) : que.upper_bound(Ask{0, 0, sml});
    std::multiset<Ask>::iterator end = in[bit] < val ? que.lower_bound(Ask{0, 0, big}) : que.upper_bound(Ask{0, 0, big});
    while (sta != end)
    {
        Ask now = *sta;
        printf("ceswhi  %d %d %d\n", now.l, now.r, now.val);
        if (now.l <= bit && now.r >= bit && now.val >= sml && now.val <= big)
            du++;
        sta++;
    }
    ans += val > in[bit] ? du : -du;
    in[bit] = val;
}
void show()
{
    for (auto i : que)
    {
        printf("%d %d %d\n", i.l, i.r, i.val);
    }
}
int main()
{
    //freopen("seq.in", "r", stdin);
    //freopen("seq.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    len = std::sqrt(n), last = n - len * len;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            blk[i][j].id = i * len + j;
            scanf("%d", &blk[i][j].val);
            in[i * len + j] = blk[i][j].val;
        }
        std::sort(blk[i], blk[i] + len, cmp);
    }
    for (int i = 0; i < last; i++)
    {
        scanf("%d", &blk[len][i].val);
        blk[len][i].id = len * len + i;
        in[len * len + i] = blk[len][i].val;
    }
    if (!last)
    {
        std::sort(blk[num], blk[num] + last, cmp);
    }

    for (int i = 0; i < m; i++)
    {
        Ask in;
        scanf("%d%d%d", &in.l, &in.r, &in.val);
        in.l--;
        in.r--;
        ans += find(in);
        que.insert(in);
    } //show();
    printf("%d\n", ans);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a ^= ans;
        b ^= ans;
        chg(a - 1, b);
        printf("%d\n", ans);
    }
    return 0;
}