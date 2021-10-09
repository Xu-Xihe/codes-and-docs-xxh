#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
map<string,int> buzz;
int n,startId,endId,tot;
int dis_start[N];
struct node{
    int next;
    int dis;
};
vector<node> op[N];
int skr(string s){
    if(buzz[s]==0) buzz[s]=tot++;
    return buzz[s];
}
int bfs(int startId,int endId){
    memset(dis_start,-1,sizeof dis_start);
    if(startId==endId) return 0;
    queue<node> m;
    node tmp;
    tmp.next=startId;tmp.dis=0;
    m.push(tmp);
    for(int i=0;i<tot;i++) dis_start[i]=INT_MAX;
    dis_start[startId]=-1;
    while(!m.empty()){
        tmp=m.front();
        m.pop();
        for(int i=0;i<op[tmp.next].size();i++){
            int next=op[tmp.next][i].next;
            int dist=op[tmp.next][i].dis;
            if(dist+tmp.dis<dis_start[next]){
                dis_start[next]=dist+tmp.dis;
                node tmp_tmp;
                tmp_tmp.next=next;tmp_tmp.dis=dis_start[next];
                m.push(tmp_tmp);
            }
        }
    }
    if(dis_start[endId]==INT_MAX) return -1;
    else return dis_start[endId];
}
int main(){
    while(~scanf("%d",&n)&&n!=-1){
        buzz.clear();
        for(int i=0;i<N;i++) op[i].clear();
        tot=1;
        string s;
        cin>>s;startId=skr(s);
        cin>>s;endId=skr(s);
        for(int i=0;i<n;i++){
            int tmp_s,tmp_e,tmp_dis;
            cin>>s;tmp_s=skr(s);
            cin>>s;tmp_e=skr(s);
            scanf("%d",&tmp_dis);
            node tmp;
            tmp.next=tmp_e;tmp.dis=tmp_dis;//双向边
            op[tmp_s].push_back(tmp);//双向边
            tmp.next=tmp_s;//双向边
            op[tmp_e].push_back(tmp);//双向边
        }
        printf("%d\n",bfs(startId,endId));
    }
    return 0;
}