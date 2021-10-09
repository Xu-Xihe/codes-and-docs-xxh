#include<cstdio>

int main(){
    int a;
    freopen("in.out","r",stdin);
    freopen("out.txt","w",stdout);
    printf("int out_one[]={");
    int b=0;
    while (~scanf("%d",&a))
    {
        printf("%d,",a);
        b++;
    }
    printf("};\nb=%d",b);
    return 0;
}