#include<iostream>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main()
{
	int n;
	char map[101][101];
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> map[i][j];
	int m;
	cin >> m;
	for(int i = 2; i <= m; ++i)
	{
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(map[i][j] == '@')
					for(int k = 0; k < 4; ++k)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if(map[nx][ny] == '.')
							map[nx][ny] = 'a';
					}
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(map[i][j] == 'a')
					map[i][j] = '@';
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(map[i][j] == '@')
			 ++cnt;
	cout << cnt;
	return 0;
}
