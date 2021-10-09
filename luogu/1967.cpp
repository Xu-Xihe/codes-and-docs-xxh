#include<cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
const int maxe = 10009;
int edge[maxe][maxe];
bool in[maxe];
struct way
{
	int city1, city2, weigh;
	bool friend operator<(way a, way b)
	{
		return a.weigh < b.weigh;
	}
};
struct node
{
	int sign, num;
};
vector<int> fa;			 //并查集fa数组
queue<way> running;		 //运行队列 city1=last city2=now
vector<node> nodes;		 //父节点维护
priority_queue<way> ways;
void out()
{
	printf("\n\nceshi:\n\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%10d  ", edge[i + 1][j + 1]);
		}
		printf("\n\n");
	}
	printf("\n\n");
	return;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void together(int a, int b)
{
	int x = find(a), y = find(b);
	fa[x] = y;
	return;
}
void node_in(int floor, int last, int now)
{
	node lin;
	lin.sign = now;
	lin.num = floor;
	nodes.push_back(lin);
	way a;
	a.city1 = last;
	a.city2 = now;
	a.weigh = floor;
	running.push(a);
	in[now]=true;
	return ;
}
void bfs(int start, int ans)
{
	running.empty();
	nodes.clear();
	node_in(0, 0, start);
	//初始化
	int least;
	bool ji;
	while (1)
	{
		ji = false;
		way top = running.front();
		running.pop();
		//printf("\ntitle= %d %d \n\n", top.city2, top.weigh);
		int lena = nodes.size();
		for (int i = 0; nodes[i].num <= top.weigh && i < lena; i++)
		{
			if (nodes[i].sign == top.city2)
			{
				ji = true;
				continue;
			}
			if (nodes[i].sign == top.city1 || (nodes[i].num == top.weigh && !ji))
				continue;
			edge[nodes[i].sign][top.city1] += edge[nodes[i].sign][top.city1] == 0 ? 2e9 : 0;
			least = edge[nodes[i].sign][top.city1] < edge[top.city1][top.city2] ? edge[nodes[i].sign][top.city1] : edge[top.city1][top.city2];
			edge[nodes[i].sign][top.city2] = least;
			edge[top.city2][nodes[i].sign] = least;
			//out();
			//printf("\nchange:-->%d -->%d\n",nodes[i].sign,i);
		}
		for (int i = 0; i < n; i++)
		{
			if(edge[top.city2][i]>0&&edge[top.city2][i]<2e9&&!in[i])
			{node_in(top.weigh + 1, top.city2,i);
			printf("in:floor-->%d last-->%d now-->%d \n", top.weigh + 1, top.city2, i);}
		}
		if (ans == top.city2)
		{
			printf("%d\n", edge[ans][start]);
			return;
		}
		printf("\n\none round\n\n");
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		fa.push_back(i);
	} //初始化数组
	for (int i = 0; i < m; i++)
	{
		way in;
		scanf("%d%d%d", &in.city1, &in.city2, &in.weigh);
		ways.push(in);
	} //读入路线
	for (int i = 0; i < m; i++)
	{
		way top = ways.top();
		ways.pop();
		if (find(top.city1) != find(top.city2))
		{
			together(top.city1, top.city2);
			edge[top.city1][top.city2] = top.weigh;
			edge[top.city2][top.city1] = top.weigh;
		}
	} //最小生成树+节点记录
	int len;
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(find(a)!=find(b))
		{
			printf("-1\n");
			continue;
		}
		memset(in,0,sizeof(in));
		bfs(a, b);
	}
	return 0;
}