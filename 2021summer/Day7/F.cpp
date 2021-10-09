#include<cstdio>
const int maxe = 1e5+10;
int len,m;
int tree[maxe];
int find(int x)
{
    int ans=0;
    for(;x>0;x-=x&-x)ans^=tree[x];
    return ans;
}
void add(int x,int val)
{
    for(;x<=len;x+=x&-x)tree[x]^=val;
}
int main()
{
    scanf("%d%d",&len,&m);
    while (m--)
    {
        int a,b,c;
        scanf("%d%d",&a,&b);
        if(a==1)
        {
            scanf("%d",&c);
            add(b,1);
            add(c+1,1);
        }
        else
        {
            printf("%d\n",find(b));
        }
    }
    return 0;
}