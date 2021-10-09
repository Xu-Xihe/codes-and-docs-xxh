#include<stdio.h>
using namespace std;
int out[1000][10000],in,zong,nx,ny,y=1,snx=1,u;
int main(){
	scanf("%d",&in);
	zong=in*in;
	for(int i=0;i<in;i++){
		if((i%2)==0){
			nx=i;
			ny=0;
			for(int j=0;j<=i;j++){
				out[nx][ny]=y;
				y++;
				nx--;
				ny++;
			}
		}
		else{
			nx=0;
			ny=i;
			for(int j=0;j<=i;j++){
				out[nx][ny]=y;
				y++;
				nx++;
				ny--;
			}
		}
	}
	if((in%2)==0)u=1;
	else u=0;
	for(int i=(in-1);i>0;i--){
		if((u%2)==0){
			nx=snx;
			ny=in-1;
			snx++;
			for(int j=0;j<i;j++){
				out[nx][ny]=y;
				//printf("%d\n\n",u);
				y++;
				nx++;
				ny--;
			}
		}
		else{
			nx=in-1;
			ny=snx;
			snx++;
			for(int j=0;j<i;j++){
				out[nx][ny]=y;
				//printf("%d\n\n",u);
				y++;
				nx--;
				ny++;
			}
		}
		u++;
	}
	for(int i=0;i<in;i++){
		for(int j=0;j<in;j++)
		printf("%d ",out[i][j]);
		printf("\n");
	}
	return 0;
}

