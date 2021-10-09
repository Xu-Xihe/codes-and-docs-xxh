#include<stdio.h>
using namespace std;
int a[100][100],n,out[100][100],m,ax=0,bx,z;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
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
	bx=0;
	while(true){
		out[0][bx]=a[0][bx];
		out[n-1][bx]=a[n-1][bx];
		bx++;
		if(bx==m)break;
	}
	ax=1;
	while(true){
		out[ax][0]=a[ax][0];
		out[ax][m-1]=a[ax][m-1];
		ax++;
		if(ax==n)break;
	}
	ax=1;
	while(true){
		bx=1;
		while(true){
			z=0;
			z=(a[ax-1][bx]+a[ax][bx-1]+a[ax][bx+1]+a[ax+1][bx]+a[ax][bx])/5;
			/*if(z%10<5)*/z-=z%10;
			//else z+=10-z%10;
			out[ax][bx]=z;
			bx++;
			if(bx==(m-1))break;
		}
		ax++;
		if(ax==(n-1))break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			printf("%d",out[ax][bx]);
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
