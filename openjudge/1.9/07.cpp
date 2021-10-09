#include<stdio.h>
using namespace std;
int len,in[105],big;
long long z;
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<len;i++){
		if(in[i]>big)
			big=in[i];
	}
	for(int i=0;i<len;i++){
		if(in[i]!=big)z+=in[i];
	}
	printf("%lld",z);
	return 0;
} 
