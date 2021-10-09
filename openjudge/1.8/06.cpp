#include<stdio.h>
using namespace std;
int m,n,a[100][100],b[100][100],ax=0,bx;
double z=0,zl=0;
int main(){
	scanf("%d%d",&m,&n);//m=hang=ax;n=lie=bx;
	while(true){
		bx=0;
		while(true){
			scanf("%d",&a[ax][bx]);
			bx++;
			if(bx==n)break;
		}
		ax++;
		if(ax==m)break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			scanf("%d",&b[ax][bx]);
			bx++;
			if(bx==n)break;
		}
		ax++;
		if(ax==m)break;
	}
	ax=bx=0;
	while(true){
		bx=0;
		while(true){
			if(a[ax][bx]==b[ax][bx])z++;
			bx++;
			if(bx==n)break;
		}
		ax++;
		if(ax==m)break;
	}
	zl=n*m;
	printf("%.2f",z/zl*100);
} 
