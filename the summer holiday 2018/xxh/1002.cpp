#include<bits/stdc++.h>
using namespace std;
int len,ji[1000];
int main(){
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		scanf("%d",&ji[i]);
	}
	for(int i=len-1;i>0;i--){
		printf("%d ",ji[i]);
	}
	printf("%d",ji[0]);
	return 0;
}
