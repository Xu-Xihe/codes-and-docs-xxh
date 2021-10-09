#include<stdio.h>
using namespace std;
int n,z,b,h,ax,bx,a[1000][1000];
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
			if(a[ax][bx]==0&&a[ax][bx+1]==0&&(bx+1)<n){
				if(h==888)break;
				else h=888;
				ax++;
				bx=0;
			}
			if(a[ax][bx]==0){
				if(b==888)b=0;
				else b=888;
			}
			if(a[ax][bx]==255&&b==888&&h==888)z++;
			bx++;
			if(bx==n)break;
		}
		ax++;
		if(ax>=n)break;
	}
	printf("%d",z);
	return 0;
}
