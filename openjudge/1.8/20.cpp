#include<stdio.h>
#include<string.h>
using namespace std;
char a[206],b[200][200];
int n,ax,bx,j,z;
int main(){
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%s",&n,a);
	z=strlen(a)/n;
	while(true){
		if(ax%2!=0)bx=n-1;
		else bx=0;
		while(true){
			b[ax][bx]=a[j];
			j++;
			if(ax%2!=0)bx--;
			else bx++;
			if(ax%2!=0&&bx<0)break;
			else if(bx==n)break;
		}
		ax++;
		if(ax==z)break;
	}
	bx=ax=0;
	while(true){
		bx=0;
		while(true){
			printf("%c",b[bx][ax]);
			bx++;
			if(bx==z)break;
		}
		ax++;
		if(ax==n)break;
	}
	return 0;
}
