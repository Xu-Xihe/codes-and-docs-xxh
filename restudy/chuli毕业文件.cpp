#include<cstdio>
char in[7][50];
int main()
{
    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    int len;
    scanf("%d",&len);
    while(len--)
    {
        for (int i = 0; i < 7; i++)
        {
            scanf("%s",in[i]);
        }
        printf("%s",in[0]);
        if (in[1][0]!='/')printf("(%s)",in[1]);
        printf("\n");
        printf("电话：%s 生日：%s\n",in[2][0]=='/'?"":in[2],in[3][0]=='/'?"":in[3]);
        printf("QQ：%s 微信号：%s\n",in[4][0]=='/'?"":in[4],in[5][0]=='/'?"":in[5]);
        printf("E-mail：%s\n",in[6][0]=='/'?"":in[6]);
    }
    return 0;
}