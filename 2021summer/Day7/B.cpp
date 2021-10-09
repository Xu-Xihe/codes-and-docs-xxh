#include<cstdio>
const int maxe = 2e6;
int n,q,sum,tree[maxe];
int find(int x)
{
    int ans=0;
    for(;x>0;x-=x&-x)ans+=tree[x];
    return ans;
}
void add(int x,int val)
{
    for(;x<=n;x+=x&-x)tree[x]+=val;
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d",&a);
        add(i,a-sum);
        sum=a;
    }
    for (int i = 0; i < q; i++)
    {
        char a[221];
        int x,y,z;
        scanf("%s%d",a,&x);
        if(a[0]=='Q')
        {
            printf("%d\n",find(x));
        }
        else
        {
            scanf("%d%d",&y,&z);
            add(x,z);
            add(y+1,-z);
        }
    }
    return 0;
}