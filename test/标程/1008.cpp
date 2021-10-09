#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1010;
struct node {
	int x;
	int y;
};
int matrix_int[maxn][maxn];
int n;
node getNextPoint(node a){
	node b;
	if (a.x== 0 && a.y==n-1){
		b.x = 1;
		b.y = n-1;
		return b;
	}
	b.x = (n+a.x-1)%n;
	b.y = (n+a.y+1)%n;
	if (matrix_int[b.x][b.y]>0){
		b.x = (n+a.x+1)%n;
		b.y = (n+a.y)%n;
	}
	return b;
}
int main (){
	while (~scanf("%d",&n)){
		memset(matrix_int,0,sizeof matrix_int);
		n = n*2 - 1;
		node point;
		point.x = 0;
		point.y = (n-1)/2;
		int cnt = 1;
		while (cnt<=n*n){
			matrix_int[point.x][point.y] = cnt++;
			point = getNextPoint(point);
		}
		for (int i = 0 ;i< n;i++){
			for (int j = 0 ;j< n;j++){
				printf("%d ",matrix_int[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
