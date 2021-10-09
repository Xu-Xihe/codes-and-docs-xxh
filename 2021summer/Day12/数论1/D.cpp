#include <cstdio>
#include <cmath>
const int maxe = 1e6 + 9;
int cnt;
long long su[maxe], fir, end;
bool ji[maxe], run[maxe];
void ola(int len)
{
    for (int i = 2; i <= len; i++)
    {
        if (!ji[i])
            su[cnt++] = i;
        for (int j = 0; j < cnt; j++)
        {
            long long a = i * su[j];
            //printf("ce-->  %d   %d\n", i, j);
            if (a <= len)
                ji[a] = 1;
            if (!(i % su[j]))
                break;
        }
    }
}
bool ack(long long x)
{
    if (x >= fir && x <= end)
    {
        run[x - fir] = 1;
        return true;
    }
    return false;
}
int mark()
{
    int ans = 0;
    for (int i = 0; i < cnt; i++)
    {
        int start = fir / su[i] * su[i];
        if (start == 0)
            start += su[i];
        if (start == su[i] || !ack(start))
            start += su[i];
        while (ack(start))
            start += su[i];
    }
    for (int i = 0; i <= end - fir; i++)
    {
        if (!run[i])
            ans++;
        //else printf("%d ", i+fir);
    }
    return ans;
}
int main()
{
    scanf("%lld%lld", &fir, &end);
    if (fir < 2)
        fir = 2;
    ola(sqrt(end));
    /*for (int i = 0; i < cnt; i++)
    {
        printf("%d ", su[i]);
    }
    printf("\n");*/
    printf("%d\n", mark());
    return 0;
}