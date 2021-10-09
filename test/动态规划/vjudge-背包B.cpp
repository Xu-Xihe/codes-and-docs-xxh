#include<cstdio>
#include<climits>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 50000+5;
int n,tim,m;
int f[N],w[N],v[N];
int main(){
    int tot;
    scanf("%d",&tot);
    while(tot--){
        scanf("%d%d",&n,&tim);
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&w[i],&v[i]);
            w[i]/=1000;
        }
        int s;
        for(int i=1;i<=tim;i++){
            memset(f,0,sizeof f);
            s=n/1000;
            for(int i=1;i<=m;i++){
                for(int j=w[i];j<=s;j++){
                    f[j]=max(f[j],f[j-w[i]]+v[i]);
                }
            }
            n+=f[s];
        }
        printf("%d\n",n);
        //system("pause");
    }
    return 0;
}