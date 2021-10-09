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
struct edge{
    int u,v,d;
}E[maxn*maxn];
bool cmp(edge a, edge b){
    return a.d<b.d;
}
int fa[maxn];
void init(int n){
    for (int i = 0 ;i<= n ;i++)
        fa[i] = i;
}
int Find(int v){
    if (v == fa[v])
        return v;
    fa[v] = Find(fa[v]);
    return fa[v];
}
void update(int u, int v){
    int fu = Find(u);
    int fv = Find(v);
    fa[fu] = fv;
}
int main(){
    int n;
    while (~scanf("%d",&n)&&n){
        for (int i = 0; i< n*(n-1)/2;i++)
            scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].d);
        sort(E,E+n*(n-1)/2,cmp);
        init(n);
        int edgeNum = 0,ans = 0;
        for (int i = 0 ;i< (n-1)*n/2&& edgeNum<n-1 ;i++){
            if (Find(E[i].u)!=Find(E[i].v)){
                update(E[i].u, E[i].v);
                ans += E[i].d;
                edgeNum++;
            }
        }
        printf("%d\n",ans);
    }
}

