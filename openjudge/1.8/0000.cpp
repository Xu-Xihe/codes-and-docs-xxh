#include<stdio.h>
using namespace std;
int in[105][105],h,l,ax,bx,z;
int main(){
	scanf("%d%d",&h,&l);
	for(int i=0;i<h;i++)
		for(int j=0;j<l;j++)
		scanf("%d",&in[i][j]);
	for(int i=1;i<=(h*l);i++){
		printf("%d\n",in[ax][bx]);
		if(in[ax+1][bx]!=0||ax==(h-1))z=1;
		if(in[ax][bx+1]!=0||bx==(l-1))z=2;
		if(in[ax-1][bx]!=0||ax==0)z=3;
		if(in[ax][bx-1]!=0||bx==0)z=4;
		if(z==1)bx--;
		if(z==2)ax++;
		if(z==3)bx++;
		if(z==4)ax--; 
	}
	return 0;
}
