#include <cstdio>
const int maxe = 1e6 + 9;
int n, num[maxe], tot = 1,lin;
inline bool con(int a,int b)
{
    return (a < 0 && b > 0) || (a > 0 && b < 0) ? true : false;
}
int main()
{
    scanf("%d", &n);
    while (num[1] < 0)
    {
        scanf("%d", &num[1]);
        n--;
    }
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &lin);
        num[con(lin, num[tot]) ? ++tot : tot] += lin;
    }
    if(num[tot]<0)
        tot--;
    
}