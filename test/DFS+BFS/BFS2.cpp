#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct xxh
{
	int x, y, ans;
};
queue<xxh> runing;
int str_x, str_y, end_x, end_y;
bool ji[9][9];
int next_w_x[] = {-2, -2, 2, 2, -1, -1, 1, 1};
int next_w_y[] = {1, -1, -1, 1, 2, -2, 2, -2};
int inde[] = {0, 8, 7, 6, 5, 4, 3, 2, 1};
bool isok(int x, int y)
{
	if (x < 1 || y < 1 || x > 8 || y > 8 || ji[x][y])
		return false;
	else
		return true;
}
int bfs(xxh in)
{
	while (!runing.empty())
		runing.pop();
	runing.push(in);
	while (!runing.empty())
	{
		int frx = runing.front().x;
		int fry = runing.front().y;
		int fra = runing.front().ans;
		//printf("-->%d %d %d \n",frx,fry,fra);
		if (frx == end_x && fry == end_y)
			return fra;
		for (int i = 0; i < 8; i++)
		{
			xxh nt;
			nt.x = frx + next_w_x[i];
			nt.y = fry + next_w_y[i];
			if (isok(nt.x, nt.y))
			{
				nt.ans = fra + 1;
				ji[nt.x][nt.y] = true;
				runing.push(nt);
				//printf("aa");
			}
		}
		runing.pop();
	}
	return -1;
}
int main()
{
	char kong[4];
	while (~scanf("%c%d%c%c%d%c", &str_x, &str_y, &kong[2], &end_x, &end_y, &kong[3]))
	{
		memset(ji, 0, sizeof(ji));
		str_x -= 'a' - 1;
		end_x -= 'a' - 1;
		int a = str_y, b = end_y;
		str_y = inde[a];
		end_y = inde[b];
		xxh start;
		start.x = str_x;
		start.y = str_y;
		start.ans = 0;
		printf("To get from %c%d to %c%d takes %d knight moves.\n", str_x + 'a' - 1, a, end_x + 'a' - 1, b, bfs(start));
	}
	return 0;
}