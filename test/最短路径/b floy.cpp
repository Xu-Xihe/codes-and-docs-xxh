#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxe 200000
using namespace std;
map<string, int> visit;
int len;
string start, endll;
bool ji[maxe];
struct way
{
	string start, end;
	int far;
} ways[maxe];
void chu(int bfs[],int len)
{
    for (int i = 1; i <= len; i++)
    {
        bfs[i] = 1e9;
    }
    for (int i = 1; i <= len; i++)
    {
        ji[i] = 0;
    }
}
int minn(bool a[], int zhi[], int len)
{
    int small = 1e9;
    int ji = -1;
    for (int i = 1; i <= len; i++)
    {
		//printf("%d--->%d\n",i,zhi[i]);
        if (a[i] == 0 && zhi[i] < small)
        {
            small = zhi[i];
            ji = i;
        }
    }
    return ji;
}
bool operator<(way a, way b)
{
	return a.far > b.far;
}
int flo()
{
	int bfs[maxe];
	int stn = visit[start];
	int llen=visit.size();
	chu(bfs,llen);
	bfs[stn] = 0;
	for (int i = 0; i <= llen; i++)
	{
		for (int j = 0; j < len*2; j++)
		{
			if(visit[ways[j].start]==stn)
				bfs[visit[ways[j].end]]=min(bfs[visit[ways[j].end]],bfs[stn]+ways[j].far);
			ji[stn]=true;
			//printf("%d   %d   %d\n",stn,visit[ways[j].start],visit[ways[j].end]);
		}
		//for(int i=0;i<len;i++)printf("%d-->%d\n",i+1,bfs[i+1]);
		stn=minn(ji,bfs,len);
		if(stn==-1)break;
	}
	return bfs[visit[endll]]<1e9&&visit[endll]>0?bfs[visit[endll]]:-1;
}
int main()
{
	while (~scanf("%d", &len))
	{
		visit.clear();
		if (len == -1)
		{
			return 0;
		}
		cin >> start >> endll;
		for (int i = 0, cnt = 1; i < len*2; i++)
		{
			string a,b;
			int c;
			cin >> a >> b >> c;
			ways[i].start=a;
			ways[i].end=b;
			ways[i++].far=c;
			ways[i].start=b;
			ways[i].end=a;
			ways[i].far=c;
			if (visit[a] == 0)
			{
				visit[a] = cnt;
				cnt++;
			}
			if (visit[b] == 0)
			{
				visit[b] = cnt;
				cnt++;
			}
		}
		printf("%d\n",flo());
	}
}