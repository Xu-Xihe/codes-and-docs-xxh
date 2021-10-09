#include<cstdio>
#include<unordered_map>
std::unordered_map<long long, long long> in;
long long key, val;
int len,opt;
int main()
{
    scanf("%d", &len);
    while (len--)
    {
        scanf("%d%lld", &opt, &key);
        if(opt==1)
        {
            scanf("%lld", &val);
            in[key] = val;
        }
        else
            printf("%lld\n", in[key]);
    }
    return 0;
}