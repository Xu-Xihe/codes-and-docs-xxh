#include<cstdio>
#include<algorithm>
using std::sort;
const int maxe = 4e6;
int len, ans[maxe],loe;
bool ji[maxe];
int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        int a;
        scanf("%d", &a);
        if(!ji[a])
        {
            ji[a] = 1;
            ans[loe++]=a;
        }
    }
    printf("%d\n", loe);
    sort(ans, ans + loe);
    for (int i = 0; i < loe; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}