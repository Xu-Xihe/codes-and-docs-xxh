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
    int nextId;
    double dist;
};
vector <edge> node[maxn];
const int INF = 1e9;
double dist[maxn];
int n;
struct upd{
    int nextId;
    double val;
    friend bool operator < (upd a, upd b)
    {
        //结构体中，x小的优先级高
        return a.val > b.val;
    }
};
void SPFA(int sNode){
    priority_queue <upd> que;
    upd tmp; tmp.nextId = sNode; tmp.val = 0;
    que.push(tmp);
    for (int i = 0 ;i<= n ;i++)
        dist[i] = INF;
    dist[sNode] = 0;
    while (!que.empty()){
        upd tmp = que.top();
        int nId = tmp.nextId;
        que.pop();
        for (int i = 0 ;i< node[nId].size() ;i++){
            int nextId = node[nId][i].nextId;
            if (max(node[nId][i].dist , dist[nId])< dist[nextId]){
                dist[nextId] = max(node[nId][i].dist , dist[nId]);
                tmp.nextId = nextId;
                tmp.val = dist[nextId];
                que.push(tmp);
            }
        }
    }
}
struct point{
    double x;
    double y;
}nodeXY[maxn];
double getDistance(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main (){
    int t = 1;
    while (~scanf("%d",&n)&&n){
        for (int i = 0 ;i< n ;i++)
            scanf("%lf%lf",&nodeXY[i].x,&nodeXY[i].y);
        for (int i = 0 ;i< n ;i++) node[i].clear();
        for (int i = 0 ;i< n ;i++)
            for (int j = i+1 ;j<n ;j++){
                edge tmp; tmp.dist = getDistance(nodeXY[i], nodeXY[j]);
                tmp.nextId = j;
                node[i].push_back(tmp);
                tmp.nextId = i;
                node[j].push_back(tmp);
            }
        SPFA(0);
        printf("Scenario #%d\n",t++);
        printf("Frog Distance = %.3lf\n\n",dist[1]);
    }
    return 0;
}
