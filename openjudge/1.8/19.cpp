#include<stdio.h>
using namespace std;
int n,z,b,ax,bx,a[105][105];
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	while(true){
		bx=0;
		while(true){
			scanf("%d",&a[ax][bx]);
			bx++;
			if(bx==n)break;
		}
		ax++;
		if(ax==n)break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			if(a[ax][bx]<=50)z++;
			bx++;
			if(bx==n)break;
		}
		ax++;
		if(ax==n)break;
	}
	printf("%d ",z);
	ax=0;
	z=0;
	while(true){
		bx=0;
		while(true){
			if(a[ax][bx]<=50){
				if((ax+1)==n||(ax-1)<0||(bx-1)<0||(bx+1)==n)z++;
				else if(a[ax+1][bx]>50||a[ax-1][bx]>50||a[ax][bx-1]>50||a[ax][bx+1]>50)z++;
			}
			bx++;
			if(bx==n)break;
		}
		ax++;
		if(ax==n)break;
	}
	printf("%d",z);
}
