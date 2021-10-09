#include <cstdio>
using namespace std;
int dfs(int n, int m){
    if (n==1) return 1;
    int ans = ( (m%n) + dfs(n-1,m) )%n;
    if (ans == 0) ans = n;
    return ans;
}
int main (){
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        if (n==0 && m==0)
            break;
        printf("%d\n",dfs(n,m));
    }
    return 0;
}
