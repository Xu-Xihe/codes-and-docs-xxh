#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int dx[3]={-1,1,2},n,k;
bool vis[N];
struct node{
    int x;
    int step;
};
bool isOK(node now){
    if(now.x<0||now.x>100000||vis[now.x]==true) return false;
    else return true;
}
void bfs(int n,int k){
    memset(vis,0,sizeof vis);
    queue<node> p;
    while(!p.empty()) p.pop();
    node tmp;
    tmp.x=n,tmp.step=0;
    vis[tmp.x]=true;
    p.push(tmp);
    while(!p.empty()){
        node now;
        now=p.front();
        p.pop();
        vis[now.x]=true;
        if(now.x==k){
            printf("%d\n",now.step);
            return;
        }
        for(int i=0;i<3;i++){
            node next;
            if(i==2){
                next.x=now.x*dx[i];
            }
            else {
                next.x=now.x+dx[i];
            }
            if(isOK(next)){
                next.step=now.step+1;
                vis[next.x]=true;
                p.push(next);
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
        bfs(n,k);
    return 0;
}