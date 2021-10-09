#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<iostream>
#define maxe 20000
using namespace std;
map<string,int >num;
struct www{
    int nodeid,valu;
    friend bool operator<(www a,www b){
        return a.valu>b.valu;
    }
};
struct ww
{
    int nodeid,valu;
};
vector<ww>ways[maxe];
priority_queue<www>runing;
string str,ed;
int len,dist[maxe];
int bfs(string start,string ed){
    www a;
    a.nodeid=num[start];
    a.valu=0;
    dist[a.nodeid]=0;
    runing.push(a);
    while(!runing.empty()){
        www fl=runing.top();
        runing.pop();
        int size=ways[fl.nodeid].size();
        for (int i = 0; i < size; i++)
        {
            if (dist[fl.nodeid]+ways[fl.nodeid][i].valu<dist[ways[fl.nodeid][i].nodeid])
            {
                dist[ways[fl.nodeid][i].nodeid]=dist[fl.nodeid]+ways[fl.nodeid][i].valu;
                www fff;
                fff.valu=dist[ways[fl.nodeid][i].nodeid];
                fff.nodeid=ways[fl.nodeid][i].nodeid;
                runing.push(fff);
                //printf("%d<------%d\n",fff.valu,fff.nodeid);
            }
        }
        //printf("%d %d \n",fl.nodeid,fl.valu);
        //for(int i=0;i<num.size();i++)printf("%d--->%d\n",i+1,dist[i+1]);
    }
    return dist[num[ed]]==1e9||num[ed]<=0?-1:dist[num[ed]];
}
int main(){
    while (~scanf("%d",&len))
    {
        if(len==-1)return 0;
        num.clear();
        for(int i=0;i<200;i++)ways[i].clear();
        while(!runing.empty())runing.pop();
        cin >> str >> ed;
        for (int i = 0,j = 0,cnt = 1; i < len; i++)
        {
            int v;
            string a,b;
            cin >> a >> b >> v;
            if (num[a] == 0)
            {
                num[a] = cnt++;
            }
            if (num[b]==0)
            {
                num[b] = cnt++;
            }
            ww l;
            l.valu=v;
            l.nodeid=num[a];
            ways[num[b]].push_back(l);
            l.nodeid=num[b];
            ways[num[a]].push_back(l);
        }
        for(int i=0;i<=num.size();i++)dist[i]=1e9;
        printf("%d\n",bfs(str,ed));
    }
    return 0;
}