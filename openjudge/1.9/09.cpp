#include<stdio.h>
using namespace std;
int len,in[10005],ji[10005],big;
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<len;i++){
		if(in[i]>big)
			big=in[i];
	}
	for(int i=0;i<len;i++){
		ji[in[i]]++;
	}
	for(int i=0;i<=big;i++){
		printf("%d\n",ji[i]);
	}
	return 0;
} 
