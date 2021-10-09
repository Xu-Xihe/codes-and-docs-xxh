#include<stdio.h>
using namespace std;
int len,in[105][105],ji[10000],big;
void shuru(int in[105][105]){
	for(int i=0;i<len;i++){
		for(int j=0;;j++){
			char lin;
			scanf("%d",&in[i][j]);
			scanf("%c",&lin);
			if(lin=='\n'){
				in[i][j+1]=-1;
				break;
			}
		}
	}
	return ;
}
int main(){
	scanf("%d",&len);
	shuru(in);
	for(int i=0;i<len;i++){
		for(int j=0;;j++){
			if(in[i][j]==-1)break;
			if(in[i][j]>big)
				big=in[i][j];
		}
	}
	printf("%d\n",big);
	int z=0;
	for(int i=0;i<len;i++){
		for(int j=0;;j++){
			if(in[i][j]==-1)break;
			if(in[i][j]==big){
				ji[z]=i+1;
				z++;
				break;
			}
		}
	}
	z--;
	for(int i=0;i<z;i++)
		printf("%d,",ji[i]);
	printf("%d",ji[z]);
}
