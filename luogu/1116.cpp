#include<cstdio>
#define maxe 10005
int len,in[maxe],ans;
int main(){
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&in[i]);
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j < len; j++)
        {
            if(in[j-1]>in[j]){
                int a=in[j];
                in[j]=in[j-1];
                in[j-1]=a;
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}