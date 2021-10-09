#include <cstdio>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>
using std::max;
using std::min;
const int maxn = 1e4 + 9;
std::vector<int> next[maxn];
std::vector<int> nnet[maxn];
std::vector<int> root;
std::stack<int> run;
int n, m, val[maxn], dfn[maxn], low[maxn], cnt, nval[maxn], ans;
std::bitset<maxn> ins;
void tarjan(int now) //我们直接使用dfn[i]==0?来判断节点 i 是否被访问过
{
	ins[now] = 1; //对于任何一个没有被访问过的节点,有可能是根,加入栈
	run.push(now);
	dfn[now] = low[now] = ++cnt; //我们不清楚其子树
	for (int i : next[now])		 //遍历所有出度
	{
		if (!dfn[i]) //如果没有访问过,递归查找并update
		{
			tarjan(i);
			low[now] = min(low[now], low[i]);
		}
		else if (ins[i]) //如果访问过,直接更新
		{
			low[now] = min(low[now], low[i]);
		}
	}
	if (dfn[now] == low[now]) //我们搜索完了整个子树,若成立,即可判断当前节点是强连通分量的根
	{
		while (!run.empty() && dfn[run.top()] != low[run.top()]) //将压在当前节点上的都弹出
		{
			nval[low[now]] += val[run.top()];				//统计强连通分量中节点权值和
			low[run.top()] = min(low[run.top()], low[now]); //标记所有强连通分量的节！！！
			ins[run.top()] = 0;								//不在栈中了
			run.pop();
		}
		run.pop(); //同上
		ins[now] = 0;
		nval[low[now]] += val[now];
	}
}
void find(int now) //直接DFS暴搜找到最大路径
{
	cnt += nval[now];
	int len = nnet[now].size();
	if (!len)
	{
		ans = max(ans, cnt);
	}
	for (int i = 0; i < len; i++)
	{
		find(nnet[now][i]);
	}
	cnt -= nval[now];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
	}
	int u, v;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		next[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) //防止出现非连通图,对于所有没被遍历到的点做Tarjan
	{
		if (!dfn[i])
		{
			ins.reset(); //多次不清空,暴零两行泪
			while (!run.empty())
				run.pop();
			tarjan(i);
		}
	}
	ins.reset(); //废物利用qwq
	for (int j = 1; j <= n; j++)
	{
		for (int i : next[j])
		{
			if (low[j] != low[i]) //这就是传说中的缩点
			{
				nnet[low[j]].push_back(low[i]);
				ins[low[i]] = 1; //记录入度
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!ins[i]) //找到图中所有入度为0的点为根(非连通图可能有多个根)
		{
			root.push_back(i);
		}
	}
	for (int now : root) //对于每个根,跑DFS
	{
		cnt = 0; //又是废物利用qwq
		find(now);
	}
	printf("%d", ans);
	return 0;
}