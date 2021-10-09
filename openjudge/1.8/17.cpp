#include<stdio.h>
using namespace std;
int h,l,ax,bx,z;
char a[5000][102];
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d %d",&h,&l);
	while(true){
		bx=0;
		while(true){
			scanf("%c",&a[ax][bx]);
			if(a[ax][bx]=='\n')bx--;
			bx++;
			if(bx==l)break;
		}
		ax++;
		if(ax==h)break;
	}
	ax=0;
	while(true){
		bx=0;
		while(true){
			if(a[ax][bx]=='#'){
				if(a[ax+1][bx]=='#'){
					z++;
					a[ax+1][bx]='.';
				}
				else if(a[ax][bx+1]=='#'){
					z++;
					a[ax][bx+1]='.';
				}
				else z++;
			}
			bx++;
			if(bx==l)break;
		}
		ax++;
		if(ax==h)break;
	}
	printf("%d",z);
	return 0;
}
