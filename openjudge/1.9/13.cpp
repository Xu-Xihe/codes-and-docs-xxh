#include<stdio.h>
using namespace std;
int len,in[20005];
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<len;i++){
		int z=0;
		for(int j=i-1;j>=0;j--){
			if(in[j]==in[i]){
				z=88;
				break;
			}
		}
		if(z==0)printf("%d ",in[i]);
	}
	return 0;
}
