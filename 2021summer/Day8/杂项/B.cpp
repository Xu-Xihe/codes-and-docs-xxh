#include<cstdio>
#include<algorithm>
using std::next_permutation;
using std::sort;
int len, ans;
char in[1000];
int main()
{
    scanf("%d%s", &len,in);
    sort(in, in + len);
    while (1)
    {
        printf("%s\n", in);
        ans++;
        if(!next_permutation(in,in+len))
            break;
    }
    printf("%d", ans);
    return 0;
}