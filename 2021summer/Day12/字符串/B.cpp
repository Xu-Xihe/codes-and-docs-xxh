#include<cstdio>
#include<cstring>
using std::strlen;
using std::strstr;
char a[2000], b[2000];
int ans,len;
char *now;
int main()
{
    while (scanf("%s",a))
    {
        if(a[0]=='#'&&a[1]==0)
            return 0;
        scanf("%s", b);
        ans = 0;
        now = a;
        len = strlen(b);
        while((now=strstr(now,b))!=NULL)
        {
            now += len;
            ans++;
        }
        printf("%d\n", ans);
    }
}