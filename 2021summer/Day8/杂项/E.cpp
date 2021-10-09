#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
using std::abs;
using std::less;
using std::min;
using std::set;
set<int, less<int>> run;
const int maxe = 1e5;
int len, ans;
/*void show()
{
    printf("\nshuchu:\n");
    for(auto x:run)
    {
        printf("%d   ", x);
    }
    printf("\n");
}*/
int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        int a;
        scanf("%d", &a);
        set<int>::iterator ite = run.lower_bound(a);
        if (run.begin() == run.end())
        {
            run.insert(a);
            ans += a;
            continue;
        }
        int aa = 2e9, bb = 2e9;
        if (ite != run.end())
            aa = *ite;
        if (ite != run.begin())
        {
            --ite;
            bb = *ite;
        }
        ans += min(abs(aa - a), abs(bb - a));
        run.insert(a);
        //show();
        //printf("\nce:-->  %d   %d   %9d  %9d %3d\n", i + 1, a, aa, bb, ans);
    }
    printf("%d\n", ans);
    return 0;
}