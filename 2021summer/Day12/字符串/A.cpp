#include <cstdio>
#include <cstring>
using std::strlen;
const int maxe = 1e6 + 9;
int next[maxe], lena, lenb, ans;
char a[maxe], b[maxe];
void boot(int len, char *t)
{
    next[0] = next[1] = 0;
    for (int i = 1; i < len; ++i)
    {
        int j = next[i];
        while (j && t[i] != t[j])
            j = next[j];
        next[i+1] = t[i]==t[j]?j+1:0;
    }
}
int main()
{
    scanf("%s%s", a, b);
    lena = strlen(a);
    lenb = strlen(b);
    boot(lenb, b);
    for (int i = 0,j=0; i < lena; i++)
    {
        while(j&&a[i]!=b[j])
            j = next[j];
        if(a[i]==b[j])
            j++;
        if(j==lenb)
            ans++;
    }
    printf("%d", ans);
    return 0;
}