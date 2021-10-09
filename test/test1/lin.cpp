
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
bool m(int n, int c[])
{
    const int N = 10010;
    int w[] = {1, 2, 3, 4, 5, 6}, t[N], f[N], pos[N], ans[N];
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));
    memset(pos, 0, sizeof(pos));
    memset(ans, 0, sizeof(ans));
    f[0] = 1;
    for (int i = 0; i < 6; i++)
    {
        memset(t, 0, sizeof(t));
        for (int j = 1; j <= n; j++)
        {
            if (t[j - w[i]] < c[i] && f[j - w[i]] && f[j] < (f[j - w[i]] + 1))
            {
                f[j] = f[j - w[i]] + 1;
                t[j] = t[j - w[i]] + 1;
                pos[j] = j - w[i];
            }
        }
    }
    int find = n;
    if (f[find])
    {
        while (find)
        {
            ans[find - pos[find]]++;
            find = pos[find];
        }
        for (int i = 0; i <= 5; i++)
            c[i] -= ans[w[i]];
        return true;
    }
    return false;
}
int main(){
    int a[6],b;
    scanf("%d",&b);
    for (int i = 0; i < 6; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",m(b,a));
}