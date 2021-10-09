#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
char reback(int in){
    in/=3;
    in-=27;
    in*=in<0?-1:1;
    in=sqrt(in);
    char a=in;
    return a;
}
char a[10000];
int main(){
    freopen("out.cpp","r",stdin);
    scanf("%s",a);
    freopen(a,"w",stdout);
    int c,b;
    scanf("%d%d%d",&b,&b,&c);
    for (int i = 0; i < c; i++)
    {
        scanf("%d",&b);
    }
    while (~scanf("%d",&c))
    {
        printf("%c",reback(c));
    }
    return 0;
}