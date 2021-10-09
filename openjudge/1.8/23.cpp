#include<stdio.h>
using namespace std;
int in[105][105],ins[105][105],h,l,ax,bx,z=1;
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&h,&l);
	for(int i=0;i<h;i++)
		for(int j=0;j<l;j++)
		scanf("%d",&in[i][j]);
	for(int i=1;i<=(h*l);i++){
		printf("%d\n",in[ax][bx]);
		ins[ax][bx]=888;
		if(z==1)if((bx+1)==l||ins[ax][bx+1]==888)z=2;
		if(z==2)if((ax+1)==h||ins[ax+1][bx]==888)z=3;
		if(z==3)if(bx==0||ins[ax][bx-1]==888)z=4;
		if(z==4)if(ax==0||ins[ax-1][bx]==888)z=1;
		if(z==1)bx++;
		if(z==2)ax++;
		if(z==3)bx--;
		if(z==4)ax--;
	}
	return 0;
}
