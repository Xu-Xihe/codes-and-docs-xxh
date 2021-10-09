#include<bits/stdc++.h>
using namespace std;
int len,out[500][500],nx,ny;
int main(){
	scanf("%d",&len);
	len*=2;
	len--;
	out[0][len/2]=1;
	nx=0;
	ny=len/2;
	for(int i=2;i<=len*len;i++){
		if(nx==0&&ny!=len-1){
			nx=len-1;
			ny++;
		}
		else if(ny==len-1&&nx!=0){
			nx--;
			ny=0;
		}
		else if(out[nx-1][ny+1]!=0||(nx==0&&ny==len-1)){
			nx++;
		}
		else{
			nx--;
			ny++;
		}
		out[nx][ny]=i;
	}
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++)
			printf("%d ",out[i][j]);
		printf("\n");
	}
}
