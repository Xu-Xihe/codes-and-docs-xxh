#include<cstdio>
#include<cstring>
using namespace std;
int v, len;
long long dp[10005][1005];
/*void out()
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < v + 1; j++)
		{
			printf("%d ", dp[i][j]);
		}
		printf("\n\n");
	}
}*/
int main()
{
	scanf("%d%d", &v, &len);
	for (int i = 1; i <= v; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (j<i)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
				for (int z = 1;; z++)
				{
					int lin = j - (i + 1)*z;
					if (lin < 0)break;
					dp[i][j] += dp[i-1][lin];
				}
				if (j%(i+1)==0)
				{
					dp[i][j]++;
				}
			}
			//printf("hehe=%d %d\n",i,j);
			//out();
		}
	}
	printf("%lld", dp[len-1][v]);
	return 0;
}