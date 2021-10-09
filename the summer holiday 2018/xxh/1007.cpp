#include<bits/stdc++.h>
using namespace std;
long long in;
bool lin=true;
int main(){
	scanf("%lld",&in);
	for(int i=2;i<10;i++){
		if(in%i==0){
			lin=false;
			printf("%d ",i);
		}
	}
	if(lin)printf("none");
	return 0;
}
