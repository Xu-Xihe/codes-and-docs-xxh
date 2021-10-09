#include<stdio.h>
//#include<time.h>
using namespace std;
char a[105][105];
int bx,ax=0,n,m,z,b[105][105];
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	while(true){
		scanf("%s",a[ax]);
		ax++;
		if(ax==n)break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			if(a[ax][bx]=='*'){
				b[ax][bx]=99;
				bx++;
			}
			else{
				z=0;
				if(a[ax-1][bx]=='*')z++;
				if(a[ax+1][bx]=='*')z++;
				if(a[ax][bx-1]=='*')z++;
				if(a[ax][bx+1]=='*')z++;
				if(a[ax-1][bx-1]=='*')z++;
				if(a[ax-1][bx+1]=='*')z++;
				if(a[ax+1][bx+1]=='*')z++;
				if(a[ax+1][bx-1]=='*')z++;
				b[ax][bx]=z;
				bx++;
			}
			if(bx==m)break;
		}
		ax++;
		if(ax==n)break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			if(b[ax][bx]==99)printf("*");
			else printf("%d",b[ax][bx]);
			bx++;
			if(bx==m)printf("\n");
			if(bx==m)break;
		}
		ax++;
		if(ax==n)break;
	}
	//printf("%f",(double)clock()/CLOCKS_PER_SEC);
	return 0;
} 
