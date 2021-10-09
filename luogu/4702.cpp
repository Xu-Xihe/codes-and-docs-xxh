#include<cstdio>
int len;
long long ans;
int main()
{
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        long long a;
        scanf("%lld", &a);
        ans+=a;
    }
    printf("%s", ans % 2 == 1 ? "Alice" : "Bob");
    return 0;
}