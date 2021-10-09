#include<stdio.h>
using namespace std;
int len,in[10005],big,small=1e6;
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<len;i++){
		if(in[i]<small)
			small=in[i];
		if(in[i]>big)
			big=in[i];
	}
	printf("%d",big-small);
	return 0;
}
