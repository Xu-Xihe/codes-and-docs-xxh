#include<stdio.h>
#include<queue>
#include<cstring>
#define maxe 300
using namespace std;
int a,b,len;
int in[maxe];
bool ji[maxe];
struct xxh
{
	int num,ans;
};
queue<xxh>run;
bool ok(int a){
	if(a<1||a>len||ji[a])return false ;
	else return true;
}
void pushed(xxh in){
	ji[in.num]=true;
	run.push(in);
}
int bfs(xxh start){
	while (!run.empty())
	{
		run.pop();
	}
	run.push(start);
	while (!run.empty())
	{
		int ftn=run.front().num;
		int fta=run.front().ans;
		if (ftn==b)
		{
			return fta;
		}
		xxh next_1;
		next_1.num=ftn+in[ftn];
		next_1.ans=fta+1;
		xxh next_2;
		next_2.num=ftn-in[ftn];
		next_2.ans=fta+1;
		if (ok(next_1.num))
		{
			pushed(next_1);
		}
		if (ok(next_2.num))
		{
			pushed(next_2);
		}
		run.pop();
	}
	return -1;
}
int main(){
	while(1)
	{
		memset(ji,0,sizeof(ji));
		scanf("%d",&len);
		if(len==0)return 0;
		scanf("%d%d",&a,&b);
		for (int i = 1; i <= len; i++)
		{
			scanf("%d",&in[i]);
		}
		if (!ok(a)||!ok(b))
		{
			printf("-1\n");
			continue;
		}
		if(a==b){
			printf("0\n");
			continue;
		}
		xxh aa;
		aa.num=a;
		aa.ans=0;
		ji[a]=true;
		printf("%d\n",bfs(aa));
	}
}