#include<cstdio>
#include<algorithm>
using std::sort;
using std::unique;
const int maxe = 4e6;
int len, ans[maxe],loe;
int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &ans[i]);
    }
    sort(ans, ans + len);
    loe = unique(ans, ans + len) - ans;
    printf("%d\n", loe);
    for (int i = 0; i < loe; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}