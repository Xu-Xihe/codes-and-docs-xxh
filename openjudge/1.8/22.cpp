#include<stdio.h>
using namespace std;
int in,ins,inx,inb,out[1000][1000],nx,ny;
void is(int ins,int inb){
	for(int i=2;i<=ins;i++){
		if(nx==0&&ny==inb)nx++;
			else if(nx==0){
					nx=inb;
					ny++;
			}
				else if(ny==inb){
					nx--;
					ny=0;
				}
					else if(out[nx-1][ny+1]!=0)nx++;
						else{
							nx--;
							ny++;
						}
		out[nx][ny]=i;
		//printf("i=%d,nx=%d,ny=%d\n\n\n",i,nx+1,ny+1);
	}
} 
int main(){
	//freopen("out.txt","w",stdout);
	scanf("%d",&in);
	ins=(2*in-1)*(2*in-1);
	inx=2*in-1;
	ny=inx/2;
	out[0][ny]=1;
	inb=inx-1;
	is(ins,inb);
	for(int i=0;i<inx;i++){ 
		for(int j=0;j<inx;j++)
			printf("%d ",out[i][j]);
		printf("\n");
	}
	return 0;
}

