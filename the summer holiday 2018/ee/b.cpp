#include<bits/stdc++.h>
using namespace std;
int in;
bool a=true;
int main(){
	scanf("%d",&in);
	if(in==2){
		printf("Yes");
		return 0;
	}
	for(int i=2;(long long)i*i<in;i++){
		if(in%i==0)a=false;
	}
	if(a)printf("Yes");
	else printf("No");
	return 0;
}
