#include<bits/stdc++.h>
using namespace std;
int len,in[100005];
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	for(int z=0;z<len;z++){
		for(int i=1;i<len;i++){
			if(in[i-1]>in[i]){
				int lin=in[i];
				in[i]=in[i-1];
				in[i-1]=lin;
			}
		}
	}
	printf("%d ",in[0]);
	for(int i=1;i<len;i++){
		if(in[i]!=in[i-1]){
			printf("%d ",in[i]);
		}
	}
	return 0;
}
