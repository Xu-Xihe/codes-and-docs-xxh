#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n, m;
	int together[150][150][100];
	int ox[10] = {-1,-1,-1,0,0,1,1,1};
	int oy[10] = {-1,0,1,-1,1,-1,0,1};
	while (~scanf ("%d%d", &m, &n)){
		memset(together, 0 , sizeof together);
		together[4][4][0] = m;
		for (int t = 1 ; t<=n ;t ++){
			int now_id = t%2;
			int pre_id = (t+1)%2;
			for (int i = 0 ;i< 9;i++){
				for (int j = 0 ;j< 9;j++){
					together[i][j][now_id] = together[i][j][pre_id]*2;
					for (int op = 0; op<8; op++){
						int nx = i + ox[op];
						int ny = j + oy[op];
						if (nx >= 0 && nx < 9 && ny>=0 && ny<9){
							together[i][j][now_id] += together[nx][ny][pre_id];
						}
					}
				}
			}
		}
		int ans_id = n%2;
		for (int i = 0 ;i< 9 ;i++){
			for (int j = 0 ;j< 9 ;j++){
				if (j==8)
					printf("%d\n",together[i][j][ans_id]);
				else
					printf("%d ",together[i][j][ans_id]);
			}
		}
			
		
	}
	return 0;
}
