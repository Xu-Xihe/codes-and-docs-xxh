#include<stdio.h>
using namespace std;
int in[103][103],h,l,nx,qishi,ny;
int main(){
	scanf("%d%d",&h,&l);
	for(int i=0;i<h;i++)
		for(int j=0;j<l;j++)
		scanf("%d",&in[i][j]);
	for(;qishi<l;qishi++){
		nx=0;
		ny=qishi;
		while(nx<h){
			if(ny<0)break;
			printf("%d\n",in[nx][ny]);
			nx++;
			ny--;
		}
	}
	for(qishi=1;qishi<h;qishi++){
		nx=qishi;
		ny=l-1;
		while(nx<h){
			if(ny<0)break;
			printf("%d\n",in[nx][ny]);
			nx++;
			ny--;
		}
	}
	return 0;
}
