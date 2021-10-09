#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int maxn = 1010;
int n,k;
bool visited[maxn];
char s[maxn][maxn];
int dfs(int dep, int num){
    if (num == k)
        return 1;
    if (dep == n)
        return 0;
    int ans = dfs(dep+1, num);
    for (int i = 0 ;i<n ;i++){
        if (!visited[i] && s[dep][i]=='#'){
            visited[i] = 1;
            ans += dfs(dep+1,num+1);
            visited[i] = 0;
        }
    }
    return ans;
}
int main (){
    while (~scanf("%d%d",&n,&k)){
        if (n==k && k==-1)
            break;
        for (int i = 0 ;i< n ;i++)
            scanf("%s",s[i]);
        printf("%d\n",dfs(0,0));
    }
}
