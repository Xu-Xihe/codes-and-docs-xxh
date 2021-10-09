#include<cstdio>
#include<algorithm>
int t,k,m,n,ans;
long long jiecheng(int a){
    if(a==0)return 1;
    long long ans=1;
    for (int i = 2; i <= a; i++)
    {
        ans*=i;
    }
    return ans;
}
long long C(int n,int m){
    return jiecheng(n)/(jiecheng(m)*jiecheng((n-m)));
}
int main(){
    scanf("%d%d",&t,&k);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < std::min(i,m); j++)
            {
                if(C(i,j)%k==0)ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}