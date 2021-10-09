#include<bits/stdc++.h>
using namespace std;
int peo,guan,in[10050],ji[105],out;
int small(int in[105],int len){
	int xiao=1e9;
	for(int zl=0;zl<len;zl++){
		if(in[zl]<xiao)
			xiao=in[zl];
	}
	return xiao;
}
int big(int in[105],int len){
	int xiao=0;
	for(int zl=0;zl<len;zl++){
		if(in[zl]>xiao)
			xiao=in[zl];
	}
	return xiao;
}
int main(){
	scanf("%d%d",&peo,&guan);
	for(int i=0;i<peo;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<guan;i++){
		ji[i]=in[i];
	}
	for(int i=guan;i<peo;){
		int lin=small(ji,guan);
		out+=lin;
		for(int j=0;j<guan;j++){
			ji[j]-=lin;
			if(ji[j]==0){
				ji[j]=in[i];
				i++;
			}
		}
	}
	out+=big(ji,guan);
	printf("%d",out);
	return 0;
}
