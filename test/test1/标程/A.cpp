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
const int maxn = 2010;
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
struct edge{
    int u,v,d;
}E[maxn*maxn];
bool cmp(edge a, edge b){
    return a.d<b.d;
}
int getDistance(char s1[],char s2[]){
    int lens = strlen(s1), ans = 0;
    for  (int i = 0 ;i< lens ;i++)
        if (s1[i] != s2[i])
            ans ++;
    return ans;
}
char s[maxn][100];
int n;
int main(){
    while (~scanf("%d",&n)&&n){
        for (int i = 0 ;i<n ;i++)
            scanf("%s",s[i]);
        int totl = 0;
        for (int i = 0 ;i< n ;i++)
            for (int j = i+1 ;j< n ;j++){
                E[totl].u = i;
                E[totl].v = j;
                E[totl++].d = getDistance(s[i], s[j]);
            }
        sort(E,E+totl,cmp);
        init(n);
        int edgeNum = 0,ans = 0;
        for (int i = 0 ;i< totl&& edgeNum<n-1 ;i++){
            if (Find(E[i].u)!=Find(E[i].v)){
                update(E[i].u, E[i].v);
                ans += E[i].d;
                edgeNum++;
            }
        }
        printf("The highest possible quality is 1/%d.\n",ans);


    }
    return 0;
}
