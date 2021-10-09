#include<bits/stdc++.h>
using namespace std;
int in,ji;
bool zhi(int in){
	if(in==2)return true;
	for(int i=2;i<in;i++){
		if(in%i==0)return false;
	}
	return true;
}
int main(){
	scanf("%d",&in);
	for(int i=2;;i++){
		if(zhi(i))ji++;
		if(ji==in){
			printf("%d",i);
			return 0;
		}
	}
}
