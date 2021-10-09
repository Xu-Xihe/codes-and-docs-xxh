#include<stdio.h>
using namespace std; 
int a[100][100];
int b[100][100];
int m,n,ax,bx;//n=hang=ax;m=lie=bx;
int main(){
	scanf("%d%d",&n,&m);
	ax=0;
	while(true){
		bx=0;
		while(true){
			scanf("%d",&a[ax][bx]);
			bx++;
			if(bx==m)break;
		}
		ax++;
		if(ax==n)break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			scanf("%d",&b[ax][bx]);
			bx++;
			if(bx==m)break;
		}
		ax++;
		if(ax==n)break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			a[ax][bx]+=b[ax][bx];
			bx++;
			if(bx==m)break;
		}
		ax++;
		if(ax==n)break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			printf("%d",a[ax][bx]);
			bx++;
			if(bx==m){
				printf("\n");
				break;
			}
			else printf(" ");
		}
		ax++;
		if(ax==n)break;
	}
	return 0;
}
