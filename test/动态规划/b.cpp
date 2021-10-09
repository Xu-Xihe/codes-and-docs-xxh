#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct ticket
{
	int cost, num;
} tic[12];
int ans, len, year;
int dp[4000770];
int ddp(int ben)
{
	for (int i = 1; i <= ben; i++)
	{
		dp[i]=0;
	}
	for (int i = 1; i <= len; i++)
	{
		for (int j = tic[i].cost; j <= ben; j++)
		{
			dp[j] = max(dp[j], dp[j - tic[i].cost] + tic[i].num);
		}
	}
	return dp[ben];
}
int main()
{
	int ci;
	scanf("%d", &ci);
	while (ci--)
	{
		scanf("%d%d", &ans, &year);
		scanf("%d", &len);
		for (int i = 1; i <= len; i++)
		{
			scanf("%d%d", &tic[i].cost, &tic[i].num);
			tic[i].cost /= 1000;
		}
		int s;
		for (int zz = 1; zz <= year; zz++)
		{
			s=ans/1000;
			ans+=ddp(s);
			//printf("%d    %d\n",ans,s);
		}
		printf("%d\n", ans);
	}
	return 0;
}