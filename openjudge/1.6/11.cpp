#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxe 3000
using namespace std;
struct xxh
{
    int len;
    int a[maxe];
};
xxh a,b,c;
void in(xxh&a){
    char lin[maxe];
    scanf("%s",lin);
    int len=strlen(lin);
    int ci=len/9;
    if (len%9!=0)ci++;
    a.len=ci;
    for (int i = 0; i < ci; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int ans=len-j-i*9-1;
            if(ans<0)return ;
            ans=lin[ans]-'0';
            for (int z = 0; z < j; z++)
            {
                ans*=10;
            }
            a.a[i]+=ans;
        }
    }
}
int main(){
    in(a);
    in(b);
    for (int i = 0; i < max(a.len,b.len); i++)
    {
        c.a[i]=a.a[i]-b.a[i];
    }
    c.len=max(a.len,b.len)-1;
    for (int i = 0; i < c.len; i++)
    {
        if (c.a[i]<0)
        {
            c.a[i+1]-=1;
            c.a[i]+=1e9;
        }
    }
    bool l=false;
    for (int i = c.len; i >= 0; i--)
    {
        int j=c.a[i];
        if (l==false)
        {
            if(j!=0)l=true;
        }
        if (l)
        {
            if(c.a[i+1]>0)printf("%09d",c.a[i]);
            else printf("%d",c.a[i]);
        }
    }
    if(!l)printf("0");
    return 0;
}