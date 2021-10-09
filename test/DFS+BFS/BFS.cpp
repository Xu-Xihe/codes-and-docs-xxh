#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 220;
struct node{
	int x, dist;
};
int n,num[maxn],startPos, endPos;
int visited[maxn];
int MyPush(queue <node> &que, int nowPos, int dist){
	if (nowPos >=1 && nowPos <=n && visited[nowPos] == 0){
		visited[nowPos] = 1;
		node tmp; tmp.x = nowPos; tmp.dist = dist + 1;
		que.push(tmp);
	}
}
int bfs(int stairs[], int startPos , int endPos){
	//初始化
	queue <node> que;
	memset(visited, 0 ,sizeof visited);
	while (!que.empty()) que.pop();
	node tmp; tmp.x=startPos; tmp.dist = 0;
	visited[startPos] = 1;
	que.push(tmp);
	//BFS过程
	while (!que.empty()){
		//弹出队列头部元素
		node nowNode = que.front();
		int x = nowNode.x;
		int dist = nowNode.dist;
		if (x == endPos) return dist;
		que.pop();
		//根据元素查找相邻元素
		MyPush(que,x + stairs[x],dist);
		MyPush(que,x - stairs[x],dist);
	}
	return -1;
}
int main(){
	while (~scanf("%d",&n)){
		if (n==0) break;
		scanf("%d%d",&startPos, &endPos);
		for (int i = 1 ;i<= n;i++)
			scanf("%d",&num[i]);
		printf("%d\n",bfs(num,startPos,endPos));
	}
	return 0;
}