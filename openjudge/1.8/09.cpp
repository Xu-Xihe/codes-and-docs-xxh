#include<stdio.h>
using namespace std;
int a[100][100];
int b[100][100];
int c[100][100];
int ax,bx,i,j,n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
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
			if(bx==k)break;
		}
		ax++;
		if(ax==m)break;
	}
	i=j=ax=bx=0;
	while(true){
		i=0;
		while(true){
			ax=0;
			while(true){
				c[i][j]+=a[i][ax]*b[ax][j];
				ax++;
				if(ax==m)break;
			}
			i++;
			if(i==n)break;
		}
		j++;
		if(j==k)break;
	} 
	ax=0;
	while(true){
		bx=0;
		while(true){
			printf("%d",c[ax][bx]);
			bx++;
			if(bx==k){
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
