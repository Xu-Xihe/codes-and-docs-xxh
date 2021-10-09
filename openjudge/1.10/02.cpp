#include<bits/stdc++.h>
using namespace std;
int len,in[501],ji[501];
int main(){
	scanf("%d",&len);
	int ee=0;
	for(int i=0;i<len;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<len;i++){
		if((in[i]%2)==1){
			ji[ee]=in[i];
			ee++;
		}
	}
	for(int i=0;i<ee;i++){
		for(int j=1;j<ee;j++){
			if(ji[j-1]>ji[j]){
				int lin=ji[j];
				ji[j]=ji[j-1];
				ji[j-1]=lin;
			}
		}
	}
	for(int i=0;i<(ee-1);i++)
		printf("%d,",ji[i]);
	printf("%d",ji[ee-1]);
	return 0;
}
